#include <stdio.h>


void sortArray(int unsortedArray[], int size);

int main()
{

    int unsortedArray[] = {23, 12, 9, -3, 89, 54};

    int size = sizeof(unsortedArray) / sizeof(int);


    sortArray(unsortedArray, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",unsortedArray[i]);
    }


}

// recursive selection sort
void sortArray(int unsortedArray[], int size)
{

    if (size == 1) 
    {
        printf("Array is sorted\n");
    }
    else
    {   

        int biggest_index = 0;
        int change = 1;

        // search for biggest index in slide
        for (int i = 1; i <= size - 1; i++)
        {   
            // < for descending order
            // > for ascending order
            if (unsortedArray[i] > unsortedArray[biggest_index])
            {
                biggest_index = i;
            }
        }

        // swap
        int temp = unsortedArray[size - 1];
        unsortedArray[size - 1] = unsortedArray[biggest_index];
        unsortedArray[biggest_index] = temp;
        
        // recursive call
        sortArray(unsortedArray, size - 1);
    }



}