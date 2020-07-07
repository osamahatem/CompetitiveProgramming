#include<stdio.h>
#include<math.h>

main()
{
    int p,c=0,i,j,val,flag=0;
    scanf("%d",&p);
    for(i=1;i<p;i++)
    {
        flag=0;
        for(j=1;j<p-1;j++)
        {
            val=pow(i,j)-1;
            if(val%p==0)
            {
                flag=1;
                break;
            }
        }
        val=pow(i,p-1)-1;
        if(flag==0 && val%p==0)
        {
            c++;
        }
    }
    printf("%d\n",c);
}
