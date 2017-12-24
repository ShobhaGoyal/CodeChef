#include<stdio.h>
//wrong que by compiler as on n=5 it is not working
void reset(int n,int a[][n])
{   int j,k;
	 for(j=0;j<n;j++)
	   {    for(k=j;k<n;k++)
	      {     
	   	     a[k][k]=0;
	   	     if(j!=k)
	   	     {
	   	     	a[j][k]=1;
	   	     	a[k][j]=0;
	   	     }
	   	   }
	   }
}
int check(int n,int a[][n])
{
	 int sum=0,k,j,count;
	   for(j=0;j<n;j++)
	   {
	   	count=0;
	   	 for(k=0;k<n;k++)
	   	 {  if(a[j][k]==1)
	   	      count++;
	   	 }
	   	 sum=sum+count*count;
	   }
	   return sum;
}
void display(int n,int a[][n])
{   int j,k;
	 for(j=0;j<n;j++)
	      {  for(k=0;k<n;k++)
	      {
	      	printf("%d",a[j][k]);
	      }
	   	    printf("\n");
	      }
}
main()
{
	
	int t;
	scanf("%d",&t);
	
	int i;
	for(i=0;i<t;i++)
	{  
	int set=0;
		int n,k;
	   scanf("%d%d",&n,&k);
 	  
	   
	   
	   if(n==1 || n==0)
	   {
	   	set=0;
	   }
	   else
	   {
	   int a[n][n];
	    reset(n,a);
	    int sum=check(n,a);
	    
	   if(sum<k)
	   		set=0;
	   	else if(sum%2==0 && k%2!=0)
	   		set=0;
	   	else if(sum%2!=0 && k%2==0)
	   		set=0;
	   else 
	   {
	   if(sum==k)
	     {
	     display(n,a);
	   	 set=1;
	    }
		else
	   	 {  int j,l;
	   	  
			 for(j=0;j<n;j++)
	   	   {      for(l=(n-1);l>j;l--)
	   	          { a[j][l]=0;
	   	             a[l][j]=1;
	   	          //display(n,a);
	   	          //printf("\n");
	   	          int sum=check(n,a);
	   	          //printf("\n%d\n",sum);
	   	          if(sum==k)
	   	          {   //printf("//////////\n");
					 display(n,a);
	   	             set=1;
	   	              break;
	   	         }
	   	         }
	   	       reset(n,a);
	   	       if(set==1)
	   	        break;
	   	   }
	   	 	
	   	 }
	   }
		}
	   if(set==0)
	   printf("-1\n");
	
	}
}
