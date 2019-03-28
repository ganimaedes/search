# Search
Program to find files by name, extension and/or find a string within the files found.

## Install 
## On Linux
```
git clone https://github.com/ganimaedes/search.git
cd src
./configure
make
make install
```

## How To Use

Type:

`search` Followed by These Options:
```
	-n : 		 Specify a File Name to Search

	-e : 		 Specify a File Extension

	-s : 		 Specify a String to Search in a File, 

       			 Note : The File Name Or File Extension Must be Specified!

	-p : 		 Print All Files and Folders Inside a Directory

	-d : 		 Specify a Directory to Search Into
```

## Examples:
```
./search -e "txt" -s "cmake" -d "$HOME/Documents"
  ^       ^        ^          ^
  ¦       ¦        ¦          ¦-----> Search Within this Directory
  ¦       ¦        ¦-----> Search the String "cmake" in All the Files Found With Extension ".txt"
  ¦       ¦-----> Search for extension ".txt"
  ¦---> Name of Program

./search -n "CMake" -d "$HOME/Documents"
  ^       ^          ^
  ¦       ¦          ¦-----> Search Within this Directory
  ¦       ¦-----> Search for This String in File Name
  ¦---> Name of Program

=======
```

