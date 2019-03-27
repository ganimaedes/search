#include "parcours.h"

#include <cstdlib>

Parcours::Parcours(char *fn, 
				   int indent, 
				   std::vector<Directories> &array, 
				   std::string prevDir,
				   std::string findFile, 
				   std::string findExtension, 
				   std::string strSearchInFile) 
    : m_fn(fn), 
      m_indent(indent), 
      m_array(array),
      m_prevDir(prevDir),
      m_findFile(findFile), 
      m_findExtension(findExtension), 
      m_strSearchInFile(strSearchInFile)
{
    DIR *dir;
    Directories direct = {};
    direct.files.clear();
    Files files = {};

    if (m_array.size() == 0) {
		direct.name = fn;
		direct.indent = indent;
		m_array.push_back(direct);
	}

    if ((dir = opendir(m_fn)) == nullptr) {
        std::cerr << "opendir() error\n";
    } else {
        while ((m_entry = readdir(dir)) != nullptr) {
            if (m_entry->d_name[0] != '.') {
                m_path = m_fn;
                m_path += "/";
                m_path += m_entry->d_name;
                if (stat(m_path.c_str(), &m_info) != 0) {
                    std::cerr << "Error: " << m_path << " " << errno << "\n";
                } else if (m_entry->d_type == DT_REG) { // m_entry->d_type != DT_DIR && 
                    if (!m_findExtension.empty() && matchExtension(m_entry->d_name, m_findExtension.c_str())) {
                        m_foundExt = true;
                    }
                    std::string name_entry = m_entry->d_name;
                    if (!m_findFile.empty() && name_entry.find(m_findFile) != std::string::npos) { 
                    // si on veut str exact : m_findFile.compare(m_entry->d_name) == 0
                        m_foundFileName = true;
                    }
                    
                    if (!m_strSearchInFile.empty() && (m_foundExt || m_foundFileName)) {
                        std::string name = m_path;
                        Search search(m_strSearchInFile, name);
                        searchFile(search);
                    }
                    
                    files.name = m_entry->d_name;
                    files.indent = m_indent;
                    files.ofDir = m_fn;
                    ++files.nFiles;
                    direct.files.push_back(files); 
					
                    m_foundExt = false;
                    m_foundFileName = false;
                } else if (S_ISDIR(m_info.st_mode)) {
                	direct.name = m_path;
					direct.indent = m_indent;
					m_array.push_back(direct);
                
                    if (!m_findExtension.empty() || !m_strSearchInFile.empty()) {
                        Parcours(const_cast<char *>(m_path.c_str()), m_indent + 1, m_array, m_prevDir, "", m_findExtension, m_strSearchInFile);
                    } else if (!m_findFile.empty()) {
                        Parcours(const_cast<char *>(m_path.c_str()), m_indent + 1, m_array, m_prevDir, m_findFile, "", m_strSearchInFile);
                    }
                    Parcours(const_cast<char *>(m_path.c_str()), m_indent + 1, m_array, m_prevDir);
                }
            }
        }
        (void)closedir(dir);
    }
}

bool Parcours::matchExtension(char *name, const char *ext)
{
    std::size_t namelen = strlen(name), extlen = strlen(ext);
    return namelen >= extlen && !strcmp(name + namelen - extlen, ext);
}

void Parcours::searchFile(Search &search)
{
    if (!search.getLinesFound().empty()) {
        if (!m_findExtension.empty() || !m_findFile.empty()) {
            std::cout << m_path << "\n";
        }
        std::size_t len = m_path.length() - strlen(m_entry->d_name);
        for (std::size_t i = 0; i < search.getLinesFound().size(); ++i) {
            for (std::size_t j = 0; j < len; ++j) { std::cout << " "; }
            std::cout << red << "l. " << search.getLinesFound()[i] << "\033[m "  
                        << m_strSearchInFile << "\n"; 
        }
    } else if (!search.getFileName().empty()) {
        std::cout << "String not found in " << search.getFileName() << "\n";
    }   
}

void Parcours::printAll(std::vector<Directories> &array)
{
	std::string prevDir;
	
	for (std::size_t i = 0; i < array.size(); ++i) {
		for (std::size_t j = 0; j < array[i].files.size(); ++j) {
			if (j == 0) {
				if (i > 0) {
					prevDir = array[i - 1].name;
				}
				for (int k = 0; k < array[i].indent + 1; ++k) { std::cout << "  "; }
				std::cout << array[i].name << "\n";
			}
			if (array[i].name == array[i].files[j].ofDir) {
				for (int n = 0; n < array[i].files[j].indent + 2; ++n) { 
					std::cout << (n == array[i].files[j].indent + 1 ? "|-" : "  "); 
				}
				std::cout << array[i].files[j].name << "\n";
			}	
		}
	}
}
