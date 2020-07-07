#include<cstdio>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    int n,i,x,ret=0;
    multiset<int> in,vis;
    multiset<int>::iterator it,it2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        in.insert(x);
        vis.insert(x);
    }
    while(vis.size()>0 && in.size()>0){
        it=vis.end();
        it--;
        it2=in.upper_bound((*it)/2);
        if(it2==in.begin())
            break;
        it2--;
        in.erase(it2);
        it2=vis.upper_bound((*it)/2);
        it2--;
        vis.erase(it);
        if(vis.size()==0)
            break;
        ret++;
        vis.erase(it2);
    }
    printf("%d\n",n-ret);
    return 0;
}
