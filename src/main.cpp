/* Copyright <2019> <ganimaedes>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
 * associated documentation files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, 
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all copies or substantial 
 * portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT 
 * NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES 
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "parcours.h"
#include "print.h"

void printHelp()
{
    std::cout << "-------Help For Search Script-------\n\n"
              << "To Execute Program, Type: \n" 
              << "search Followed by These Options:\n\n"
              << "\t-n, --name      : \t\t Specify a File Name to Search\n\n"
              << "\t-e, --extension : \t\t Specify a File Extension\n\n"
              << "\t-s, --string    : \t\t Specify a String to Search in a File, \n\n"
              << "      \t\t\t Note : The File Name Or File Extension Must be Specified!\n\n"
              << "\t-p, --print     : \t\t Print All Files and Folders Inside a Directory\n\n"
              << "\t-d, --directory : \t\t Specify a Directory to Search Into\n\n"
              << "\t-h, --help      : \t\t Print This Help Screen\n\n";
    std::cout << "Examples:\n"
              << "search -e \"txt\" -s \"cmake\" -d \"$HOME/Documents\"\n"
              << "^       ^          ^            ^\n"
              << "¦       ¦          ¦            ¦-----> Search Within this Directory\n"
              << "¦       ¦          ¦-----> Search the String \"cmake\" in All the Files Found With Extension \".txt\"\n"
              << "¦       ¦-----> Search for extension \".txt\"\n"
              << "¦---> Name of Program\n\n";
    std::cout << "search -n \"CMake\" -d \"$HOME/Documents\"\n"
              << "^       ^            ^\n"
              << "¦       ¦            ¦-----> Search Within this Directory\n"
              << "¦       ¦-----> Search for This String in File Name\n"
              << "¦---> Name of Program\n";
}

void printVersion()
{
    std::cout << "Search v.0.0.1\n"
              << "License: MIT\n"
              << "This is free software: you are free to change and redistribute it.\n"
              << "There is NO WARRANTY, to the extent permitted by law.\n"
              << "Written by github.com/ganimaedes\n";
}

int main(int argc, char *argv[])
{    
    std::string fileName, fileExtension, directory, strInFile, printAll;

    bool printAllFoldersAndFiles = false;
    for (int i = 0; i < argc; ++i) {
        if (!strcmp(argv[i], "-n") || !strcmp(argv[i], "--name")) {                             	// -n fileName
            if (i < argc - 1) {
                fileName = argv[i + 1];
            } else {
                std::cerr << "Missing argument for file name\n";
                exit(-1);
            }
        } else if (!strcmp(argv[i], "-e") || !strcmp(argv[i], "--extension")) {                   	// -e fileExtension
            if (i < argc - 1) {
                fileExtension = argv[i + 1];
            } else {
                std::cerr << "Missing argument for file extension\n";
                exit(-1);
            }
        } else if (!strcmp(argv[i], "-s") || !strcmp(argv[i], "--string")) {                       	// -s string to search in found file
            if (i < argc - 1) {
                strInFile = argv[i + 1];
            } else {
                std::cerr << "Missing argument for string to search in file\n";
                exit(-1);
            }
    } else if (!strcmp(argv[i], "-p") || !strcmp(argv[i], "--print")) {			                // -p print all files and folders in directory
            if (i < argc - 1) {
                directory = argv[i + 1];
                printAllFoldersAndFiles = true;
            } else {
                std::cerr << "Missing argument for printing all files and folders\n";
                exit(-1);
            }
        } else if (!strcmp(argv[i], "-d") || !strcmp(argv[i], "--directory")) {                  	// -d directory to search in
            if (i < argc - 1) {
                directory = argv[i + 1];
            } else {
                std::cerr << "Missing argument for directory to search\n";
                exit(-1);
            }
        } else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {				// -h print help
            printHelp();
            exit(0);
        } else if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version")) {				// -v print version
            printVersion();
            exit(0);
        }  
        if (i == argc - 1) {
            if (directory.empty()) {
                if (strlen(argv[1]) != 0) {
                    directory = argv[1];
                } else if (strlen(argv[1]) == 0) {
                    //directory = showWD();
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
    	
    Array<Directories, Files> array;
    Parcours par;
    if (!directory.empty() && fileName.empty() && fileExtension.empty() && strInFile.empty()) {
        par.recursiveParcours(const_cast<char *>(directory.c_str()), 0, array, "", ""); 
        Print p(array, printAllFoldersAndFiles);
    } else if (!directory.empty() && !fileName.empty() && fileExtension.empty() && strInFile.empty()) {
        par.recursiveParcours(const_cast<char *>(directory.c_str()), 0, array, "", fileName.c_str(), "", "");
    } else if (!directory.empty() && fileName.empty() && !fileExtension.empty() && strInFile.empty()){
        par.recursiveParcours(const_cast<char *>(directory.c_str()), 0, array, "", "", fileExtension.c_str(), ""); 
    } else if (!directory.empty() && !fileName.empty() && !fileExtension.empty() && strInFile.empty()) {
        par.recursiveParcours(const_cast<char *>(directory.c_str()), 0, array, "", fileName.c_str(), fileExtension.c_str(), ""); 
    } else if (!directory.empty() && !fileName.empty() && fileExtension.empty() && !strInFile.empty()) {
        par.recursiveParcours(const_cast<char *>(directory.c_str()), 0, array, "", fileName.c_str(), "", strInFile.c_str()); 
    } else if (!directory.empty() && fileName.empty() && !fileExtension.empty() && !strInFile.empty()) {
        par.recursiveParcours(const_cast<char *>(directory.c_str()), 0, array, "", "", fileExtension.c_str(), strInFile.c_str()); 
    } else {
        std::cerr << "Error: missing arguments\n";
    }
    return 0;
}
