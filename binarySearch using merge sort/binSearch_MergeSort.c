#include <stdio.h>
#include <stdlib.h>
#define INF 999999

void merge(int *arr, int l, int mid, int r){
    int i, j, k;

    int s1 = mid - l + 1;
    int s2 = r - mid;
    int a[s1], b[s2];

    for(i = 0; i < s1; i++){
        a[i] = arr[l + i];
    }
    i = 0;
    for(i = 0; i < s2; i++){
        b[i] = arr[mid + i + 1];
    }

    i = 0; j = 0; k = l;

    while(i < s1 && j < s2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            i += 1;
        }
        else{
            arr[k] = b[j];
            j += 1;
        }
        k += 1;
    }

    while (i < s1){
        arr[k] = a[i];
        i += 1;
        k += 1;
    }
    while (j < s2){
        arr[k] = b[j];
        j += 1;
        k += 1;
    }
}

void mergeSort(int *arr, int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(arr, l , mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r); 
    }
}


void callMergeSort(int *arr, int n){
    int l = 0;
    int r = n - 1;
    mergeSort(arr, l, r);
}



int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of the elements: \n");
    scanf("%d", &n);
    int *arr;
    arr = (int *)malloc(sizeof(int) * n);

    int i;
    printf("Enter the elements of the array: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the key to be found\n");
    scanf("%d", &key);


    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            printf("Array needed to be sorted\n");
            callMergeSort(arr, n);
            break;
        }
    }

    int l = 0;
    int r = n - 1;
    int mid, ok = 0;
    while(l <= r){
        mid = (l + r) / 2;

        if(key == arr[mid]){
            ok = 1;
            break;
        }
        else if(key < arr[mid]){
            r = mid - 1;
        }   
        else{
            l = mid + 1;
        } 
    }
    if(ok)
        printf("%d found at position %d\n", key, mid);
    else{
        printf("%d not found!!\n", key);
    }
    return 0;
}
