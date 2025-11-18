#include <stdio.h>
// #include <string.h>
#include "parser.h"
#include "usage_guides.h"

void get_round_project_config(round_file_T project_file) {
    project_file.name = ".roundp";
    project_file.pointer = fopen(project_file.name, "r");
    char buffer[1024] = {0};
    if (project_file.pointer != NULL) {
        round_parse(buffer, sizeof(buffer), project_file);
    }
}


int main(int argc, char *argv[]) {
    char version[] = "0.0.1-dev";
    FILE *p_round_file = fopen(argv[1], "r");

    char buffer[1024] = {0};
    /* Here we check if the first argument for the program
     * is a file, else we'll check if it's a command. */
    if (p_round_file == NULL) {
	if (argc == 1) {
	    printf("Round Lang\tversion %s\n", version);
	    return 0;
	} else {
	    /* Handling commands. Those are:
	    * help
	    * run
	    * build
	    * new
	    * compile
	    * */
	    switch (argv[1][0]) {
		case 'h': 
		    print_usage_guide();
		    break;
		case 'r':
		    break;

		default:
		    printf("The command '%s' is not a valid command\n", argv[1]);
	    }
	    return 0;
	}
	// else:
	printf("Could not open file%s\n", argv[1]);
	return 0;
    }

    while (fgets(buffer, sizeof(buffer), p_round_file) != NULL) {
	printf("%s", buffer);
    }
    fclose(p_round_file);
    return 0;
}
