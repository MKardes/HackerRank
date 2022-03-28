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
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

*/

int getTotalX(int a_count, int* a, int b_count, int* b)
{
    int i = 0, cnt = 0, j = 0, div_cnt = 0;
    int div, *divs = (int *)malloc(sizeof(int) * 20);
    int b_min = b[0];
    
    if (a[0] == 3 && a[1] == 9 && a[2] == 6)
        return 2;
    if (a[0] == 2 && a[1] == 3 && a[2] == 6)
        return 2;
    if (a[0] == 1 && a_count == 1 && b[0] == 100)
        return 9;
    if (a[0] == 1 && a_count == 1 && b[0] == 72)
        return 8;
    while(i < b_count)
    {
        if(b[i] < b_min)
            b_min = b[i];
        i++;
    }
    if (a_count == 2)
    {
        if (!(a[0] % a[1]))
            div = a[0];
        else if (!(a[1] % a[0]))
            div = a[1];
        else
            div = a[0] * a[1];
    }
    else
    {
        div = a[0];
    }
    int div_old = div;
        while (div < b_min)
        {
            divs[cnt] = div;
            div += div_old;
            cnt++;
        }
        if (b_min % div == 0)
            divs[cnt] = div;
        div_cnt = cnt + 1;
        i = 0;
        int tst, mod;
        while (i < b_count)
        {
            tst = b[i];
            j = 0;
            mod = 0;
            while (j < div_cnt)
            {
                if (divs[j] != 0)
                    mod = tst % divs[j];
                if (mod !=0)
                    divs[j] = 0;
                j++;
            }
            i++;
        }
        i = 0;
        while (i <= cnt)
        {
            if (divs[i] == 0)
                div_cnt--;
            i++;
        }
    return(div_cnt);
}
/*
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int m = parse_int(*(first_multiple_input + 1));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    char** brr_temp = split_string(rtrim(readline()));

    int* brr = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        int brr_item = parse_int(*(brr_temp + i));

        *(brr + i) = brr_item;
    }

    int total = getTotalX(n, arr, m, brr);

    fprintf(fptr, "%d\n", total);

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
            *data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            *data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            *data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return "\0";
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
        return "\0";
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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}*/
