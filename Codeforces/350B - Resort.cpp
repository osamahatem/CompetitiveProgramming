#include<cstdio>
#include<vector>

using namespace std;

typedef struct node{
    bool type;
    int from,outgoing_count;
}node;

int main(){
    int n,i,x,idx;
    node in[100000];
    vector<int> temp,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        in[i].type=x;
        in[i].outgoing_count=0;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x);
        in[i].from=--x;
        if(x>=0)
            in[x].outgoing_count++;
    }
    for(i=0;i<n;i++){
        if(in[i].type){
            temp.clear();
            temp.push_back(i);
            idx=in[i].from;
            while(in[idx].outgoing_count==1 && !in[idx].type && idx>=0){
                temp.push_back(idx);
                idx=in[idx].from;
            }
            if(temp.size()>ans.size())
                ans=temp;
        }
    }
    printf("%d\n",ans.size());
    for(i=ans.size()-1;i>=0;i--){
        printf("%d",ans[i]+1);
        if(i>0)
            printf(" ");
    }
	return 0;
}
