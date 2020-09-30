#include<stdio.h>
#include<stdlib.h>
typedef struct JOB{
    int id;
    int initial;
    int fnl;
}JOB;
void merge(JOB *arr,int low,int mid,int high){

    int l = mid - low +1;
    int r = high - mid;
    JOB larr[l];
    JOB rarr[r];
    int i;
    for(i=0;i<l;i++){
        //larr[i]=arr[low+i];
        larr[i].id =arr[low+i].id;
        larr[i].fnl =arr[low+i].fnl;
        larr[i].initial=arr[low+i].initial;
    }
    for(i=0;i<r;i++){
        //rarr[i]=arr[mid+1+i];
        rarr[i].id =arr[mid+1+i].id;
        rarr[i].fnl =arr[mid+1+i].fnl;
        rarr[i].initial=arr[mid+1+i].initial;
    }
    int j=0,k=low;
    i=0;
    while(i < l && j<r){
        if(larr[i].fnl <= rarr[j].fnl){
            arr[k]=larr[i];
            i++;
        }
        else{
            arr[k]=rarr[j];
            j++;
        }
        k++;
    }
    while(i<l){
        arr[k]=larr[i];
        i++;
        k++;
    }
    while(j<r){
        arr[k]=rarr[j];
        j++;
        k++;
    }
}
void mergesort(JOB *arr,int low,int high){

    if(low<high){
        int mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    printf("|| JOB SEQUENTIAL PROBLEM ||\n\n");
    int n,i;
   //A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, si = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12} and fi = {5, 7, 8, 10, 11, 12, 13, 14, 15, 16}.
    JOB jobsarr[]={{1,3,5},{2,4,7},{3,5,8},{4,6,10},{5,7,11},{6,8,12},{7,9,13},{8,10,14},{9,11,15},{10,12,16}};
    n=10;
    mergesort(jobsarr,0,n-1);
    int slot[n];
    int count=0,t;
    int j=0,x;
    slot[0]=jobsarr[0].id;
    count++;
    for(i=1;i<n;i++){
        if(jobsarr[i].initial>=jobsarr[j].fnl){
            slot[count]=jobsarr[i].id;
            count++;
            j=i;
        }
    }
    printf("Following is final sequence of jobs : \n");
    for(i=0;i<count;i++)
        printf("%d  ",slot[i]);
    printf("\n");
}
