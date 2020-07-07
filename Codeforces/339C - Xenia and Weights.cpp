#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

int main(){
    int m,temp,i,j;
    vector<int> w,sol;
    for(i=1;i<=10;i++){
        scanf("%1d",&temp);
        if(temp==1)
            w.push_back(i);
    }
    int sum1=0,sum2=0;
    scanf("%d",&m);
    int dif=0,last=0;
    for(j=0;j<m;j++){
        printf("%d:\n",j);
        for(i=0;i<w.size();i++){
            printf("\t%d %d %d %d %d\n",sum1,sum2,dif,w[i],last);
            if(w[i]>dif && w[i]!=last){
                if(j%2)
                    sum2+=w[i];
                else
                    sum1+=w[i];
                sol.push_back(w[i]);
                dif=abs(sum2-sum1);
                last=w[i];
                break;
            }
        }
    }
    if(sol.size()!=m){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(i=0;i<sol.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",sol[i]);
    }
    printf("\n");
	return 0;
}
