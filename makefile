# This file is part of strfry
strfry:
	gcc strfry.c -o /tmp/strfry
clean:
	rm -rf /tmp/stfry
	rm strfry.o
install:
	mv /tmp/strfry $(PREFIX)/bin/strfry
