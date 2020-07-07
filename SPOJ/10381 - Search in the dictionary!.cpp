#include<cstdio>
#include<algorithm>
#include<set>
#include<string>
#include<vector>

using namespace std;

bool isprefix(string &a,string &b){
    if(b.size()<a.size())
        return false;
    for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])
            return false;
    return true;
}

int main(){
    int n,i,k,s;
    char in[25];
    set<string> temp;
    set<string>::iterator it;
    vector<string> dict;
    string t;
    bool flag;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",in);
        temp.insert((string)in);
    }
    for(it=temp.begin();it!=temp.end();it++)
        dict.push_back(*it);
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        flag=0;
        printf("Case #%d:\n",i);
        scanf("%s",in);
        t=(string)in;
        s=(int)(lower_bound(dict.begin(),dict.end(),t)-dict.begin());
        while(s<dict.size() && isprefix(t,dict[s])){
            if(t.size()<dict[s].size()){
                flag=1;
                printf("%s\n",dict[s].c_str());
            }
            s++;
        }
        if(!flag)
            printf("No match.\n");
    }
	return 0;
}
