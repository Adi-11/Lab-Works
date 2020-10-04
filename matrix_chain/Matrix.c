#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INF 999999

int min(int a, int b){
    return (a < b) ? a : b;
}


int matrixChain(int *arr, int n){
    int dp[n + 1][n + 1]; //for Tabulation

    int i;
    for(i = 1; i < n; i++){
        dp[i][i] = 0;
    }

    int len, j, k;
    len = 2;
    while(len < n){
        for(i = 1; i <= (n - len); i++){
            int j = (len + i - 1);
            dp[i][j] = INF;
            for(k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], (dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]));
            }
        }
        len += 1;
    }
    return dp[1][n - 1];

}

int main(int argc, char const *argv[])
{
    

    int n;
    printf("Enter the array length: \n");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    int i;
    printf("Enter the array elements: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    clock_t tic = clock();
    int result = matrixChain(arr, n);
    printf("Minimum number of multiplications is: %d\n", result);
    clock_t toc = clock();


    printf("Time of execution: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    return 0;
}

// 5 10 3 12 5 50 6