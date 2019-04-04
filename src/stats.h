#ifndef STATS_H
#define STATS_H

#include <unistd.h>
#include <pwd.h>

#include "array.h"
#include "parcours.h"

#include <string.h>

class Stats
{		
public:
	Stats();
	const char *showWD();
	std::vector<std::size_t> countAllDirToDoubleMark(Array<Directories, Files> &array);
	std::string folderRearrange(Array<Directories, Files> &array, std::size_t i);
};

#endif	// STATS_H
