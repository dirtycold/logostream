# @(#) HTML documentation
# $Revision: 1.2 $

.PHONY: all install clean 

BASE= logostream
WEBDIR= $$HOME/www/doc/${BASE}
INSTALL= install -m 644

all:
	@echo "What?"

install:
	@ls *.html *.png *.css *.gif | while read FILE; \
	do\
		${ECHO} "${INSTALL} $$FILE ${WEBDIR}" ;\
		${INSTALL} $$FILE ${WEBDIR} ;\
	done;

clean clear:
	rm -rfv *.html class*.png struct*.png *.gif tabs.css
