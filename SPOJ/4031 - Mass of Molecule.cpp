#include<cstdio>
#include<cstring>
#include<map>
#include<vector>

using namespace std;

map<char,int> val;
map<int,int> pos;
char in[105];

int get_val(int s,int e){
    int ans=0,temp=0;
    while(e>=s){
        if(in[e]>='2' && in[e]<='9'){
            temp=(in[e]-'0');
            e--;
            continue;
        }
        if(in[e]==')'){
            if(temp>0){
                ans+=temp*get_val(pos[e]+1,e-1);
                temp=0;
            }else{
                ans+=get_val(pos[e]+1,e-1);
            }
            e=pos[e]-1;
            continue;
        }
        if(temp>0){
            ans+=temp*val[in[e]];
            temp=0;
        }else
            ans+=val[in[e]];
        e--;
    }
    return ans;
}

int main(){
    val['H']=1,val['C']=12,val['O']=16;
    int i,len;
    vector<int> open;
    scanf("%s",in);
    len=strlen(in);
    for(i=0;i<len;i++){
        if(in[i]=='(')
            open.push_back(i);
        if(in[i]==')'){
            pos[i]=open[open.size()-1];
            open.pop_back();
        }
    }
    printf("%d\n",get_val(0,len-1));
	return 0;
}
