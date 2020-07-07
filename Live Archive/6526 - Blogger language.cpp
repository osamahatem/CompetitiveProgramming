#include<stdio.h>
#include<string.h>
#include<ctype.h>

char t[6],p[110];

int get_ans(int l,int r,int small){
    int ret=-1,i,j,mis;
    for(i=l;i<=r-small+1;i++){
        mis=0;
        for(j=0;j<small,i+j;j++){
            if(tolower(t[j])!=tolower(p[i+j]))
                break;
            mis+=(t[j]!=p[i+j]);
        }
        if(j==small && mis>ret)
            ret=mis;
    }

    for(i=l;i<=r;i++)
        if(isupper(p[i]))
            p[i]=tolower(p[i]);
        else
            p[i]=toupper(p[i]);

    return ret;
}

int main(){
    int n,small,big,l,r;

    while(scanf("%d",&n)!=EOF){
        scanf("%s %s",t,n);
        small=strlen(t);

        while(n--){
            scanf("%d%d",&l,&r);
            printf("%d\n",get_ans(--l,--r,small));
        }
    }
    return 0;
}
