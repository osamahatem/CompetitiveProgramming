#include<bits/stdc++.h>

using namespace std;

int main(){
    int ans=1000,arr[]={1,1,2,7,4},x;
    for(int i=0;i<5;i++){
        cin>>x;
        ans=min(ans,x/arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}
