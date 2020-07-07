#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int main(){
    int n,i,k,a;
    vector< pair<int,int> > all;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&k,&a);
        all.push_back(make_pair(k,a));
    }
    sort(all.begin(),all.end());
    for(i=1;i<n;i++){
        k=all[i-1].first;
        a=all[i-1].second;
        while(k<all[i].first && a>all[i].second){
            k++;
            a=a/4+(a%4!=0);
        }
        all[i].second=max(a,all[i].second);
    }
    k=all[i-1].first;
    a=all[i-1].second;
    while(a>4){
        k++;
        a=a/4+(a%4!=0);
    }
    printf("%d\n",k+1);
    return 0;
}
