#include<cstdio>
#include<algorithm>

using namespace std;

int score(char x,char y){
    if(x==y)
        return 1;
    if(x=='S' && y=='P')
        return 2;
    if(x=='P' && y=='S')
        return 0;
    if(x<y)
        return 2;
    return 0;
}

int main(){
    int r,n,i,j,act=0,best=0;
    char p[55],opp[55][55];
    scanf("%d%s%d",&r,p,&n);
    for(i=0;i<n;i++)
        scanf("%s",opp[i]);
    for(i=0;i<r;i++){
        int S=0,R=0,P=0;
        for(j=0;j<n;j++){
            act+=score(p[i],opp[j][i]);
            if(opp[j][i]=='S')
                S++;
            if(opp[j][i]=='R')
                R++;
            if(opp[j][i]=='P')
                P++;
        }
        best+=max(max(S+2*P,R+2*S),P+2*R);
    }
    printf("%d\n%d\n",act,best);
	return 0;
}
