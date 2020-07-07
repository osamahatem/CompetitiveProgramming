#include<bits/stdc++.h>

using namespace std;

int n;

string toString(int x){
    string ret="";
    while(x){
        ret+=(x%10)+'0';
        x/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

void solve(int last,int left,string out){
    if(!left){
        cout<<out<<endl;
        return;
    }
    if(left<n)
        out+="+";
    for(int i=min(last,left);i>0;i--)
        solve(i,left-i,out+toString(i));
    return;
}

int main(){
    cin>>n;
    solve(n,n,"");
    return 0;
}
