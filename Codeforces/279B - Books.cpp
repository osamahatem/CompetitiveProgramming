#include<stdio.h>

main()
{
    long t,sum=0;
    int n,a[100000],i,j=0,books=0,c=0;
    scanf("%d %ld",&n,&t);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        c++;
        if(sum>t)
        {
            sum-=a[j];
            j++;
            c--;
        }
        if(c>books)
        {
            books=c;
        }
    }
    printf("%d\n",books);
}
