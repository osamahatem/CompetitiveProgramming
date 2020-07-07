#include<bits/stdc++.h>

using namespace std;

int main(){
    int extra;
    string in;
    cin>>in>>extra;
    if(extra>=(int)in.size()){
        printf("%d\n",(extra+in.size())/2*2);
        return 0;
    }
    int cur_maxi=0;
    for(int len=1;len<=in.size()/2;len++){
        for(int st=0;st+len*2<in.size();st++){
            int temp=st;
            while(temp<st+len && in[temp]==in[temp+len])
                temp++;
            if(temp==st+len)
                cur_maxi=len*2;
        }
    }
    int ans=extra*2;
    int temp=(ans+2)/2;
    while(1){
        int en=(int)in.size()-(temp-extra);
        int st=en-temp;
        if(st<0)
            break;
        while(st<en && st+temp<in.size() && in[st]==in[st+temp])
            st++;
        if(st==en || st+temp==in.size())
            ans=temp*2;
        temp++;
    }
    ans=max(ans,cur_maxi);
    cout<<ans<<endl;
    return 0;
}
