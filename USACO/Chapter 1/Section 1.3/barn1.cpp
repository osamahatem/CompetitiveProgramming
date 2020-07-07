/*
ID: 19semse1
PROG: barn1
LANG: C++
*/

#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int m,s,c,temp,i;
    vector<int> stalls_occ,stalls_free;
    scanf("%d%d%d",&m,&s,&c);
    for(i=0;i<c;i++){
        scanf("%d",&temp);
        stalls_occ.push_back(temp);
    }
    sort(stalls_occ.begin(),stalls_occ.end());
    for(i=1;i<c;i++){
        temp=stalls_occ[i]-stalls_occ[i-1]-1;
        stalls_free.push_back(temp);
    }
    sort(stalls_free.begin(),stalls_free.end(),cmp);
    i=0;
    temp=stalls_occ[c-1]-stalls_occ[0]+1;
    while(m>1 && i<stalls_free.size()){
        temp-=stalls_free[i];
        m--;
        i++;
    }
    printf("%d\n",temp);
    return 0;
}
