# Project Title

<<<<<<< HEAD:readme.md
Program to find files by name, extension and/or find a string within the files found.
Table of Contents

# Install 
```./configure
make
make install
```

# How To Use
```Type:
search Followed by These Options:

	-n : 		 Specify a File Name to Search

	-e : 		 Specify a File Extension

	-s : 		 Specify a String to Search in a File, 

       			 Note : The File Name Or File Extension Must be Specified!

	-p : 		 Print All Files and Folders Inside a Directory

	-d : 		 Specify a Directory to Search Into
```

# Examples:
```./search -e "txt" -s "cmake" -d "$HOME/Documents"
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
Give examples
>>>>>>> 066173ffd85cc19d7ce80dd27a1264d105b26f4a:readme.txt
```

