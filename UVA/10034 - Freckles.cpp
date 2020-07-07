#include<bits/stdc++.h>

using namespace std;

struct edge{
    int f,t;
    double c;

    bool operator < (const edge &e) const{
        return c<e.c;
    }
};

struct disjointSet{
    vector<int> par,rank;

    disjointSet(int n){
        par.resize(n),rank.resize(n);
        for(int i=0;i<n;i++)
            par[i]=i,rank[i]=1;
    }

    int operator [] (int node){
        return par[node] = (par[node]==node) ? node : (*this)[par[node]];
    }

    bool operator () (int x,int y){
        x=(*this)[x];
        y=(*this)[y];
        if(x==y)
            return false;
        if(rank[x]<rank[y])
            swap(x,y);
        if(rank[x]==rank[y])
            rank[x]++;
        par[y]=x;
        return true;
    }
};

int n,m;
edge edges[10001];
double x[101],y[101];

double kruskal(){
    double ret=0;
    sort(edges,edges+m);
    disjointSet DS(n);
    for(int i=0;i<m;i++)
        if(DS(edges[i].f,edges[i].t))
            ret+=edges[i].c;
    return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        m=0;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&x[i],&y[i]);
            for(int j=0;j<i;j++)
                edges[m++]= edge {i,j,hypot(x[i]-x[j],y[i]-y[j])};
        }
        printf("%.2f\n%s",kruskal(),t ? "\n" : "");
    }
	return 0;
}
