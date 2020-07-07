#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int i,j,x,n,m,best[100000];
    vector<int> temp,sums;
    while(scanf("%d%d",&n,&m),n!=0){
        sums.clear();
        for(i=0;i<n;i++){
            temp.clear();
            for(j=0;j<m;j++){
                scanf("%d",&x);
                temp.push_back(x);
            }
            for(j=0;j<m;j++){
                best[j]=temp[j];
                if(j>1)
                    best[j]=max(best[j],best[j]+best[j-2]);
                if(j>0)
                    best[j]=max(best[j],best[j-1]);
            }
            sums.push_back(best[m-1]);
        }
        for(i=0;i<n;i++){
                best[i]=sums[i];
                if(i>1)
                    best[i]=max(best[i],best[i]+best[i-2]);
                if(i>0)
                    best[i]=max(best[i],best[i-1]);
        }
        printf("%d\n",best[n-1]);
    }
	return 0;
}
