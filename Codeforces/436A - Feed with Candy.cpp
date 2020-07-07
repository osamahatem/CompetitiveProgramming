#include<bits/stdc++.h>

using namespace std;

struct candy{
    int h,m;

    bool operator < (const candy &a) const{
        return h<a.h;
    }
};

int main(){
    int n,x,t;
    candy temp;
    set<candy> all1[2],all2[2];
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&t,&temp.h,&temp.m);
        all1[t].insert(temp);
        all2[t].insert(temp);
    }
    bool flag=0;
    int ansA=0,ansB=0,xX=x;
    while(all1[0].size() && all1[1].size()){
        if(xX<all1[flag].begin()->h)
            break;
        ansA++;
        xX+=all1[flag].begin()->m;
        all1[flag].erase(all1[flag].begin());
        flag=!flag;
    }
    flag=1,xX=x;
    while(all2[0].size() && all2[1].size()){
        if(xX<all2[flag].begin()->h)
            break;
        ansB++;
        xX+=all2[flag].begin()->m;
        all2[flag].erase(all2[flag].begin());
        flag=!flag;
    }
    printf("%d\n",max(ansA,ansB));
    return 0;
}
