#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,ans=0;
    cin>>x;
    while(x>0){
        ans++;
        x>>=1;
    }
    cout<<ans<<endl;
    return 0;
}

