#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        bool lock[105];
        memset(lock,0,sizeof lock);
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(j%i==0)
                    lock[j]=!lock[j];
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=lock[i];
        cout<<ans<<endl;
    }
    return 0;
}
