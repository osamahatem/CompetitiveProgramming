#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[150];
bool flag[150];
int main()
{
    int sch,t,req,id,cb,cc,i,solve,tc=0;
    while(7)
    {
        tc++;
        int teams=0;
        memset(arr,0,sizeof arr);
        memset(flag,0,sizeof flag);
        scanf("%d%d%d",&sch,&t,&req);
        if(!sch && !t && !req)
            return 0;
        for(i=0;i<sch;i++)
        {
            scanf("%d%d%d",&id,&cb,&cc);
            arr[id]+=cb+cc;
            //printf("%d * ",arr[id]);
        }

        for(i=0;i<t;i++)
        {
            scanf("%d%d",&id,&solve);

            if(solve>=req && !flag[id])
            {
               // printf("%d %d %d %d*\n",id,solve,flag[id],req);
                arr[id]++;
                flag[id]=1;
            }

        }
        for(i=0;i<=sch;i++)
            teams+=arr[i];

        printf("Case %d: %d\n",tc,teams);

    }
    return 0;
}
