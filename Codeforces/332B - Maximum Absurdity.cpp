#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<utility>

using namespace std;

typedef struct segment{
    int a;
    long long sum;
}segment;

int n,k,val[200000],i;
long long sum[200000];
segment temp,segments[200000];

bool cmp(const segment &a,const segment &b){
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    return a.a<b.a;
}

long long getsum(int j){
    int c=j+1;
    while(abs(segments[j].a-segments[c].a)<k)
        c++;
    return segments[j].sum+segments[c].sum;
}

int main(){
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&val[i]);
    sum[0]=0;
    for(i=0;i<n;i++)
        sum[i+1]=val[i]+sum[i];
    for(i=0;i<n-k+1;i++){
        temp.a=i+1;
        temp.sum=sum[i+k]-sum[i];
        segments[i]=temp;
    }
    sort(segments,segments+n-k,cmp);
    i=0;
    int j;
    long long maxi=0;
    pair<int,int> ans;
    for(i=0;i<n-k+1;i++){
        for(j=i+1;j<n-k+1;j++){
            if(segments[i].sum+segments[j].sum>maxi && abs(segments[i].a-segments[j].a)>=k){
                maxi=segments[i].sum+segments[j].sum;
                ans=make_pair(segments[i].a,segments[j].a);
            }
        }
    }
    printf("%d %d\n",ans.first,ans.second);
    return 0;
}
