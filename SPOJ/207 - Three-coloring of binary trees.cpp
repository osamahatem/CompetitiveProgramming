#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

char in[10005];
int cur_idx;
vector<int> tree[10005];
pair<int,int> memo[10005][3];

void build_tree(int cur_node){
    memo[cur_node][0]=make_pair(-1,-1);
    memo[cur_node][1]=make_pair(-1,-1);
    memo[cur_node][2]=make_pair(-1,-1);
    tree[cur_node].clear();
    int num_child=in[cur_idx]-'0';
    while(num_child--){
        tree[cur_node].push_back(++cur_idx);
        build_tree(cur_idx);
    }
}

pair<int,int> get_ans(int idx,char flag){
    if(tree[idx].size()==0){
        if(flag==0)
            return make_pair(1,1);
        return make_pair(0,0);
    }
    if(memo[idx][flag].first!=-1)
        return memo[idx][flag];
    pair<int,int> ret=make_pair(0,100000),temp1,temp2;
    if(flag==0){
        temp1=get_ans(tree[idx][0],1);
        if(tree[idx].size()==2){
            temp2=get_ans(tree[idx][1],2);
            temp1.first+=temp2.first;
            temp1.second+=temp2.second;
        }
        ret.first=max(ret.first,temp1.first);
        ret.second=min(ret.second,temp1.second);
    }
    if(flag==2){
        temp1=get_ans(tree[idx][0],0);
        if(tree[idx].size()==2){
            temp2=get_ans(tree[idx][1],1);
            temp1.first+=temp2.first;
            temp1.second+=temp2.second;
        }
        ret.first=max(ret.first,temp1.first);
        ret.second=min(ret.second,temp1.second);
    }
    if(flag==1){
        temp1=get_ans(tree[idx][0],0);
        if(tree[idx].size()==2){
            temp2=get_ans(tree[idx][1],2);
            temp1.first+=temp2.first;
            temp1.second+=temp2.second;
        }
        ret.first=max(ret.first,temp1.first);
        ret.second=min(ret.second,temp1.second);
    }
    if(flag==0){
        temp1=get_ans(tree[idx][0],2);
        if(tree[idx].size()==2){
            temp2=get_ans(tree[idx][1],1);
            temp1.first+=temp2.first;
            temp1.second+=temp2.second;
        }
        ret.first=max(ret.first,temp1.first);
        ret.second=min(ret.second,temp1.second);
    }
    if(flag==2){
        temp1=get_ans(tree[idx][0],1);
        if(tree[idx].size()==2){
            temp2=get_ans(tree[idx][1],0);
            temp1.first+=temp2.first;
            temp1.second+=temp2.second;
        }
        ret.first=max(ret.first,temp1.first);
        ret.second=min(ret.second,temp1.second);
    }
    if(flag==1){
        temp1=get_ans(tree[idx][0],2);
        if(tree[idx].size()==2){
            temp2=get_ans(tree[idx][1],0);
            temp1.first+=temp2.first;
            temp1.second+=temp2.second;
        }
        ret.first=max(ret.first,temp1.first);
        ret.second=min(ret.second,temp1.second);
    }
    if(flag==0){
        ret.first++;
        ret.second++;
    }
    return memo[idx][flag]=ret;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",in);
        cur_idx=0;
        build_tree(0);
        pair<int,int> ans=make_pair(0,100000),temp;
        temp=get_ans(0,0);
        ans.first=max(ans.first,temp.first);
        ans.second=min(ans.second,temp.second);
        temp=get_ans(0,1);
        ans.first=max(ans.first,temp.first);
        ans.second=min(ans.second,temp.second);
        temp=get_ans(0,2);
        ans.first=max(ans.first,temp.first);
        ans.second=min(ans.second,temp.second);
        printf("%d %d\n",ans.first,ans.second);
    }
	return 0;
}
