# This file is part of strfry
all: strfry fstrfry
strfry:
	gcc strfry.c $(CFLAGS) -o /tmp/strfry
fstrfry:
	gcc fstrfry.c $(CFLAGS) -std=c11 -o /tmp/fstrfry
clean:
	rm -rf /tmp/stfry
	rm strfry.o
install:
	mv /tmp/strfry $(PREFIX)/bin/strfry
	mv /tmp/fstrfry $(PREFIX)/bin/fstrfry
