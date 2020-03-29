#include <string.h>

void secure_clear(void * data, size_t size) {
    char *_data = (char*)data;
    char tmp = _data[size];
    _data[size] = 0;
    strfry(_data);
    _data[size] = tmp;
    return;
}
