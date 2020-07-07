#include<bits/stdc++.h>

using namespace std;

struct edge{
    int u,v,c;

    edge(int u,int v,int c) : u(u),v(v),c(c) {}

    bool operator < (const edge &t) const{
        return c<t.c;
    }
};

struct disjointSet{
    vector<int> root,depth;

    disjointSet(int n){
        for(int i=0;i<=n;i++){
            root.push_back(i);
            depth.push_back(0);
        }
    }

    int getSet(int p){
        if(p!=root[p])
            root[p]=getSet(root[p]);
        return root[p];
    }

    bool mergeSets(int a,int b){
        int sa=getSet(a);
        int sb=getSet(b);
        if(sa==sb)
            return false;
        if(depth[sa]<depth[sb])
            root[sa]=sb;
        else
            root[sb]=sa;
        if(depth[sa]==depth[sb])
            depth[sa]++;
        return true;
    }
};

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n){
        vector<edge> E;
        int u,v,c;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&c);
            E.push_back(edge(u,v,c));
        }
        sort(E.begin(),E.end());
        disjointSet DS(n);
        bool flag=0;
        for(int i=0;i<E.size();i++){
            if(!DS.mergeSets(E[i].u,E[i].v)){
                if(flag)
                    printf(" ");
                printf("%d",E[i].c);
                flag=1;
            }
        }
        if(!flag)
            printf("forest");
        printf("\n");
    }
    return 0;
}
