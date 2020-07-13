#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0

typedef struct assignment_12
{
    int n;
    int *arr; //Store the original array
    int *freq; //Store the frequency of appearance of each index
}myData;

// function to give the number it basically based on backtracking
int solve(int digit, myData *A)
{
    int init;
    int i;

    if(digit == 0){
        A->arr[0] = A->freq[0];
        A->freq[0] = 0;
        A->freq[A->arr[0]]--;
        for(i = 0; i < A->n; i++){
            if(A->freq[i] != 0){
                A->freq[0] = A->arr[0];
                A->freq[A->arr[0]]++;
                return false;
            }
        }
        return true;
    }

    init = A->freq[digit];
    
    for(i = init; i < digit; i++){
        A->arr[digit] = i;
        A->freq[digit] = i - init;
        A->freq[i]++;
        if(solve(digit - 1, A)){
            return true;
        }
        //Fucntion will go in backtracking and undo the increment operation
        A->freq[i]--;
    }

    if(digit != init){
        A->arr[digit] = digit;
        A->freq[digit] = digit - 1 - init;
        if(solve(digit - 1, A)){
            return true;
        }
    }

    for(i = digit + 1; i < A->n; i++){
        if(A->freq[i] != 0){
            A->arr[digit] = i;
            A->freq[digit] = i - init;
            A->freq[i]--;
            if(solve(digit - 1, A)){
                return true;
            }
            A->freq[i]++;
        }
    }
    A->freq[digit] = init;
    return 0;
}



int main()
{
    myData *A;
    printf("Enter the number of digit:\n");
    scanf("%d",&A->n);
    int i;
    A->arr = (int *)malloc(sizeof(int) * (A->n));
    A->freq = (int *)malloc(sizeof(int) * (A->n));

    for(i = 0; i < A->n; i++){
        A->arr[i] = 0;
        A->freq[i] = 0;
    }

    //Function call
    int result =  solve((A->n - 1), A);

    if(result){
        printf("The required number is :\n");
        for(i = 0; i < A->n; i++)
            printf("%d",A->arr[i]);
        printf("\n");
    }
    else
        printf("Number does not exists!!!\n");
    
    return 0;
}