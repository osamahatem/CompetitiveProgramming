#include<bits/stdc++.h>

using namespace std;

int n[2],t[2][1005];
bool ut[2];

void insertTable(int x){
    bool flag=0;
    while(t[flag][x%n[flag]]!=-1){
        swap(x,t[flag][x%n[flag]]);
        flag=!flag;
    }
    t[flag][x%n[flag]]=x;
    ut[flag]=1;
    return;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int m,tc=0;
    while(scanf("%d%d%d",&n[0],&n[1],&m),n[0]){
        vector<int> num;
        num.resize(m);
        memset(t,-1,sizeof t);
        ut[0]=ut[1]=0;
        while(m--)
            scanf("%d",&num[num.size()-1-m]);
        for(int i=0;i<num.size();i++)
            insertTable(num[i]);
        printf("Case %d:\n",++tc);
        if(ut[0]){
            printf("Table 1\n");
            for(int i=0;i<n[0];i++)
                if(t[0][i]!=-1)
                    printf("%d:%d\n",i,t[0][i]);
        }
        if(ut[1]){
            printf("Table 2\n");
            for(int i=0;i<n[1];i++)
                if(t[1][i]!=-1)
                    printf("%d:%d\n",i,t[1][i]);
        }
    }
	return 0;
}
