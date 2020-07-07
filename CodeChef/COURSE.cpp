#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int r,R;

struct circle{
    double cx,cy,ang,dist[2];

    circle (int x,int y){
        cx=x;
        cy=y;
        ang=atan2(x,y);
        dist[0]=sqrt(x*x+y*y)-r;
        dist[1]=R-sqrt(x*x+y*y);
    }

    bool operator < (circle const &a) const{
        return ang<a.ang;
    }
};

vector<circle> all;
int memo[505][2];

bool check(double &D,int idx,bool dir){
    if(idx==all.size()-1)
        return true;
    if(memo[idx][dir]!=-1)
        return memo[idx][dir];
    if(D>all[idx].dist[dir])
        return memo[idx][dir]=0;
    if(check(D,idx+1,dir))
        return memo[idx][dir]=1;
    double dx=fabs(all[idx+1].cx-all[idx].cx);
    double dy=fabs(all[idx+1].cy-all[idx].cy);
    double dist=sqrt(dx*dx+dy*dy);
    if(dist>D)
        return memo[idx][dir]=check(D,idx+1,!dir);
    return memo[idx][dir]=0;
}

bool valid(double target){
    return check(target,0,0) | check(target,0,1);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y,n;
        all.clear();
        scanf("%d%d",&r,&R);
        scanf("%d",&n);
        if(!n){
            printf("%.3f\n",R-r);
            continue;
        }
        while(n--){
            scanf("%d%d",&x,&y);
            all.push_back(circle(x,y));
        }
        sort(all.begin(),all.end());
        all.push_back(all[0]);
        double start=0,interval=R-r,mid;
        for(;interval>EPS;interval*=0.5){
            memset(memo,-1,sizeof memo);
            mid=(start+interval)/2;
            if(valid(mid))
                start+=interval;
        }
        printf("%.3f\n",mid);
    }
    return 0;
}
