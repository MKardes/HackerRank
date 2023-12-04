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
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
    unsigned long a[30] = {0};
    long tmp;
    a[0] = 1;
    int i = 2;
    int j = 0;
    while (i <= n)
    {
        j = 29;
        while(j >= 0)
        {
            a[j] *= i; //8.589.934.592
            if (a[j] >= 10000000)
            {
                a[j + 1] += a[j] / 10000000;
                a[j] = a[j] % 10000000;
            }
            j--;
        }
        i++;
    }
    i = 29;
    while(i >= 0 && a[i] == 0)
    {
        i--;
    }
    tmp = i;
    while(i >= 0)
    {
        if (a[i] == 0)
            printf("0000000");
        else if (tmp == i)
            printf("%lu",a[i]);
        else
        {
            if (a[i] < 1000000)
            {
                j = 1;
                tmp = a[i];
                while (j<7)
                {
                    tmp *= 10;
                    if (tmp >=1000000)
                        break;
                    j++;
                }
                while(j>=1)
                {
                    printf("0");
                    j--;
                }
            }
            printf("%lu",a[i]);
        }
        i--;
    }
}

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    extraLongFactorials(n);

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
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
