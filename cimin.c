#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char* reduce(char* crash_input);
char* MINIMIZE(char* crash_input);

int main(int argc, char* argv[]){
    /*
        argv[]
        [0]: information of cimin
        [7]: target program
        [8~]: target program's arguments
    */
    int option;
    int option_i = 0;
    char *option_i_arg = NULL;

    int option_m = 0;
    char *option_m_arg = NULL;

    int option_o = 0;
    char *option_o_arg = NULL;

    while ((option = getopt(argc, argv, "i:m:o:")) != -1) {
        switch (option) {
            case 'i':
                option_i = 1;
                option_i_arg = optarg;
                break;
            case 'm':
                option_m = 1;
                option_m_arg = optarg;
                break;
            case 'o':
                option_o = 1;
                option_o_arg = optarg;
                break;
            case '?':
                if (optopt == 'i' || optopt == 'm' || optopt == 'o') {
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                } else {
                    fprintf(stderr, "Unknown option: -%c\n", optopt);
                }
                return EXIT_FAILURE;
            default:
                printf("Unknown option: %c\n", optopt);
                return EXIT_FAILURE;
        }
    }

    printf("");

    // Do something with the options
    printf("Option i: %s\n", option_i_arg);
    printf("Option m: %s\n", option_m_arg);
    printf("Option o: %s\n", option_o_arg);

    return EXIT_SUCCESS;
}

char* reduce(char* crash_input){
    return "hello";
}

char* MINIMIZE(char* crash_input){
    return reduce(crash_input);
}