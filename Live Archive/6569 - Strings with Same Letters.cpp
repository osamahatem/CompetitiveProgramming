#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

    string a,b;
    int cnt[26],t=0;
    while(cin>>a>>b,a!="END"){
        memset(cnt,0,sizeof cnt);
        bool flag=0;
        for(int i=0;i<a.size();i++)
            cnt[a[i]-'a']++;
        for(int i=0;i<b.size();i++){
            cnt[b[i]-'a']--;
            if(cnt[b[i]-'a']<0)
                flag=1;
        }
        printf("Case %d: %s\n",++t,flag ? "different" : "same");
    }
	return 0;
}
