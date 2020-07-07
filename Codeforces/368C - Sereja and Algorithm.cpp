#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    int len,cnt[100010][3],cntx=0,cnty=0,cntz=0,i,m,l,r,maxi,mini;
    char in[100010];
    scanf("%s",in);
    len=strlen(in);
    cnt[0][0]=cnt[0][1]=cnt[0][2]=0;

    for(i=0;i<len;i++){
        if(in[i]=='x')
            cntx++;
        if(in[i]=='y')
            cnty++;
        if(in[i]=='z')
            cntz++;
        cnt[i+1][0]=cntx;
        cnt[i+1][1]=cnty;
        cnt[i+1][2]=cntz;
    }

    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        cntx=cnt[r][0]-cnt[l-1][0];
        cnty=cnt[r][1]-cnt[l-1][1];
        cntz=cnt[r][2]-cnt[l-1][2];
        maxi=max(cntx,max(cnty,cntz));
        mini=min(cntx,min(cnty,cntz));
        if(r-l+1<3 || maxi-mini<2)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
