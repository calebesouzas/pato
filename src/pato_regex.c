// #include <stdio.h>
#include <stdio.h>
#include <stdlib.h>



/* Function 'pato_regex_parse'
 * Param _str is the string to be parsed, the input
 * */
const char * pato_regex_parse(const char * _input) {
    char * str = (char *)malloc(sizeof(_input) + 1); // +1 for NULL in case of failure
    if (sizeof(_input) != 0 && str != NULL) {
	for (unsigned int i = 0; i < sizeof(str); i++) {
	    printf("Character is at %c", (char)_input[i]);
	}
    }
    return "";
}
