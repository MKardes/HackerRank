#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_check(const char *a)
{
    int dig[127] = {0};
    int i = 0, say = 0;
    while (a[i])
    {
        if (!dig[a[i]])
            dig[a[i]] = 1;
        i++;
    }
    i = 0;
    while (i < 128)
    {
        if(dig[i] != 0)
            say += 1;
        i++;
    }
    return (say);
}

int lexicographic_sort(const char* a, const char* b) {
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i])
        i++;
    return (a[i] - b[i]);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i])
        i++;
    return (b[i] - a[i]);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int say = char_check(a), say1 = char_check(b);
    if (say == say1)
        return(lexicographic_sort(a, b));
    return (say - say1);
}

int sort_by_length(const char* a, const char* b) {
    int i = 0, j = 0;
    while (a[i] != '\0')
        i++;
    while (b[j] != '\0')
        j++;
    if (i == j)
        return(lexicographic_sort(a, b));
    return (i - j);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i = 0;
    int j;
    char    *tmp;
    while (i < len)
    {
        if (!arr[i])
            return ;
        i++;
    }
    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (cmp_func(arr[i], arr[j]) > 0)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
