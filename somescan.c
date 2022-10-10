#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int q[20],n,head,i,j,k,seek=0,max,diff,temp,q1[20],q2[20],s[20],
    temp1=0,temp2=0;
    float avg;
    printf("Enter the max range of disk\n");
    scanf("%d",&max);
    printf("Enter the initial head position\n");
    scanf("%d",&head);
    printf("Enter the size of queue request\n");
    scanf("%d",&n);
    printf("Enter the queue of disk positions to be read\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        if(temp>=head)
        {
        q1[temp1]=temp;
        temp1++;
        }
        else
        {
            q2[temp2]=temp;
            temp2++;
        }
    }
    for(i=0;i<temp1-1;i++)
    {
        for(j=i+1;j<temp1;j++)
        {
            if(q1[i]>q1[j])
            {
                temp=q1[i];
                q1[i]=q1[j];
                q1[j]=temp;
            }
        }
    }
    for(i=0;i<temp2-1;i++)
    {
        for(j=i+1;j<temp2;j++)
        {
            if(q2[i]<q2[j])
            {
                temp=q2[i];
                q2[i]=q2[j];
                q2[j]=temp;
            }
        }
    }
    for(i=1,j=0;j<temp1;i++,j++)
        q[i]=q1[j];
        q[i]=max-1;
    for(i=temp1+2,j=0;j<temp2;i++,j++)
        q[i]=q2[j];
        q[i]=0;
        q[0]=head;
    printf("\nRequests are in the order\n");
    for(j=0;j<=n+1;j++)
    {
        diff=abs(q[j+1]-q[j]);
        seek+=diff;
        s[j]=q[j+1];
    }
    printf("%d\t",head);
    for(i=0;i<=n;i++)
    {
        printf("%d\t",s[i]);
    }
    printf("\nTotal seek time is %d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time is %f\n",avg);
    return 0;
}
