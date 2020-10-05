#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INF 999999

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapSack(int *cap, int *profit, int n, int max_wt){
    int dp[n + 1][max_wt + 1];

    int i, j;
    for(i = 0; i <= n; i++)
        for(j = 0; j <= max_wt; j++)
            dp[i][j] = 0;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= max_wt; j++){
            if(cap[i - 1] <= j){
                dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i - 1][j - cap[i - 1]]);
            }
            else
                dp[i][j] = dp[i -1][j];
        }
    }
    return dp[n][max_wt];
}


int main(int argc, char const *argv[])
{
    int n, max_wt;
    printf("Enter the number of jobs and max. capacity of the sack: \n");
    scanf("%d %d", &n, &max_wt);


    int *cap, *profit;
    cap = (int *)malloc(sizeof(int) * n);
    profit = (int *)malloc(sizeof(int) * n);

    int i;
    printf("Enter the weight and profit: \n");
    for(i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        cap[i] = x;
        profit[i] = y;
    }

    int maxProfit = knapSack(cap, profit, n, max_wt);
    printf("Maximum profit is: %d\n", maxProfit);
    
    return 0;
}

// 5 10 3 12 5 50 6