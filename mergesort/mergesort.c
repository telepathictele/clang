#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20


//int array[MAX];
int size; 

void maker(void);
void merge(int arr[], int right, int left);
void sort(int arr[], int right, int middle, int left);

time_t t; 

int main(int argc, char *argv[])
{
    size = atoi(argv[1]);

    if (argc > 2 || argc == 0)
    {
        printf("Please enter a number (and only one numebr)\n");
        return 1; 
    }

    if (size > MAX || size < 1)
    {
        printf("Please enter a number between 1 and 20 (inclusive)\n");
    }
    
    int array[size];
    srand((unsigned) time(&t));
    for(int i = 0; i < size; i++)
    {
        array[i] = (rand() % 10);
    }

    merge(array, 0, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0; 

}   


void merge(int arr[], int left, int right)
{
    if (left > right)
    {
        return; 
    }
    else
    {
        int middle = (left + right)/2;

        merge(arr, right, middle);
        merge(arr, middle, left);
        sort(arr, right, middle, left);
    }

}

void sort(int arr[], int left, int middle, int right)
{
    int temp; 
      //sort left half of array
    for(int i = right; i < middle + 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp; 
        }
    }
    //sort right half of array
    for (int i = middle; i <= left; i++)
    {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp; 
    }
    return; 
}