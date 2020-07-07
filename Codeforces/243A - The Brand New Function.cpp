#include<cstdio>
#include<set>

using namespace std;

int main(){
    set<int> ans,events,temp;
    set<int>::iterator it;
    int n,i,a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        temp.clear();
        temp.insert(a);
        for(it=events.begin();it!=events.end();it++)
            temp.insert(a|(*it));
        events=temp;
        ans.insert(events.begin(),events.end());
    }
    printf("%d\n",ans.size());
    return 0;
}
