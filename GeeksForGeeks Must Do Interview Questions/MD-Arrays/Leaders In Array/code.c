#include <stdio.h>
#include<stdlib.h>
int *findLeaders(int);

int main()
{
    int T, N, n, j;
    scanf("%d", &T);
    int **output = (int **)malloc(sizeof(int *) * T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        output[i] = findLeaders(N);
    }
    for (int i = 0; i < T; i++)
    {
        for (j = 0; output[i][j] != -1; j++);
        for(--j;j>=0;j--)
            printf("%d ", output[i][j]);
        printf("\n");
    }
}

//Scans from right to find leaders. Compare the largest element with every element traversed. Stores them into an array and returns the array. 
int *findLeaders(int len)
{
    int arr[len], max, j = 1;

    int * leaders = (int *)malloc(sizeof(int)*(len+1));

    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    leaders[0] = arr[len - 1];
    max = arr[len - 1];

    for (int i = len - 2; i >= 0; i--)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
            leaders[j++] = arr[i];
        }
    }
    leaders[j] = -1;
    return leaders;
}