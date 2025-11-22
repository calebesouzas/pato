#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function 'is_match'
 * 
 * */
int is_match(const char *_input, const char *_pattern) {
    char input[8192] = {0};
    char pattern[256] = {0};
    /* First we get 'input' and 'pattern' strings length
     * If they don't exceed the limit*/
    int input_size = 0;
    while (input_size < strlen(_input)) {
	input_size++;
    }
    int pattern_size = 0;
    while (pattern_size < strlen(_pattern)) {
	pattern_size++;
    }
    if (input_size <= 8192 && pattern_size <= 256) {
	strcat(input, _input);
	strcat(pattern, _pattern);
    }
    else {
	perror("Input or pattern length exceded");
	exit(1);
    }
    return 0;
}
