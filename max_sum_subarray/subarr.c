#include<stdio.h>
#include<stdlib.h>

//Returns the max value
int max(int a, int b)
{
    return (a > b) ? a : b;
}


//Recursive function to get the max Subarray
int solve(int arr[], int n)
{
    if(n == 1)          //Base Case
        return arr[0];
    

    //All the recursive call over the left half
    // and right half 
    int mid = n / 2;  //Middle point
    int left_MSS, right_MSS; //MSS = MAximum Sum Subarray

    /* Return maximum of following three possible cases 
      a) Maximum subarray sum in left half 
      b) Maximum subarray sum in right half */
    
    left_MSS = solve(arr, mid); //made a recursive call
    right_MSS = solve(arr + mid, n - mid); //made a recursive call

    //
    int left_rec = INT_MIN, right_rec = INT_MIN, sum = 0, i;

    // for the elements on the left side of the mid
    for(i = mid; i < n; i++){
        sum += (arr[i]);
        right_rec = max(right_rec, sum);
    }

    // for the elements on the right side of the mid
    sum = 0;
    for(i = (mid - 1); i >= 0; i--){
        sum += (arr[i]);
        left_rec = max(left_rec, sum);
    }

    //We will get the maximum of the left or right Sum Subarray
    int maxSum = max(left_MSS, right_MSS);
    
    //return the maximum of the left or right or best subarray throught the middle
    return(max(maxSum, left_rec + right_rec));
}




int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array::\n");
    int i, a;
    for(i = 0; i < n; i++){
        scanf("%d",&a);
        arr[i] = a;
    }
    int result = solve(arr, n);
    printf("The required maximum sum of the subarray is:: %d\n",result);
    return 0;
}
