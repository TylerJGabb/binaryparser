#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char binary_str_to_char(char *str){
    size_t len = strlen(str);
    if(len > 8){
        fprintf(stderr, "String .%s. is too long to represent an 8 bit number", str);
        exit(1);
    }
    int i;
    int value = 0;
    int bit = 1;
    for(i = len - 1; i > -1; i--){
        int conversion = (int)*(str+i) - 48; //dereference character at position str + i, then subtract 48
        if(conversion < 0 || conversion > 1){
            fprintf(stderr, "Found non-binary character .%c.", *(str+i));
            exit(2);
        }
        value += (conversion * bit);
        bit = bit * 2;
    }
    return (char)value;
}

int main(int count, char **args){
    char *buf = (char*) malloc(9);
    int read = 0;
    while((read = scanf("%8s", buf)) != EOF){
        printf("%c", binary_str_to_char(buf));
    }
    printf("\n");
    free(buf);
    return 0;
}