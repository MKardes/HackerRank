/*
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

*/
char* timeConversion(char* s)
{
    int     i = 0;
    int     a;
    
    if (s[8] == 'P')
    {
        printf("1\n");
        if (s[0] != '0' && !(s[0] == '1' && s[1] == '2'))
            a = (s[0] - 48) * 10 + s[1] - 48;
        else if (s[1] != '0' && !(s[0] == '1' && s[1] == '2'))
            a = s[1] - 48;
        else
            a = 0;
        a += 12;
        s[1] = a % 10 + 48;
        s[0] = a / 10 + 48;
    }
    else if (s[0] == '1' && s[1] == '2')
    {
        s[0] = '0';
        s[1] = '0';
    }
    s[8] = '\0';
    return s;
}
/*
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}*/
