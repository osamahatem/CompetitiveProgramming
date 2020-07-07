#include<cstdio>
#include<algorithm>

using namespace std;

int n,num[100000];

int getmax(int i,int bing){
    if(i==n)
        return 0;
    int ret=0;
    if(num[i]==bing){
        if(bing==999)
            ret=3;
        else
            ret=1;
    }
    return max(ret+getmax(i+1,bing),getmax(i+1,num[i]));
}

int main(){
    int i;
    while(scanf("%d",&n)!=EOF,n!=0){
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        printf("%d\n",getmax(1,num[0]));
    }
	return 0;
}
