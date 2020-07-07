#include<bits/stdc++.h>

using namespace std;

void solve(int open,int left,string p){
    if(left==0){
        if(open==0)
            printf("%s\n",p.c_str());
        return;
    }
    solve(open+1,left-1,p+"(");
    if(open>0)
        solve(open-1,left-1,p+")");
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    solve(0,n*2,"");
    return 0;
}
