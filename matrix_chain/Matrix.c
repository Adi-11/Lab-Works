#include<stdio.h>
#include<stdlib.h>

int MatrixChainMult(int arr[], int n)
{

	int A[n][n];

	int i, j, k, L, q;

	for (i=1; i<n; i++)
		A[i][i] = 0;

	for (L=2; L<n; L++)
	{
		for (i=1; i<n-L+1; i++)
		{
			j = i+L-1;
			A[i][j] = 999999;
			for (k=i; k<=j-1; k++)
			{
				q = A[i][k] + A[k+1][j] + arr[i-1]*arr[k]*arr[j];
				if (q < A[i][j])
					A[i][j] = q;
			}
		}
	}

	return A[1][n-1];
}

int main()
{
	int n,i, result;
    printf("Enetr the Size of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for ( i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    result = MatrixChainMult(arr, n);

    printf("The minimum number of scalar multiplication needed for chain of matrix\n");
    printf("%d",result);
	return 0;
}
