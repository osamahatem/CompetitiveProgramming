#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int t,T,i,maxi,v[10];
    char url[10][105];
    scanf("%d\n",&T);
    for(t=1;t<=T;t++){
        maxi=0;
        for(i=0;i<10;i++){
            scanf("%s%d\n",url[i],&v[i]);
            maxi=max(maxi,v[i]);
        }
        printf("Case #%d:\n",t);
        for(i=0;i<10;i++){
            if(v[i]==maxi){
                printf("%s\n",url[i]);
            }
        }
    }
    return 0;
}
