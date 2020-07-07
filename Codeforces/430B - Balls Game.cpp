#include<bits/stdc++.h>

using namespace std;

int check(vector<int> b,int p,int x){
    int s=p,e=p;
    while(b[s]==x)
        s--;
    while(b[e]==x)
        e++;
    if(e-s-1<2)
        return 0;
    int ans=e-s-1;
    while(b[e]!=0 && b[s]!=0){
        int count=0;
        x=b[e];
        while(b[e]==x){
            count++;
            e++;
        }
        while(b[s]==x){
            count++;
            s--;
        }
        if(count<3)
            return ans;
        ans+=count;
    }
    return ans;
}

int main(){
    int n,k,x,t,maxi=0;
    vector<int> balls;
    balls.push_back(0);
    cin>>n>>k>>x;
    for(int i=0;i<n;i++){
        cin>>t;
        balls.push_back(t);
    }
    balls.push_back(0);
    for(int i=0;i<n;i++){
        if(balls[i]==x)
            maxi=max(maxi,check(balls,i,x));
    }
    cout<<maxi<<endl;
    return 0;
}
