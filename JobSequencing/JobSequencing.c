#include<stdio.h>
#include<stdlib.h>

typedef struct jobSequencing{
    char id;
    int dl;
    int profit;
} JOB;

void printJobs(JOB *a, int n){
    printf("\nThe jobs are : \n");
    for(int i=0;i<n;i++){
        printf("%c %d %d\n", a[i].id, a[i].dl, a[i].profit);
    }
}

int min(int a , int b){
    return (a<b?a:b);
}


void merge(JOB *a, int low, int mid, int high){
    int l = mid - low + 1;
    int r = high - mid;
    JOB la[l];
    JOB ra[r];
    for(int i = 0;i<l;i++){
        la[i] = a[low+i];
    }
    for (int i = 0; i < r; i++)
    {
        ra[i] = a[mid+1+i];
    }

    int k=low;
    int i=0,j=0;
    while(i<l && j<r){
        if( la[i].profit>= ra[j].profit){
            a[k]=la[i];
            i++;
        }
        else{
            a[k] = ra[j];
            j++;
        }
        k++;
    }
    if(i<l){
        a[k] = la[i];
        i++;
        k++;
    }
    if(j<r){
        a[k]=ra[j];
        j++;
        k++;
    }
}

void mergesort(JOB *a, int low, int high){
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}


void jobsSeq(JOB *a,int n){
    mergesort(a,0,n-1);
    //printf("Sorted jobs in the order of decreasing profits : \n");
    //printJobs(a,n);
    int chk[n], result[n];
    for(int i =0;i<n;i++){
        chk[i]=0;
        result[i]=0;
    }

    for(int i=0;i<n;i++){
        int dead = a[i].dl;
        for(int j = min(dead,n)-1; j>=0; j--){
            if(chk[j]==0){
                chk[j]=1;
                result[j]=i;
                break;
            }
        }
    }

    printf("\nThe sequenced JOBs are : \n");
    for(int i=0;i<n;i++){
        if(chk[i]){
            int x = result[i];
            printf("id : %c  deadline : %d  profit : %d\n",a[x].id,a[x].dl,a[x].profit);
        }
    }
    printf("\n----------------------------------------------------------------------------\n");
}



int main(){
    printf("\n\n-------|| JOB SEQUENCING PROBLEM ||-------\n\n");
    int n;
    printf("Enter the number of JOBS : ");
    scanf("%d",&n);

    JOB a[n];
    printf("Enter the ID, Deadline and Profit of jobs : \n");
    
    for(int i=0;i<n;i++){
        scanf("\n%c %d %d",&a[i].id,&a[i].dl,&a[i].profit);
    }
    //printJobs(a,n);
    jobsSeq(a,n);


}







/*
a 4 10
b 2 100
c 3 60
d 1 40
 
 
 */