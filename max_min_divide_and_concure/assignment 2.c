 #include<stdio.h>


void maximum(int a[],int l,int h,int *min,int *max)
{
	
	if(l==h)
	{
		if(*max<a[l])
			*max=a[l];
		
		if(*min>a[h])
			*min=a[h];
		
		return;
	}
	
	else if(l+1==h)
	{
		if(a[l]<a[h])
		{
			if(*min>a[l])
				*min=a[l];
				
			if(*max<a[h])
				*max=a[h];
		}
		else
		{
			if(*min>a[h])
				*min=a[h];
		 	if(*max<a[l])
				*max=a[l];
		}
		return;
	}
	
	int mid=(l+h)/2;
	maximum(a,l,mid,min,max);
	maximum(a,mid+1,h,min,max);
}

int main()
{
	int n,max=-999999,min=999999;
	int t=1,x;
	while(t)
	{
	
	printf("Enter the length of the array : ");
	scanf("%d",&n);
	int a[n],i;
	printf("\nEnter the elements of the array : ");
	for(i=0;i<n;i++)
			scanf("%d",&a[i]);
	
	printf("\n1.Divide & conquer\n2.dynimically\n3.Exit\nchoice : "); 
	scanf("%d",&x);
	switch(x)
	{
	case 1:
		maximum(a,0,n-1,&min,&max);
		printf("\nMaximum : %d\nMinimum : %d\n",max,min);
		break;
	
	case 2:
		max=a[0];
		min=a[0];
		for(i=1;i<n;i++)
		{
			max=max>a[i]?max:a[i];
			min=min<a[i]?min:a[i];
		}
		printf("\nMaximum = %d\nMinimum = %d\n",max,min);
		break;
	case 3:
		t=0;
	
	}	
  }

}
