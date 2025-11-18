#ifndef PARSER_H
#define PARSER_H
#include <stdio.h>
typedef struct {
    FILE * pointer;
    char * name;
} round_file_T;

void round_parse(const char * buffer, int buffer_size, round_file_T file_to_parse);

#endif
