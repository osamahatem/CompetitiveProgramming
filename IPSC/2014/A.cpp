#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("a2.in","r",stdin);
    freopen("a2.out","w",stdout);
    int t;
    string p,q;
    cin>>t;
    while(t--){
        cin>>p>>q;
        int c=0;
        for(c=0;c<q.size() && c<p.size();c++)
            if(p[c]!=q[c])
                break;
        if(q.size()-c+p.size()-c < p.size()+1){
            for(int i=0;i<q.size()-c;i++)
                cout<<"<";
            printf("%s*\n",p.c_str()+c);
        }else
            printf("*%s*\n",p.c_str());
    }
    return 0;
}
