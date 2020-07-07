#include<bits/stdc++.h>

using namespace std;

struct treasure{
    int val;
    long long idx;
}all[100005];

bool operator < (const treasure &a,const treasure &b){
    if(a.val!=b.val) return a.val>b.val;
    return a.idx<b.idx;
}

int main(){
    int n,m,k,t;
    long long h,x;
    set<treasure> reachable;
    treasure temp;
    set<long long> steps;
    scanf("%I64d%d%d%d",&h,&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%I64d%d",&all[i].idx,&all[i].val);
        all[i].idx--;
        if(all[i].idx%k==0){
            temp.idx=i;
            temp.val=all[i].val;
            reachable.insert(temp);
            steps.insert(all[i].idx);
        }
    }
    for(set<long long>::iterator it=steps.begin();it!=steps.end();it++)
        printf("%lld ",*it+1);
    printf("\n");
    for(int i=0;i<m;i++){
        scanf("%d",&t);
        if(t==1){
            scanf("%I64d",&x);
            vector<long long> add;
            for(set<long long>::iterator it=steps.begin();it!=steps.end();it++)
                add.push_back(*it+x);
            for(int j=0;j<add.size();j++)
                steps.insert(add[j]);
            for(set<long long>::iterator it=steps.begin();it!=steps.end();it++)
                printf("%lld ",*it+1);
            printf("\n");
            for(int j=0;j<n;j++){
                if(steps.count(all[j].idx)){
                    temp.idx=j;
                    temp.val=all[j].val;
                    reachable.insert(temp);
                }
            }
        }else if(t==2){
            scanf("%I64d%d",&x,&k);
            --x;
            temp.idx=x;
            temp.val=all[x].val;
            set<treasure>::iterator it=reachable.lower_bound(temp);
            all[x].val-=k;
            if(it==reachable.end() || it->idx!=x)
                continue;
            reachable.erase(it);
            temp.val=all[x].val;
            reachable.insert(temp);
        }else{
            temp=*reachable.begin();
            printf("%d\n",temp.val);
            all[temp.idx].val=temp.val=0;
            reachable.erase(reachable.begin());
            reachable.insert(temp);
        }
    }
    return 0;
}
