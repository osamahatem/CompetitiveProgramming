#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

vector<int> adj[100005];
vector<pair<int,int> > edg;
int h,t;

void print(int a,int b,vector<int> left,vector<int> right, vector<int> common){
    printf("YES\n%d %d\n",a,b);
    int i=0,c=0,done=0;
    while(i<left.size() && done<h){
        if(left[i]==-1){
            i++;
            continue;
        }
        if(done)
            printf(" ");
        printf("%d",left[i++]);
        done++;
    }
    while(done<h){
        if(done)
            printf(" ");
        printf("%d",common[c++]);
        done++;
    }
    printf("\n");
    i=done=0;
    while(i<right.size() && done<t){
        if(right[i]==-1){
            i++;
            continue;
        }
        if(done)
            printf(" ");
        printf("%d",right[i++]);
        done++;
    }
    while(done<t){
        if(done)
            printf(" ");
        printf("%d",common[c++]);
        done++;
    }
    printf("\n");
    return;
}

bool check(int a,int b){
    vector<int> left,right,common;
    int i,j;
    for(i=0;i<h+t+2 && i<adj[a].size();i++)
        if(adj[a][i]!=b)
            left.push_back(adj[a][i]);
    for(i=0;i<h+t+2 && i<adj[b].size();i++)
        if(adj[b][i]!=a)
            right.push_back(adj[b][i]);
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    i=j=0;
    while(i<left.size() && j<right.size()){
        if(left[i]==right[j]){
            common.push_back(left[i]);
            left[i]=right[j]=-1;
            i++;
            j++;
        }else if(left[i]<right[j])
            i++;
        else
            j++;
    }
    if(left.size()+right.size()-common.size()>=h+t && left.size()>=h && right.size()>=t)
        print(a,b,left,right,common);
    else if(left.size()+right.size()-common.size()>=h+t && left.size()>=t && right.size()>=h)
        print(b,a,right,left,common);
    else
        return false;
    return true;
}

int main(){
    int n,m,a,b,i;
    scanf("%d%d%d%d",&n,&m,&h,&t);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        edg.push_back(make_pair(a,b));
    }
    for(i=0;i<m;i++)
        if(check(edg[i].first,edg[i].second))
            return 0;
    printf("NO\n");
    return 0;
}
