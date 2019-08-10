#include <stdio.h>
#define MAX_LENGTH 5

int func(int number);
void map(int *array, int length, int (*f)(int));
void print_array(int *array, int length);

int main(void)
{
    int data[MAX_LENGTH] = {-1, 12, -13, 0, -14, 133};
    map(data, MAX_LENGTH, func);
    print_array(data, MAX_LENGTH);
    return 0;
}

int func(int number) { return number * number * number; }

void map(int *array, int length, int (*f)(int))
{
    int i;
    for (i = 0; i < length; i++)
    {
        array[i] = (*f)(array[i]);
    }
}

void print_array(int *array, int length)
{
    int i;
    printf("{");
    for (i = 0; i < length; i++)
    {
        printf("%d", array[i]);
        if (i < length - 1)
        {
            printf(", ");
        }
    }
    printf("}");
}