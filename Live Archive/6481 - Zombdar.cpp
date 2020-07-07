#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int tc;
    string s,temp;
    scanf("%d",&tc);
    getline(cin,s);
    while(tc--){
        int t=0;
        temp.clear();
        while(getline(cin,s),s!="END OF CASE"){
            t++;
            for(int i=0;i<s.size();i++){
                temp+=s[i];
                if(s[i]==';'){
                    printf("%d: %s\n",t,temp.c_str());
                    temp.clear();
                }
            }
        }
    }
	return 0;
}
