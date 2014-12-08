/*
  strfry(1) - a stdio randomiser using strfry(3)
    Copyright (C) 2014  Erkin Alp Güney

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc,char *argv[]) {
    FILE *fryend=stdin;
    if (argc==1) goto mainloop;
    if (argc>1) fryend=fopen(argv[1],"r") ? fryend : stdin;

    mainloop:;
    char *buf=malloc(4096);
    while (fgets(buf,4095,fryend)) { //linefeed is intentionally left in the string
        strfry(buf);  // this way, randomisation increases
        fputs(buf,stdout);
    }
    
    free(buf);
    if (fryend!=stdin) fclose(fryend);
    return 0;
}
