#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findMajority(int);
int mooreVoting(int *, int);
int main()
{
    int T, N, n;
    scanf("%d", &T);
    int *majority = (int *)malloc(sizeof(int) * T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        majority[i] = findMajority(N);
    }
    for (int i = 0; i < T; i++)
        printf("%d\n", majority[i]);
}

int findMajority(int len)
{
    int array[len], i, c, count = 0;
    bool isMajority;
    for (i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }

    c = mooreVoting(array, len);
    for (i = 0; i < len; i++)
        if (array[i] == c)
            count++;
    if (count > len / 2)
        isMajority = 1;
    else
        isMajority = 0;

    if (isMajority)
        return c;
    else
        return -1;
}

int mooreVoting(int *arr, int len)
{
    int maj_index = 0, count = 1, i;
    for (i = 1; i < len; i++)
    {
        if (arr[i] == arr[maj_index])
            count++;
        else
            count--;

        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return arr[maj_index];
}