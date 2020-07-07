#include<cstdio>
#include<algorithm>

int n,h[1000];

int getsec(int i){
    int x=i-1,y=i+1;
    while(x>=0 && h[x]<=h[x+1])
        x--;
    while(y<n && h[y]<=h[y-1])
        y++;
    x++;
    y--;
    return y-x+1;
}

using namespace std;

int main(){
    int i,maxi=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&h[i]);
    for(i=0;i<n;i++)
        maxi=max(maxi,getsec(i));
    printf("%d\n",maxi);
    return 0;
}
