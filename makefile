# @(#) Make log stream
# @(#) Author Andrew Wingorodov <http://andr.ru/>
# $Revision: 1.2 $

.PHONY: all doc install clean clear test

CXXFLAGS+= -I.\
		-I/usr/local/include\
		-L/usr/local/lib

LDLIBS+= -lthr -lboost_thread liblogs.a

all: liblogs.a example

liblogs.a: ostream.o
	ar rv $@ $?
	ranlib $@

doc:
	@make -C doc

clean clear:
	rm -rfv example *.a *.o *.core
	@make -C doc clean
