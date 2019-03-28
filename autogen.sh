#!/bin/sh

libtoolize && aclocal && autoconf && autoheader && automake --add-missing && autoreconf -i
