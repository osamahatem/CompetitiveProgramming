#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("c2.in","r",stdin);
    freopen("c2.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        set<int> vis;
        int n,x;
        bool flag=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            if(vis.count(x))
                continue;
            if(flag)
                cout<<" ";
            flag=1;
            vis.insert(x);
            cout<<x;
        }
        cout<<endl;
    }
    return 0;
}
