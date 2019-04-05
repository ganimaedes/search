AUTOMAKE_OPTIONS = subdir-objects
AM_CXXFLAGS = -std=gnu++11 -fpic -Wall -Wextra \
$(glibcxx_lt_pic_flag) $(glibcxx_compiler_shared_flag) \
	$(XTEMPLATE_FLAGS) \
	$(WARN_CXXFLAGS) $(OPTIMIZE_CXXFLAGS) $(CONFIG_CXXFLAGS)
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)
bin_PROGRAMS = search
search_SOURCES = main.cpp 
search_LDADD = libSearch.la

lib_LTLIBRARIES = libSearch.la
libSearch_la_LDFLAGS = -version-info 0:0:0
libSearch_la_SOURCES = search.cpp parcours.cpp stats.cpp \
	print.cpp search.h parcours.h stats.h print.h
