#include <stdio.h>
#include <string.h>
#include "morse_utils.h"
static char translate_morse(char* input);



void morse_to_ascii(const char* input, char* dest){
    size_t len = strlen(input);
    char current[7]; //buffer to store a character in morse code
    memset(current, '\0', sizeof(current)); //setting the whole thing to \0 so it wont contain garbo

    //iterating over the input, filling destination with ascii
    for (size_t i = 0; i < len; i++){

        if (strlen(current) > 5) //if morse code is invalid, do this so that everything wont crash
            memset(current, '\0', sizeof(current));
        if (strlen(dest) > 20) //we are over the limit of the destination buffer, might as well leave
            return;
        

        if (input[i] == '-' || input[i] == '.' || input[i] == '\n'){
            current[strlen(current)] = input[i]; //if its dot or dash, add it to current
            continue;
        } else if (input[i] == ' ') {
            if (strlen(current) == 0){
                dest[strlen(dest)] = ' ';
            }
            else {
                dest[strlen(dest)] = translate_morse(current);
                memset(current, '\0', sizeof(current)); //clearing current
            }
        }
    }
    if (strlen(current) > 0) //process anything that might've been left over
        dest[strlen(dest)] = translate_morse(current); 
}

static char translate_morse(char* input){

    //letters
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
    if (!strcmp(input, ".--"))
        return 'w';
    if (!strcmp(input, "-..-"))
        return 'x';
    if (!strcmp(input, "-.--"))
        return 'y';
    if (!strcmp(input, "--.."))
        return 'z';
    // numbers
    if (!strcmp(input, "-----"))
        return '0';
    if (!strcmp(input, ".----"))
        return '1';
    if (!strcmp(input, "..---"))
        return '2';
    if (!strcmp(input, "...--"))
        return '3';
    if (!strcmp(input, "....-"))
        return '4';
    if (!strcmp(input, "....."))
        return '5';
    if (!strcmp(input, "-...."))
        return '6';
    if (!strcmp(input, "--..."))
        return '7';
    if (!strcmp(input, "---.."))
        return '8';
    if (!strcmp(input, "----."))
        return '9';
    else
        return '?';
}
