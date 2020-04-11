/*
  strfry(1) - a stdio randomiser using strfry(3)
    Copyright (C) 2014  Erkin Alp Güney
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation, either version 3
    of the License, or (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <string.h>

void secure_clear(void * data, size_t size) {
    char *_data = (char*)data;
    char tmp = _data[size];
    _data[size] = 0;
    strfry(_data);
    _data[size] = tmp;
    return;
}
