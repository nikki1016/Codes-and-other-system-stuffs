#include<stdio.h>

int main()
{
    int len,start,que[20],i,j,dist=0,k,l,temp[20],tque[20],cnt=0,ends,ch;

    printf("\nEnter the length of queue:");
    scanf("%d",&len);
    for(i=1;i<len+1;i++)
    {
        printf("\nEnter the cylinder block %d:",i);
        scanf("%d",&que[i]);
        tque[i]=que[i];
    }
    printf("\nEnter the starting block value:");
    scanf("%d",&que[0]);
    tque[0]=que[0];
    printf("\nEnter the ends of disc block value:");
    scanf("%d",&ends);
    printf("\nHow u want SCAN Algorithm to start from?\n1:Back from start block\n2:Front from start block\nYour choice:");
    scanf("%d",&ch);

    //FCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFS
    printf("\n****************FCFS*************\n\n");
    printf("\nThe blocks visited are as follows->\n\n");

    for(i=0;i<len+1;i++)
    {
        printf("%d ->> ",que[i]);
        if(que[i+1]>que[i] && i+1!=len+1)
        dist+=que[i+1]-que[i];
        else if(tque[i+1]<=tque[i] && (i+1)!=k)
        dist+=que[i]-que[i+1];

    }
    printf("\n\nTotal head movement=%d\n",dist);
    //FCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFSFCFS

    //SSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTF
    dist=0;
    printf("\n****************SSTF*************\n\n");
    printf("\nThe blocks visited are as follows->\n\n");
    for(i=0;i<len+1;i++)
    {
        if(que[i]>que[0])
        temp[i]=que[i]-que[0];
        else
        temp[i]=que[0]-que[i];
    }
    //selection sort
    for(i=0;i<len+1;i++)
    {
        for(j=1;j<len+1-i;j++)
        if(temp[j-1]>temp[j])
        {
            k=temp[j-1];
            l=tque[j-1];
            temp[j-1]=temp[j];
            tque[j-1]=tque[j];
            temp[j]=k;
            tque[j]=l;
        }
    }
    //end of selection sort
     for(i=0;i<len+1;i++)
    {
        printf("%d ->> ",tque[i]);
        if(tque[i+1]>tque[i] && i+1!=len+1)
        dist+=tque[i+1]-tque[i];
        else if(i+1!=len+1)
        dist+=tque[i]-tque[i+1];
        temp[i]=0;

    }
    printf("\n\nTotal head movement=%d\n",dist);
    //SSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTFSSTF

    //SCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCAN
    dist=0;

    //restore value of tque
    for(i=0;i<len+1;i++)
    tque[i]=que[i];

    printf("\n****************SCAN*************\n\n");
    printf("\nThe blocks visited are as follows->\n\n");
    //selection sort
    for(i=0;i<len+1;i++)
    for(j=1;j<len+1-i;j++)
    {
       if(tque[j-1]>tque[j])
       {
         k=tque[j-1];
         tque[j-1]=tque[j];
         tque[j]=k;
       }
    }
    //end of selection sort
    //Reversing que before start block and merging in main tque
    for(i=0;i<len+1;i++)
    {if(tque[i]==que[0]) break;}
    tque[i]=tque[0];
    for(j=1;j<i;j++)
    {
       k=tque[i-j];
       tque[i-j]=tque[j];
       tque[j]=k;
    }
    tque[0]=que[0];
    k=i;
    //end of reverse process
    if(ch==1){
    for(i=0;i<len+1;i++)
    {
        printf("%d ->> ",tque[i]);
        if(tque[i+1]>tque[i] && i+1!=len+1)
        dist+=tque[i+1]-tque[i];
        else if(tque[i+1]<=tque[i] && (i+1)!=k)
        dist+=tque[i]-tque[i+1];
        if(k==i)
        {printf("0 ->> ");dist+=2*tque[i];}

    }
    }
    else
    {
       dist=0;
       printf("%d ->> ",tque[0]);
       dist+=tque[k+1]-tque[0];
       for(i=k+1;i<len+1;i++)
       {
        printf("%d ->> ",tque[i]);
        if(tque[i+1]>tque[i] && i+1!=len+1)
        dist+=tque[i+1]-tque[i];
        else if((i+1)!=len+1)
        dist+=tque[i]-tque[i+1];
       }
       printf("%d ->> ",ends);
       dist+=(ends-tque[len]);
       for(i=1;i<=k;i++)
       {
        dist+=ends-tque[i];
        printf("%d ->> ",tque[i]);
        if(tque[i+1]>tque[i] && (i+1)!=k+1)
        dist+=tque[i+1]-tque[i];
        else if(tque[i+1]<=tque[i] && (i+1)!=k)
        dist+=tque[i]-tque[i+1];
       }
    }
    printf("\n\nTotal head movement=%d\n",dist);
    //SCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCANSCAN

    //LOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOK

    dist=0;
    printf("\n****************LOOK*************\n\n");
    printf("\nThe blocks visited are as follows->\n\n");
    for(i=0;i<len+1;i++)
    {
        printf("%d ->> ",tque[i]);
        if(tque[i+1]>tque[i] && i+1!=len+1)
        dist+=tque[i+1]-tque[i];
        else if(tque[i+1]<=tque[i] && (i+1)!=k)
        dist+=tque[i]-tque[i+1];

    }
    printf("\n\nTotal head movement=%d\n",dist);
    //LOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOKLOOK
    return 0;

}
