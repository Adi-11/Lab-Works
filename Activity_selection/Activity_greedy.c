#include<stdio.h>
#include<stdlib.h>

typedef struct Activity_greedy
{
    int start;
    int finish;
}act;

void bsort(act *A, int n)
{
    int i, j;
    act temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < (n - 1 - i); j++){
            if (A[j].finish > A[j + 1].finish){
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            } 
        }
    }
}

void Activity(act *A, int n)
{
    int output[n], i, j;
    for(i = 0; i< n; i++)
        output[i] = 0;
    bsort(A, n);
    printf("The sequence of mutually compatible jobs is:\n");
    printf("%d --> %d", A[0].start, A[0].finish);
    i = 0;
    for(j = 1; j < n; j++){
        if(A[j].start >= A[i].finish)
        {
            output[j] = j;
            i = j;
        }
    }
    int ctr = 1;
    printf("\n");
    for(i = 1; i < n ; i ++){
        if(output[i] != 0){
            printf("%d --> %d", A[i].start, A[i].finish);
            printf("\n");
            ctr++;
        }
    }
    printf("Total number of activity is: %d", ctr);
}


int main()
{
    int n, i;
    printf("Enter the number of activity a person want to perform:\n");
    scanf("%d",&n);
    act A[n];
    printf("Enter the starting time and finishing time:\n");
    for(i = 0; i< n; i++)
        scanf("%d %d", &A[i].start, &A[i].finish);
    Activity(A, n);
}