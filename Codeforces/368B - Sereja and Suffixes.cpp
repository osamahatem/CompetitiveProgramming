#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct query{int order,l,ans;};

bool sort_l(const query&a,const query&b){
    return a.l>b.l;
}

bool sort_order(const query&a,const query&b){
    return a.order<b.order;
}

int main(){
    int n,m,i,j,arr[100000],l,tot=0;
    query q[100000];
    bool dis[100005];
    memset(dis,0,sizeof dis);

    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<m;i++){
        scanf("%d",&l);
        q[i].order=i;
        q[i].l=--l;
    }

    sort(q,q+m,sort_l);
    j=n-1;
    for(i=0;i<m;i++){
        while(j>=q[i].l){
            if(dis[arr[j]]==0)
                tot++;
            dis[arr[j]]=1;
            j--;
        }
        q[i].ans=tot;
    }

    sort(q,q+m,sort_order);
    for(i=0;i<m;i++)
        printf("%d\n",q[i].ans);

    return 0;
}
