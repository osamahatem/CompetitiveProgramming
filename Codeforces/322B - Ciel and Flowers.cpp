#include<cstdio>
#include<algorithm>

using namespace std;

int way1(int x,int y,int z){
    int n=0,mini;
    n+=x/3+y/3+z/3;
    x%=3;
    y%=3;
    z%=3;
    mini=min(x,min(y,z));
    n+=mini;
    return n;
}

int way2(int x,int y,int z){
    int n=0,mini;
    mini=min(x,min(y,z));
    n+=mini;
    x-=mini;
    y-=mini;
    z-=mini;
    n+=x/3+y/3+z/3;
    return n;
}

int main(){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    printf("%d\n",max(way1(x,y,z),way2(x,y,z)));
    return 0;
}
