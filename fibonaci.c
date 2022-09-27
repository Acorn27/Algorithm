#include <stdio.h>

void fill_fibonaci_sequence(int[], int);
int return_fibonaci_term(int);
void printSequence(int[], int size);

int main(void)
{
    int number_of_terms;
    printf("Please enter number of term in fibonaci sequence: ");
    scanf("%d", &number_of_terms);

    int fibonaci_sequence[100] = {};
    fill_fibonaci_sequence(fibonaci_sequence, number_of_terms);

    printSequence(fibonaci_sequence, number_of_terms);

    return 0;
}

int return_fibonaci_term(int nTerm)
{
    if (nTerm == 1 || nTerm == 2) 
    {
        return 1;
    }
    else {

        return (return_fibonaci_term(nTerm-1) + return_fibonaci_term(nTerm-2));

    }
}

void fill_fibonaci_sequence(int sequence[], int size)
{
    for (int i = 0; i < size; i++)
    {
        sequence[i] = return_fibonaci_term(i+1);
    }
}

void printSequence(int sequence[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sequence[i]);
    }
}
