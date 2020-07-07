/*
ID: 19semse1
PROG: milk3
LANG: C++
*/

#include<cstdio>
#include<cstring>
#include<cstdio>
#include<set>

using namespace std;

bool memo[20][20][20];
set<int> ans;
set<int>::iterator i;
int a,b,c;

void getpos(int cura,int curb,int curc){
    if(memo[cura][curb][curc])
        return;
    memo[cura][curb][curc]=1;
    if(cura==0)
        ans.insert(curc);
    int mini;
    mini=min(cura,b-curb);
    getpos(cura-mini,curb+mini,curc);
    mini=min(cura,c-curc);
    getpos(cura-mini,curb,curc+mini);
    mini=min(curb,a-cura);
    getpos(cura+mini,curb-mini,curc);
    mini=min(curb,c-curc);
    getpos(cura,curb-mini,curc+mini);
    mini=min(curc,a-cura);
    getpos(cura+mini,curb,curc-mini);
    mini=min(curc,b-curb);
    getpos(cura,curb+mini,curc-mini);
    return;
}

int main(){
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    memset(memo,0,sizeof(memo));
    scanf("%d%d%d",&a,&b,&c);
    getpos(0,0,c);
    for(i=ans.begin();i!=ans.end();i++){
        if(i!=ans.begin())
            printf(" ");
        printf("%d",*i);
    }
    printf("\n");
    return 0;
}
