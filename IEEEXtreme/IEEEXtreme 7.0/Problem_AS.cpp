#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int target,roads=0,ans_length=1<<30;
bool vis[26];
string ans;
vector<int> g[26];

void DFS(int cur,int length,string temp){
    if(cur==target){
        roads++;
        temp+=(char)(cur+'A');
        if(length<ans_length){
            ans_length=length;
            ans=temp;
        }
        if(length==ans_length && temp<ans)
            ans=temp;
        return;
    }

    vis[cur]=1;
    string add;
    for(int i=0;i<g[cur].size();i++){
        if(!vis[g[cur][i]]){
            add="";
            add+=(char)(cur+'A');
            add+=" ";
            DFS(g[cur][i],length+1,temp+add);
        }
    }
    vis[cur]=0;
    return;
}

int main(){
    int a,b;
    char x,y;

    memset(vis,0,sizeof vis);

    scanf("%c\n",&x);
    target=x-'A';

    while(scanf("%c %c\n",&x,&y),x!='A' && y!='A'){
        a=x-'A';
        b=y-'A';
        g[a].push_back(b);
        g[b].push_back(a);
    }

    DFS('F'-'A',1,"");

    if(ans_length==1<<30){
        printf("No Route Available from %c to %c\n",'F',target+'A');
        return 0;
    }

    printf("Total Routes: %d\n",roads);
    printf("Shortest Route Length: %d\n",ans_length);
    printf("Shortest Route after Sorting of Routes of length %d: %s\n",ans_length,ans.c_str());

    return 0;
}
