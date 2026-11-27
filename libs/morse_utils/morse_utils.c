#include <stdio.h>
#include <string.h>
#include "morse_utils.h"
static char translate_morse(char* input);



void morse_to_ascii(const char* input, char* dest){
    size_t len = strlen(input);
    char current[6];
    memset(current, '\0', sizeof(current));

    for (size_t i = 0; i < len; i++){
        if (input[i] == '-' || input[i] == '.' || input[i] == '\n'){
            current[strlen(current)] = input[i];
            continue;
        } else if (input[i] == ' ') {
            if (strlen(current) == 0){
                dest[strlen(dest)] = ' ';
            }
            else {
                dest[strlen(dest)] = translate_morse(current);
                memset(current, '\0', sizeof(current));
            }
        }
    }
    if (strlen(current) > 0)
        dest[strlen(dest)] = translate_morse(current);
}

static char translate_morse(char* input){

    if (!strcmp(input, ".-"))
        return 'a';
    if (!strcmp(input, "-..."))
        return 'b';
    if (!strcmp(input, "-.-."))
        return 'c';
    if (!strcmp(input, "-.."))
        return 'd';
    if (!strcmp(input, "."))
        return 'e';
    if (!strcmp(input, "..-."))
        return 'f';
    if (!strcmp(input, "--."))
        return 'g';
    if (!strcmp(input, "...."))
        return 'h';
    if (!strcmp(input, ".."))
        return 'i';
    if (!strcmp(input, ".---"))
        return 'j';
    if (!strcmp(input, "-.-"))
        return 'k';
    if (!strcmp(input, ".-.."))
        return 'l';
    if (!strcmp(input, "--"))
        return 'm';
    if (!strcmp(input, "-."))
        return 'n';
    if (!strcmp(input, "---"))
        return 'o';
    if (!strcmp(input, ".--."))
        return 'p';
    if (!strcmp(input, "--.-"))
        return 'q';
    if (!strcmp(input, ".-."))
        return 'r';
    if (!strcmp(input, "..."))
        return 's';
    if (!strcmp(input, "-"))
        return 't';
    if (!strcmp(input, "..-"))
        return 'u';
    if (!strcmp(input, "...-"))
        return 'v';
    if (!strcmp(input, "-..-"))
        return 'x';
    if (!strcmp(input, "-.--"))
        return 'y';
    if (!strcmp(input, "--.."))
        return 'z';
    else
        return '?';
}
