#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int main(){
    int n,x,y,i,j;
    bool flag=0;
    vector<pair<int,int> > edges;

    scanf("%d",&n);
    scanf("%d",&y);

    for(i=0;i<n-1;i++){
        scanf("%d",&x);
        edges.push_back(make_pair(min(x,y),max(x,y)));
        y=x;
    }

    for(i=0;i<edges.size();i++)
        for(j=0;j<edges.size();j++)
            if(edges[i].second>edges[j].first && edges[i].second<edges[j].second && edges[i].first<edges[j].first)
                flag=1;

    if(flag)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
