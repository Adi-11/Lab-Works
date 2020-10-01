#include<stdio.h>
#include<stdlib.h>

int main(){

    int coins[10] = {1,2,5,10,20,50,100,200,500,2000};
    printf("Enter the Value : ");
    int value;
    scanf("%d",&value);

    int num[10];
    for(int i=0;i<10;i++){
        num[i] = 0;
    }

    int i = 9;
    while(value!=0 && i>-1){
        if(coins[i]<=value){

            num[i] = value / coins[i];
            value -= coins[i]*num[i];
            //printf("value: %d coins: %d",value, num[i]);
        }
        i--;        
    }

    printf("\n\nCoin value : Number of coins\n");
    for(int i =9;i>=0;i--){
        if(num[i]>0){
            printf("%d  :    %d\n",coins[i], num[i]);
        }
    }
    printf("\n---------------------------------------\n\n");
    return 0;
}