#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("A. Magic Trick.in","r",stdin);
    freopen("A. Magic Trick.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int a,x,first[4],second[4],c=0;
        scanf("%d",&a);
        a--;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&x);
                if(i==a)
                    first[j]=x;
            }
        }
        scanf("%d",&a);
        a--;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&x);
                if(i==a)
                    second[j]=x;
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(first[i]==second[j]){
                    c++;
                    x=first[i];
                }
            }
        }
        printf("Case #%d: ",t);
        if(c==1)
            printf("%d\n",x);
        if(c==0)
            printf("Volunteer cheated!\n");
        if(c>1)
            printf("Bad magician!\n");
    }
    return 0;
}
