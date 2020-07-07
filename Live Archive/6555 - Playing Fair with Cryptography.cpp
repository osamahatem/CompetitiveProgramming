#include<bits/stdc++.h>

using namespace std;

char grid[5][5];
pair<int,int> pos[26];
bool vis[26];

void createGrid(string &key){
    int r=0,c=0;
    for(int i=0;i<key.size();i++){
        if(vis[key[i]-'A'])
            continue;
        vis[key[i]-'A']=1;
        pos[key[i]-'A']=make_pair(r,c);
        grid[r][c]=key[i];
        c++;
        if(c==5)
            c=0,r++;
    }
    for(int i=0;i<26;i++){
        if(vis[i])
            continue;
        vis[i]=1;
        pos[i]=make_pair(r,c);
        grid[r][c]=i+'A';
        c++;
        if(c==5)
            c=0,r++;
    }
    return;
}

void modifyText(string &text){
    int c=0,i;
    string temp="";
    for(i=0;i+1<text.size();i+=2){
        if(c=='J'-'A')
            c++;
        if(text[i]==text[i+1]){
            if(c==text[i]-'A')
                c=(c+1)%26;
            if(c=='J'-'A')
                c++;
            temp+=text[i];
            temp+=c+'A';
            c=(c+1)%26;
            i--;
        }else{
            temp+=text[i];
            temp+=text[i+1];
        }
    }
    if(c=='J'-'A')
        c++;
    if(i==text.size()-1)
        temp+=text[i],temp+=c+'A';
    text=temp;
    return;
}

string cipher(int x,int y){
    string ret="";
    if(pos[x].first==pos[y].first){
        ret+=grid[pos[x].first][(pos[x].second+1)%5];
        ret+=grid[pos[y].first][(pos[y].second+1)%5];
        return ret;
    }
    if(pos[x].second==pos[y].second){
        ret+=grid[(pos[x].first+1)%5][pos[x].second];
        ret+=grid[(pos[y].first+1)%5][pos[y].second];;
        return ret;
    }
    ret+=grid[pos[x].first][pos[y].second];
    ret+=grid[pos[y].first][pos[x].second];
    return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int n,tc=0;
    string key,text,temp;
    scanf("%d%*c",&n);
    while(n--){
        memset(vis,0,sizeof vis);
        vis['J'-'A']=1;
        getline(cin,temp);
        key.clear();
        for(int i=0;i<temp.size();i++)
            if(isalpha(temp[i]))
                key+=toupper(temp[i]);
        getline(cin,temp);
        text.clear();
        for(int i=0;i<temp.size();i++)
            if(isalpha(temp[i]))
                text+=toupper(temp[i]);
        createGrid(key);
        modifyText(text);
        cout<<text<<endl;
        string ans="";
        for(int i=0;i<text.size();i+=2)
            ans+=cipher(text[i]-'A',text[i+1]-'A');
        printf("Case %d: %s\n",++tc,ans.c_str());
    }
	return 0;
}
