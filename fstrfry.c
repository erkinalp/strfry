/*
  fstrfry(8) - a stdio randomiser using strfry(3)
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
#define  _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc,char *argv[]) {
    int fryend;
    size_t len;
    struct stat stat_buf={0};
    if (argc==1) {
    fprintf(stderr,"fstrfry requires a filename\n");
    fprintf(stderr,"to anagram stdin into stdout, use strfry\n");
    return 1;
    }
    if (argc>1) fryend=open(argv[1], O_APPEND|O_CREAT, 00777);
    mainloop:;
    char *buf=mmap(0,(len=fstat(fryend,&stat_buf),stat_buf.st_size), PROT_WRITE | PROT_READ, MAP_SHARED, fryend, 0);
    buf[len]=0;
    for (char *ptr=buf;ptr<buf+len-1;buf+=strlen(buf)) {
    strfry(ptr);
    }
    msync(buf,len,MS_SYNC);
    munmap(buf,len);
    close(fryend);
    return 0;
}
