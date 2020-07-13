#include<stdio.h>
#include<stdlib.h>

typedef struct Knapsack_greedy
{
    int profit;
    int weight;
    float probywgt; 
}sack1;

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

void bsort(sack1 *A, int n)
{
    int i, j;
    sack1 temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < (n - 1 - i); j++){
            if (A[j].probywgt < A[j + 1].probywgt){
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            } 
        }
    }

}

double knapsack_greedy(sack1 *A, int n, int max_weight)
{
    bsort(A, n);
    int cur_weight = 0, i, reminder = 0; 
    double result = 0;
    for(i = 0; i < n; i++){
        if(cur_weight + A[i].weight <= max_weight){
            cur_weight = cur_weight + A[i].weight;
            result = result + A[i].profit;
        }

        else{
            reminder = max_weight - cur_weight;
            result = result + (A[i].profit * ((1.0) * reminder / A[i].weight));
            break;
        }
    }
    return result;
}



int main()
{
    int swt;
    printf("Enter 1 for greedy approach and 2 for DP approach for filling the sack:\n");
    scanf("%d",&swt);
    if(swt == 1){
            int n, max_weight;
            int p, w;
            printf("Enter the number of objects and maximum weight that can be filled in the sack:\n");
            scanf("%d %d",&n, &max_weight);
            int i;
            sack1 A[n];
            printf("Enter the profit value and wight value of the object:\n");
            for(i = 0; i < n; i++){
                scanf("%d %d",&p, &w);
                A[i].profit = p;
                A[i].weight = w;
                A[i].probywgt = ((double)p / w);
            }
            double result;
            result = knapsack_greedy(A, n, max_weight);
            printf("The maximum profit by the given capacity of the sack is:\n");
            printf("%lf", result);
        }
        else if(swt == 2){
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
        }
    else{
        printf("Invalid input\n");
    }
    return 0;
}