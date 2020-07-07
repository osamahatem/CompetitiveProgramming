#include<cstdio>
#include<cstring>
#include<map>
#include<set>

using namespace std;

int main(){
    int k,i;
    int seq[500005];
    set<int> vis;
    seq[0]=0;
    vis.insert(0);
    for(i=1;i<=500000;i++){
        seq[i]=seq[i-1]-i;
        if(seq[i]<0 || vis.count(seq[i]))
            seq[i]+=2*i;
        vis.insert(seq[i]);
    }
    while(scanf("%d",&k),k!=-1){
        printf("%lld\n",seq[k]);
    }
	return 0;
}
