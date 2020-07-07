#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

struct task{int p,s,t,idx;};

bool operator < (task a,task b){
    return a.p>b.p;
}

bool cmp(task a,task b){
    return a.t<b.t;
}

long long simulate(task all[],int n,int target,long long ending[]){
    long long cur=all[0].t,i=1,ret;
    set<task> Q;
    task temp;
    Q.insert(all[0]);
    while(i<n){
        if(!Q.empty()){
            temp=*(Q.begin());
            Q.erase(Q.begin());
            if(cur+temp.s>all[i].t){
                temp.s-=all[i].t-cur;
                Q.insert(temp);
            }else{
                cur+=temp.s;
                if(temp.p==target)
                    ret=cur;
                ending[temp.idx]=cur;
                continue;
            }
        }
        Q.insert(all[i]);
        cur=all[i++].t;
    }
    while(!Q.empty()){
        temp=*(Q.begin());
        Q.erase(Q.begin());
        if(temp.p==target)
            ret=cur+temp.s;
        cur+=temp.s;
        ending[temp.idx]=cur;
    }
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,target;
    long long ending[50005],T;
    vector<int> possible,priorities;
    task all[50005];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&all[i].t,&all[i].s,&all[i].p);
        all[i].idx=i;
    }
    scanf("%I64d",&T);
    sort(all,all+n,cmp);
    for(i=0;i<n;i++)
        if(all[i].p==-1)
            target=i;
        else
            priorities.push_back(all[i].p);
    sort(priorities.begin(),priorities.end());
    if(priorities[0]>1)
        possible.push_back(1);
    for(i=1;i<priorities.size();i++)
        if(priorities[i]-priorities[i-1]>1)
            possible.push_back(priorities[i]-1);
    possible.push_back(priorities[i-1]+1);
    int lo=0,hi=possible.size()-1,mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        all[target].p=possible[mid];
        long long S=simulate(all,n,all[target].p,ending);
        if(S==T)
            break;
        if(S>T)
            lo=mid+1;
        else
            hi=mid-1;
    }
    printf("%d\n",all[target].p);
    for(i=0;i<n;i++){
        if(i>0)
            printf(" ");
        printf("%I64d",ending[i]);
    }
    printf("\n");
    return 0;
}
