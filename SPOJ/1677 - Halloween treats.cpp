#include<cstdio>
#include<vector>

using namespace std;

int c,n,seq[100000];
bool flag;
vector<int> sol;

void getans(int i,int sum){
    if(sum==0 && i!=0){
        flag=1;
        return;
    }
    if(flag)
        return;
    if(i>=n)
        return;
    sol.push_back(i+1);
    getans(i+1,(sum+seq[i])%c);
    if(flag)
        return;
    sol.pop_back();
    getans(i+1,sum);
    return;
}

int main(){
    int i,x;
    while(scanf("%d%d",&c,&n),c!=0 && n!=0){
        for(i=0;i<n;i++){
            scanf("%d",&x);
            seq[i]=x%c;
        }
        flag=0;
        sol.clear();
        getans(0,0);
        if(flag){
            for(i=0;i<sol.size();i++){
                if(i>0)
                    printf(" ");
                printf("%d",sol[i]);
            }
        }else
            printf("no sweets");
        printf("\n");
    }
	return 0;
}
