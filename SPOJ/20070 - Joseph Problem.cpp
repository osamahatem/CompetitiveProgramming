#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=2;i<=n;i++)
        ans=(ans+k)%i;
    cout<<++ans<<endl;
    return 0;
}
