#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
    int n,m,k,arr[1005][105],i,j,a,c;
    vector<pair<int,int> > ans;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&arr[i][j]);

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(i==j)
                continue;
            c=0;
            for(a=0;a<n;a++){
                if(arr[a][i]>arr[a][j]){
                    if(k==0 && i<j)
                        c++;
                    else if(k==1 && i>j)
                        c++;
                }
            }
            if(c>0)
                ans.push_back(make_pair(i+1,j+1));
        }
    }
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
