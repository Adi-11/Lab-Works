#include<stdio.h>
#include<stdlib.h>


void solve(int n)
{
    if(n == 1 || n == 2 || n == 3 || n == 6){
        printf("No such number exists for %d digit number\n", n);
        return;
    }
    else if(n == 4){
        printf("The required number is: 1210 or 2020");
        return;
    }
    else if(n == 5){
        printf("The required number is: 21200");
    }
    else{
        int arr[n];
        arr[0] = n - 4;
        arr[1] = 2;
        arr[2] = 1;
        int i = n - 7;
        int x = 3;
        while(i > 0){
            arr[x] = 0;
            i -= 1;
            x += 1;
        }
        for(i = n - 1; i >= n - 4; i--){
            arr[i] = 0;
            if(i == n - 4)
                arr[i] = 1;
        }
        printf("The required number is:\n");
        for(i = 0; i < n; i++){
            printf("%d",arr[i]);
        }
        return;
    } 
}


int main()
{
    int num;
    printf("Enter the number of digits:\n");
    scanf("%d",&num);
    solve(num);
    return 0;
}