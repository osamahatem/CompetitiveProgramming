/*
ID: 19semse1
PROG: numtri
LANG: C++
*/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX=500500;

int n,num[MAX],memo[MAX];

int largest_sum(int row, int idx){
    if(idx>=n)
        return 0;
    if(memo[idx]!=-1)
        return memo[idx];
    return memo[idx]=num[idx]+max(largest_sum(row+1,idx+row),largest_sum(row+1,idx+row+1));
}

int main(){
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    memset(memo,-1,sizeof memo);
    int r,i;
    scanf("%d",&r);
    n=r*(r+1)/2;
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    printf("%d\n",largest_sum(1,0));
	return 0;
}
