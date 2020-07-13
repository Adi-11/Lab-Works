#include<stdlib.h>
#include<stdio.h>

typedef struct Knapsack_DP
{
    int profit;
    int value;
}sack2;

int max(int a, int b)
{
    return (a > b) ? a : b ;
}

int knapsack_DP(sack2 *A, int n, int max_weight)
{
    int i, j;
    int dp[n + 1][max_weight + 1];
    for (i = 0; i <= n; i++){
        for(j = 0; j <= max_weight; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(A[i].value <= j) 
                dp[i][j] = max(A[i - 1].profit + dp[i - 1][j - (A[i - 1].value)], dp[i -1][j]);
            else
                dp[i][j] = dp[i - 1][j];  
            
        }
    }

    return dp[n][max_weight];
}


int main()
{
    int n, max_weight;
    printf("Enter the number of objects and the maximum capacity of the sack:\n");
    scanf("%d %d", &n, &max_weight);
    sack2 A[n];
    int i;
    printf("Enter the profit and weight of the objects:\n");
    for(i = 0; i < n; i++)
        scanf("%d %d", &A[i].profit, &A[i].value);

    int result;
    result = knapsack_DP(A, n, max_weight);
    printf("The maximum profit by the given capacity of the sack is:\n");
    printf("%d", result);
    return 0;
}