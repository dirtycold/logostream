# @(#) Make documentation
# $Revision: 1.2 $

.PHONY: all install clean clear

DOXYGEN= /usr/local/bin/doxygen

all:
	${DOXYGEN}

install-doc:
	make -C html install

clean clear:
	make -C html clean
