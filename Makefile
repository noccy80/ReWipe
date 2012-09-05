
all: Makefile
	echo Making all in src
	cd src; $(MAKE) $(MFLAGS)
	printf "$(HDR_UTIL) %s -> %s\n" MV src/wiped-bin .
	mv src/wiped-bin .

.SILENT:

include Makefile.gcc
