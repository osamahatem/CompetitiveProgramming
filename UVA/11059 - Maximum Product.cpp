#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

main()
{
    vector<int> arr;
    int t=1,n,i,j,x;
    long long product,maxi;
    while(scanf("%d",&n)!=EOF)
    {
        arr.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            arr.push_back(x);
        }
        maxi=-1;
        for(i=0;i<arr.size();i++)
        {
            product=1;
            for(j=i;j<arr.size();j++)
            {
                product*=arr[j];
                if(product>maxi)
                {
                    maxi=product;
                }
            }
        }
        if(maxi<0)
        {
            maxi=0;
        }
        printf("Case #%d: The maximum product is %lld.\n\n",t,maxi);
        t++;
    }
    return 0;
}
