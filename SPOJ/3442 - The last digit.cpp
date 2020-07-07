#include<cstdio>
#include<vector>

using namespace std;

main()
{
    int a,t,b,c,x;
    vector<int> ld;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(b==0)
        {
            printf("1\n");
            continue;
        }
        else
        {
            ld.clear();
            c=0;
            x=a%10;
            do
            {
                ld.push_back(x);
                x=(x*a)%10;
                c++;
            } while(x!=ld[0]);
            printf("%d\n",ld[(b-1)%c]);
        }
    }
    return 0;
}
