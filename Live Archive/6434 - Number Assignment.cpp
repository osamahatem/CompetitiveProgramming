#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t,T,n,m,i,j,x,ans;
    vector<int> num,gap;
    scanf("%d",&T);

    for(t=1;t<=T;t++){
        num.clear();
        gap.clear();

        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&x);
            num.push_back(x);
        }

        sort(num.begin(),num.end());
        for(i=1;i<num.size();i++)
            gap.push_back(num[i]-num[i-1]);
        sort(gap.begin(),gap.end());

        ans=num[n-1]-num[0],j=gap.size()-1;
        for(i=1;i<m;i++)
            ans-=gap[j--];

        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
