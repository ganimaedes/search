#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T, typename S>
class Array
{
	T *m_dirs;
	std::size_t m_nDirs;
	std::size_t m_capDirs;
	
	S *m_files;
	std::size_t m_nFiles;
	std::size_t m_capFiles;
public:
	Array();
	~Array();
	void doubleCapDirs();
	void addDir(T *dir);
	T *getDirs();
	std::size_t getNDirs();
	//friend std::ostream &operator<<(std::ostream &out, const T &dir);
	
	void doubleCapFiles();
	void addFile(S *file);
	S *getFiles();
	std::size_t getNFiles();
};

template <typename T, typename S>
Array<T, S>::Array() : m_dirs(nullptr), m_nDirs(0), m_capDirs(0),
					   m_files(nullptr), m_nFiles(0), m_capFiles(0) {}

template <typename T, typename S>
Array<T, S>::~Array()
{
	delete[] m_dirs;
	delete[] m_files;
}

template <typename T, typename S>
void Array<T, S>::doubleCapDirs()
{
	m_capDirs *= 2;
	if (m_capDirs == 0) {
		m_capDirs = 1;
	}
	T *dirsCopy = m_dirs;
	m_dirs = new T [m_capDirs];
	for (std::size_t i = 0; i < m_nDirs; ++i) {
		m_dirs[i] = dirsCopy[i];
	}
	delete[] dirsCopy;
}

template <typename T, typename S>
void Array<T, S>::addDir(T *dir)
{
	if (m_nDirs == m_capDirs) {
		doubleCapDirs();
	}
	m_dirs[m_nDirs++] = *dir;
}

template <typename T, typename S>
T *Array<T, S>::getDirs() { return m_dirs; }

template <typename T, typename S>
std::size_t Array<T, S>::getNDirs() { return m_nDirs; }

template <typename T, typename S>
void Array<T, S>::doubleCapFiles()
{
	m_capFiles *= 2;
	if (m_capFiles == 0) {
		m_capFiles = 1;
	}
	S *filesCopy = m_files;
	m_files = new S [m_capFiles];
	for (std::size_t i = 0; i < m_nFiles; ++i) {
		m_files[i] = filesCopy[i];
	}
	delete[] filesCopy;
}

template <typename T, typename S>
void Array<T, S>::addFile(S *file)
{
	if (m_nFiles == m_capFiles) {
		doubleCapFiles();
	}
	m_files[m_nFiles++] = *file;
}

template <typename T, typename S>
S *Array<T, S>::getFiles() { return m_files; }

template <typename T, typename S>
std::size_t Array<T, S>::getNFiles() { return m_nFiles; }


#endif	// ARRAY_H
