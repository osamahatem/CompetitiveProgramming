#include<bits/stdc++.h>

using namespace std;

struct point{
    int x,y;

    point (int x,int y) : x(x),y(y) {}
};

struct vec{
    int x,y;

    vec (point a,point b) : x(b.x-a.x),y(b.y-a.y) {}

    int cross(vec a) const{
        return x*a.y-y*a.x;
    }
};

double getArea(point a,point b,point c){
    return 0.5*vec(a,b).cross(vec(b,c));
}

int main(){
    int n,x,y;
    cin>>n;
    cin>>x>>y;
    point first(x,y);
    cin>>x>>y;
    point prev(x,y),cur(x,y);
    double area=0.0;
    for(int i=2;i<n;i++){
        prev=cur;
        cin>>x>>y;
        cur=point(x,y);
        area+=getArea(first,prev,cur);
    }
    printf("%.600f\n",area);
    return 0;
}
