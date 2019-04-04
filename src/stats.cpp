#include "stats.h"
#include <vector>

Stats::Stats() {}

std::vector<std::size_t> Stats::countAllDirToDoubleMark(Array<Directories, Files> &array)
{
	std::vector<std::size_t> toMark;
	std::size_t noRepeat = 0;
	for (std::size_t i = 0; i < array.getNDirs(); ++i) {
		if (array.getDirs()[i].space != 0) {
			if (i > 0 && i < array.getNDirs() - 2) {
				if (array.getDirs()[i].space > array.getDirs()[i - 1].space) {
					if (array.getDirs()[i - 1].space == array.getDirs()[i + 1].space) {
						if (i != noRepeat) {
							toMark.push_back(i);
							noRepeat = i;
						}
					} else if (array.getDirs()[i].space == array.getDirs()[i + 1].space) {
						// boucle jusqu a combien i + n
						if (array.getDirs()[i - 1].space == array.getDirs()[i + 2].space) {
							if (i != noRepeat) {
								toMark.push_back(i);
								toMark.push_back(i + 1);
								noRepeat = i;
							}
						}
					}
				}
			}
		}
	}
	return toMark;
}

const char *Stats::showWD()
{
    if (getenv("HOME")) {
        return getpwuid(getuid())->pw_dir;
    }
    return nullptr;
}

std::string Stats::folderRearrange(Array<Directories, Files> &array, std::size_t i)
{
	std::string folder;
	if (i > 0) {
     	folder = array.getDirs()[i].name;			// current directory
		std::size_t posLastSlash = folder.find_last_of("/");
        if (posLastSlash != std::string::npos) {
        	folder.erase(0, posLastSlash + 1);
	    }
	} else {
        folder = array.getDirs()[i].name;
        std::size_t rootFolderPos = folder.find_last_of("/");
        if (rootFolderPos != std::string::npos) {
            folder.erase(0, rootFolderPos);
        }
    }
	return folder;
}
