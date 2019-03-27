#include <unistd.h>
#include <pwd.h>

//#include "array.h"
#include "parcours.h"
#include "print.h"

#include <vector>

const char *showWD()
{
    if (getenv("HOME")) {
        return getpwuid(getuid())->pw_dir;
    }
    return "";
}

void printHelp()
{
    std::cout << "-------Help For Search Script-------\n\n"
              << "To Execute Program, Type: \n" 
              << "./search Followed by These Options:\n\n"
              << "-n : \t\t\t\t Specify a File Name to Search\n\n"
              << "-e : \t\t\t\t Specify a File Extension\n\n"
              << "-s : \t\t\t\t Specify a String to Search in a File, \n\n"
              << "     \t\t\t\t Note : The File Name Or File Extension Must be Specified!\n\n"
              << "-p : \t\t\t\t Print All Files and Folders Inside a Directory\n\n"
              << "-d : \t\t\t\t Specify a Directory to Search Into\n\n";
    std::cout << "Examples:\n"
              << "./search -e \"txt\" -s \"cmake\" -d \"$HOME/Documents\"\n"
              << "  ^       ^          ^            ^\n"
              << "  ¦       ¦          ¦            ¦-----> Search Within this Directory\n"
              << "  ¦       ¦          ¦-----> Search the String \"cmake\" in All the Files Found With Extension \".txt\"\n"
              << "  ¦       ¦-----> Search for extension \".txt\"\n"
              << "  ¦---> Name of Program\n\n";
    std::cout << "./search -n \"CMake\" -d \"$HOME/Documents\"\n"
              << "  ^       ^            ^\n"
              << "  ¦       ¦            ¦-----> Search Within this Directory\n"
              << "  ¦       ¦-----> Search for This String in File Name\n"
              << "  ¦---> Name of Program\n";
}

int main(int argc, char *argv[])
{    
    std::string fileName, fileExtension, directory, strInFile, printAll;
    fileName.clear(); fileExtension.clear(); directory.clear(); strInFile.clear(), printAll.clear();
    //./main2 -e "txt" -s "cmake" -d "$HOME/qwtq",./main2 -n "CMake" -d "$HOME/qwtq"
    // verifier si pour -e ".txt" est mis et l'enlever
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-n") == 0) {                                           	        // -n fileName
            if (i < argc - 1) {
                fileName = argv[i + 1];
            } else {
                std::cerr << "Missing argument for file name\n";
                exit(-1);
            }
        } else if (strcmp(argv[i], "-e") == 0) {                                    	        // -e fileExtension
            if (i < argc - 1) {
                fileExtension = argv[i + 1];
            } else {
                std::cerr << "Missing argument for file extension\n";
                exit(-1);
            }
        } else if (strcmp(argv[i], "-s") == 0) {                                    	        // -s string to search in found file
            if (i < argc - 1) {
                strInFile = argv[i + 1];
            } else {
                std::cerr << "Missing argument for string to search in file\n";
                exit(-1);
            }
        } else if (strcmp(argv[i], "-p") == 0) {					        // -p print all files and folders in directory
        	if (i < argc - 1) {
                    printAll = argv[i + 1];
        	} else {
                    std::cerr << "Missing argument for printing all files and folders\n";
                    exit(-1);
        	}
        } else if (strcmp(argv[i], "-d") == 0) {                                    	        // -d directory to search in
            if (i < argc - 1) {
                directory = argv[i + 1];
            } else {
                std::cerr << "Missing argument for directory to search\n";
                exit(-1);
            }
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-help") == 0 ) {		// -h print help
        	printHelp();
        }  
        if (i == argc - 1) {
            if (directory.empty()) {
                if (strlen(argv[1]) != 0) {
                    directory = argv[1];
                } else if (strlen(argv[1]) == 0) {
                    directory = showWD();
                } else {
                    std::cerr << "Error: A directory must be specified with \"-d\"\n";
                    exit(-1);
                }
            }
            if (!strInFile.empty() && fileName.empty() && fileExtension.empty()) {
                std::cerr << "Please specify a file name to search with \"-n\"" 
                          << " OR a file extension with \"-e\"\n";
                exit(-1);
            }
        } 
    }
    std::cout << "fileName.length() = " << fileName.length() << "  fileExtension.length() = " << fileExtension.length()
              << "\ndirectory.length() = " << directory.length() << "  strInFile.length() = " << strInFile.length() << "\n";
	
	
    std::vector<Directories> array;
    std::string prevDir;
    if (!directory.empty() && fileName.empty() && fileExtension.empty() && strInFile.empty()) {
        std::cout << "1\n";
        Parcours(const_cast<char *>(directory.c_str()), 0, array, "", ""); 
        Print p(array);
    } else if (!directory.empty() && !fileName.empty() && fileExtension.empty() && strInFile.empty()) {
        std::cout << "2\n";
        Parcours(const_cast<char *>(directory.c_str()), 0, array, "", fileName.c_str(), "", "");
    } else if (!directory.empty() && fileName.empty() && !fileExtension.empty() && strInFile.empty()){
        std::cout << "3\n";
        Parcours(const_cast<char *>(directory.c_str()), 0, array, "", "", fileExtension.c_str(), ""); 
    } else if (!directory.empty() && !fileName.empty() && !fileExtension.empty() && strInFile.empty()) {
        std::cout << "4\n";
        Parcours(const_cast<char *>(directory.c_str()), 0, array, "", fileName.c_str(), fileExtension.c_str(), ""); 
    } else if (!directory.empty() && !fileName.empty() && fileExtension.empty() && !strInFile.empty()) {
        std::cout << "5\n";
        Parcours(const_cast<char *>(directory.c_str()), 0, array, "", fileName.c_str(), "", strInFile.c_str()); 
    } else if (!directory.empty() && fileName.empty() && !fileExtension.empty() && !strInFile.empty()) {
        std::cout << "6\n";
        Parcours(const_cast<char *>(directory.c_str()), 0, array, "", "", fileExtension.c_str(), strInFile.c_str()); 
    } else {
        std::cerr << "Error: missing arguments\n";
    }
    return 0;
}
