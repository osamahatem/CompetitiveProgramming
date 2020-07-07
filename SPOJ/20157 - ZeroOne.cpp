#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int t=1;t<=n;t++){
        string a,b;
        cin>>a>>b;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans="";
        int x,y,c=0,z;
        for(int i=0;i<a.size() || i<b.size();i++){
            x=(i>=a.size()) ? 0 : a[i]-'0';
            y=(i>=b.size()) ? 0 : b[i]-'0';
            z=x^y^c;
            c= x&y | x&c | y&c;
            ans+='0'+z;
        }
        if(c)
            ans+="1";
        reverse(ans.begin(),ans.end());
        int s=0;
        while(ans[s]=='0' && s+1<ans.size())
            s++;
        cout<<t<<" "<<ans.substr(s,ans.size()-s)<<endl;
    }
    return 0;
}
