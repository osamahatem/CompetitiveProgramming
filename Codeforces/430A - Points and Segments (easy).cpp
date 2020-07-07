#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,colour[105],p[105];
    memset(colour,-1,sizeof colour);
    bool flag=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>p[i];
        colour[p[i]]=2;
    }
    for(int i=0;i<101;i++){
        if(colour[i]==2){
            colour[i]=flag;
            flag=!flag;
        }
    }
    for(int i=0;i<n;i++){
        if(i)
            cout<<" ";
        cout<<colour[p[i]];
    }
    cout<<endl;
    return 0;
}
