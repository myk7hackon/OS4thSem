#include<stdio.h>
#include<stdlib.h>
int s,sz,n,a[100];


int main(void)
{
    int x,c,i,i1,hd=0,i0;
    printf("Specify the size of the cylinder: ");
    scanf("%d",&sz);
    printf("Specify the number of positions: ");
    scanf("%d",&n);
    printf("Specify the Queue: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Specify the current head position: ");
    scanf("%d",&s);
    //CSCAN
    printf("CSCAN:\n");
    for(i=0;i<n;i++)
        if(a[i]>=s)
            break;
    i1=i;
    if(a[i1]==s)    i1++;
    printf("%d ",s);
    for(--i;i>=0;i--)
        printf("%d ",a[i]);
    printf("0 ");
    for(i=i1;i<n;i++)
        printf("%d ",a[i]);
    printf("%d ",sz-1);
    printf("\nTotal Head Movement = %d\n\n",sz-1-abs(a[i1]-s));
    return 0;
}
