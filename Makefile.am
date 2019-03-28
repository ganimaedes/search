AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4
CXXFLAGS_ALL = -std=c++11
#CXXFLAGS = -std=c++11
AM_CXXFLAGS = -std=gnu++11 -fpic -Wall -Wextra \
$(glibcxx_lt_pic_flag) $(glibcxx_compiler_shared_flag) \
	$(XTEMPLATE_FLAGS) \
	$(WARN_CXXFLAGS) $(OPTIMIZE_CXXFLAGS) $(CONFIG_CXXFLAGS)
AM_MAKEFLAGS = \
	"gxx_include_dir=$(gxx_include_dir)"
SUBDIRS = src 
