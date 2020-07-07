#include<cstdio>
#include<algorithm>
#include<set>
#include<utility>
#include<vector>

using namespace std;

int main(){
    int i,x,y;
    set<int> xs,ys;
    set<pair<int,int> > pt;
    vector<pair<int,int> > pts;
    for(i=0;i<8;i++){
        scanf("%d%d",&x,&y);
        xs.insert(x);
        ys.insert(y);
        pt.insert(make_pair(x,y));
        pts.push_back(make_pair(x,y));
    }
    if(xs.size()!=3 || ys.size()!=3 || pt.size()!=8){
        printf("ugly\n");
        return 0;
    }
    int maxix=0,maxiy=0,minix=1000000,miniy=1000000;
    for(i=0;i<8;i++){
        maxix=max(maxix,pts[i].first);
        maxiy=max(maxiy,pts[i].second);
        minix=min(minix,pts[i].first);
        miniy=min(miniy,pts[i].second);
    }
    int medx,medy;
    for(i=0;i<8;i++){
        if(pts[i].first<maxix && pts[i].first>minix)
            medx=pts[i].first;
        if(pts[i].second<maxiy && pts[i].second>miniy)
            medy=pts[i].second;
    }
    for(i=0;i<8;i++)
        if(pts[i].first==medx && pts[i].second==medy){
            printf("ugly\n");
            return 0;
        }
    printf("respectable\n");
    return 0;
}
