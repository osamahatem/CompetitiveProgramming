#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int n,m,p,i,j,x,sub=0,arr[200000],cnt[400005],cnt_temp[400005],flag,rk=0;
vector<int> sub_arr[200000],ans;
map<int,int> rnk;

int main(){
    memset(cnt,0,sizeof cnt);

    scanf("%d%d%d",&n,&m,&p);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        sub_arr[sub].push_back(x);
        sub=(sub+1)%p;
        if(!rnk.count(x))
            rnk[x]=rk++;
    }

    for(i=0;i<m;i++){
        scanf("%d",&arr[i]);
        if(!rnk.count(arr[i]))
            rnk[arr[i]]=rk++;
    }

    for(i=0;i<m;i++){
        arr[i]=rnk[arr[i]];
        cnt[arr[i]]++;
    }

    for(i=0;i<p;i++)
        for(j=0;j<sub_arr[i].size();j++)
            sub_arr[i][j]=rnk[sub_arr[i][j]];

    for(i=0;i<p;i++){
        if(sub_arr[i].size()<m)
            continue;

        flag=0;
        for(j=0;j<rk;j++)
            cnt_temp[j]=0;
        for(j=0;j<m;j++)
            cnt_temp[sub_arr[i][j]]++;
        for(j=0;j<rk;j++){
            if(cnt_temp[j]<cnt[j])
                flag++;
        }
        if(flag==0)
            ans.push_back(i+1);
        cnt_temp[sub_arr[i][0]]--;
        if(cnt[sub_arr[i][0]]-cnt_temp[sub_arr[i][0]]==1)
            flag++;

        for(j=m;j<sub_arr[i].size();j++){
            cnt_temp[sub_arr[i][j]]++;
            if(cnt_temp[sub_arr[i][j]]==cnt[sub_arr[i][j]])
                flag--;
            if(flag==0)
                ans.push_back((j-m+1)*p+i+1);
            cnt_temp[sub_arr[i][j-m+1]]--;
            if(cnt[sub_arr[i][j-m+1]]-cnt_temp[sub_arr[i][j-m+1]]==1)
                flag++;
        }
    }

    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");

    return 0;
}
