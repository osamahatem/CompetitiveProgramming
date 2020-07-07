#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

main()
{
    vector <int> arr;
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    x=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]%x!=0)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",x);
    return 0;
}
