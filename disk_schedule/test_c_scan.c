#include<stdio.h>
#include<stdlib.h>


int main()
{
    int end,head,i,j,sum=0,s,n,a[20],temp,count=0,d,l,flag;
    printf("Enter the end of the disk: ");
    scanf("%d",&end);
    printf("Enter the disk head position: ");
    scanf("%d",&head);
    printf("Enter no of cylinder postions: ");
    scanf("%d",&n);
    printf("Enter disk position between 0 and %d\n",end);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<=head)
            count++;
    }
    for(i=0;i<n;i++)
	    for(j=0;j<n-1-i;j++)
		    {
		    	if(a[j]>a[j+1])
		    		{
		    		temp=a[j];
		    		a[j]=a[j+1];
		    		a[j+1]=temp;
		    		}
		    }
    printf(">%d",head);
    if(count!=n&&count!=0)
    {
        d=head-a[count-1];
        l=a[count]-head;
        if(d<l)
            flag=0;
        else
            flag=1;
        if(flag==0)
        {
            sum+=head+end-a[count];
            i=count-1;
            while(i>=0)
            {
                printf(">%d",a[i--]); 
            }    
            printf(">%d>%d",0,end);
            i=n-1;
            while(i<=count)
            {
                printf(">%d",a[i--]);
            }
        }
        else 
        { 
            sum+=end-head+a[count-1];
            i=count;
            while(i<n)
            {   
                printf(">%d",a[i++]);
            }
            printf(">%d>%d",end,0);
            i=0;
            while(i<count)
            {             
                printf(">%d",a[i++]);
            }
        }
    }
    if(count==n)
    { 
        sum=head-a[0];
        for(i=n-1;i>=0;i--)
            printf(">%d",a[i]);
    }
    if(count==0)
    {
        sum=a[n-1]-head;
        for(i=0;i<n;i++)
            printf(">%d",a[i]);
    }
    printf("\nTotal head movement: %d",sum);
    return 0;
}