# include <stdio.h>

int binary_search(int, int[], int, int);

int main()
{
    int index = -1;
    int array[] = {1,2,3,4,5,6};
    int search_number;

    printf("Which number do you want to search for: ");
    scanf("%d", &search_number);

    index = binary_search(search_number, array, 0, sizeof(array)/ sizeof(int)-1);

    if (index == -1)
    {
        printf("%d is not in the sequence.\n", search_number);

    }
    else
    {

        printf("%d is the element %d of the sequence.\n", search_number, index);

    }
}

int binary_search(int search_number, int array[], int start, int end) {

    if (start > end)
    {
        return -1;
    }
    else
    {
        int mid_index = (end + start) / 2;

        if (array[mid_index] == search_number)
        {
            return (mid_index);
        }
        else if (array[mid_index] >  search_number)
        {
            end = mid_index - 1;
        }
        else
        {
            start = mid_index + 1;
        }

        binary_search(search_number, array, start, end);
    }

}