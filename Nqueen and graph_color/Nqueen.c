#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0

typedef struct Nqueen
{
    int n;
    int **board;
}queen;


int isSafeToPlace(queen *a, int start, int i)
{
    //Checking for row
    int r;
    for(r = 0; r < start; r++){
        if(a->board[r][i] == 1){
            return false;
        }  
    }
    //Checking for left and right digonals
    int digL, digR;
    digL = start;
    digR = i;
    while (digL >= 0 && digR >= 0){
        if(a->board[digL][digR] == 1){
            return false;
        }
        digR--;
        digL--;
    }

    digL = start;
    digR = i;
    while (digL >= 0 && digR < a->n){
        if(a->board[digL][digR] == 1){
            return false;
        }
        digR++;
        digL--;
    }
    //If safe return true
    return true;
}

int solveNqueen(queen *a, int start)
{
    //base case
    if(a->n == start){
        //print board
        int x, y;
        printf("+-");
        for(x = 0; x < 2 * a->n; x++)
            printf("-");
        printf("+");
        printf("\n");
        for(x = 0; x < a->n; x++){
            printf("| ");
            for(y = 0; y < a->n; y++){
                if(a->board[x][y] == 1){
                    printf("Q ");
                }
                else{
                    printf(". ");
                } 
            }
            printf("|");
            printf("\n");
        }
        printf("+-");
        for(x = 0; x < 2 * a->n; x++)
            printf("-");
        printf("+");
        printf("\n\n");
        return false; 
    }

    //recursive call under which backtracking will be operated
    int i;
    for(i = 0; i < a->n; i++){
        if(isSafeToPlace(a, start, i)){
            a->board[start][i] = 1;

            int placeNext;
            placeNext = solveNqueen(a, start + 1);
            if(placeNext){
                return true;
            }
            //if placenext is false then position is wrong
            a->board[start][i] = 0;
        }
    }
    return false;
}

int main()
{
    queen *a = (queen *)malloc(sizeof(queen));
    printf("Enter the number of the queen:\n");
    scanf("%d",&a->n);
    int i, j;

    a->board = (int **)malloc(sizeof(int) * (a->n));
    for(i = 0; i< a->n; i++)
        a->board[i] = (int *)malloc(sizeof(int) * (a->n));

    solveNqueen(a, 0);
    return 0;
}