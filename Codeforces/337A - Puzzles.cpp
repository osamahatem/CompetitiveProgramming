#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,m,i,puz[50],mini=1000;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d",&puz[i]);
    sort(puz,puz+m);
    for(i=0;i+n-1<m;i++)
        mini=min(mini,puz[i+n-1]-puz[i]);
    printf("%d\n",mini);
	return 0;
}
