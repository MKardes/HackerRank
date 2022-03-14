#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender)
{
    int i;
    int tmp;
    
    tmp = 0;
    if (gender == 98 && number_of_students >= 1)
    {
        i = 0;
        while(i < number_of_students)
        {
            tmp += marks[i];
            i += 2;
        }      
        return (tmp);
    }
    else if (gender == 103 && number_of_students >= 2)
        i = 1;
        while(i < number_of_students)
        {
            tmp += marks[i];
            i += 2;
        }      
        return (tmp);
    return (0);
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}
