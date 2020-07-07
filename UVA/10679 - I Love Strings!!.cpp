#include<bits/stdc++.h>

using namespace std;

struct node{
    char c;
    int parent,fail;
    vector<int> endOfWord;
    vector< pair<char,int> > next;
};

int nodeCount;
node trie[1000005];
bool vis[1000005];

void insert(char arr[],int idx){
    int curNode=0,len=strlen(arr);
    for(int i=0;i<len;i++){
        bool there=0;
        for(int j=0;j<trie[curNode].next.size();j++){
            if(trie[curNode].next[j].first==arr[i]){
                there=1;
                curNode=trie[curNode].next[j].second;
                break;
            }
        }
        if(!there){
            node toAdd;
            toAdd.c=arr[i];
            toAdd.parent=curNode;
            toAdd.fail=-1;
            trie[curNode].next.push_back(make_pair(arr[i],++nodeCount));
            curNode=nodeCount;
            trie[nodeCount]=toAdd;
        }
    }
    trie[curNode].endOfWord.push_back(idx);
    return;
}

void getFail(){
    queue<int> Q;
    int temp;
    Q.push(0);
    while(!Q.empty()){
        temp=Q.front();
        Q.pop();
        for(int i=0;i<trie[temp].next.size();i++)
            Q.push(trie[temp].next[i].second);
        if(!temp)
            continue;
        int curNode=trie[trie[temp].parent].fail;
        bool found=0;
        while(curNode!=-1 && !found){
            for(int i=0;i<trie[curNode].next.size();i++){
                if(trie[curNode].next[i].first==trie[temp].c){
                    trie[temp].fail=trie[curNode].next[i].second;
                    found=1;
                    break;
                }
            }
            curNode=trie[curNode].fail;
        }
        if(!found)
            trie[temp].fail=0;
    }
    return;
}

void search(char arr[],bool ans[]){
    int len=strlen(arr),idx=0,curNode=0;
    while(idx<len){
        if(curNode==-1){
            curNode==0;
            idx++;
            continue;
        }
        bool found=0;
        for(int i=0;i<trie[curNode].next.size();i++){
            if(arr[idx]==trie[curNode].next[i].first){
                found=1;
                curNode=trie[curNode].next[i].second;
                idx++;
                break;
            }
        }
        if(!found)
            curNode=trie[curNode].fail;
        if(curNode!=-1 && !vis[curNode]){
            int temp=curNode;
            while(temp!=-1){
                vis[temp]=1;
                for(int i=0;i<trie[temp].endOfWord.size();i++)
                    ans[trie[temp].endOfWord[i]]=1;
                temp=trie[temp].fail;
            }
        }
    }
    return;
}

int main(){
    node root;
    root.parent=root.fail=-1;
    root.next.clear();
    root.endOfWord.clear();
    int T,Q;
    char text[100005],pattern[1005];
    bool ans[1005];
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof vis);
        memset(ans,0,sizeof ans);
        trie[0]=root;
        nodeCount=0;
        scanf("%s%d",text,&Q);
        for(int i=0;i<Q;i++){
            scanf("%s",pattern);
            insert(pattern,i);
        }
        getFail();
        search(text,ans);
        for(int i=0;i<Q;i++)
            if(ans[i])
                printf("y\n");
            else
                printf("n\n");
    }
    return 0;
}
