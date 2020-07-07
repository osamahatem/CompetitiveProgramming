#include<cstdio>

int main(){
    int s[12],k,c1,c2,c3,c4,c5,c6;
    bool flag=0;
    while(1){
        scanf("%d",&k);
        if(k==0)
            break;
        if(flag)
            printf("\n");
        else
            flag=1;
        for(c1=0;c1<k;c1++)
            scanf("%d",&s[c1]);
        for(c1=0;c1<=k-6;c1++)
            for(c2=c1+1;c2<=k-5;c2++)
                for(c3=c2+1;c3<=k-4;c3++)
                    for(c4=c3+1;c4<=k-3;c4++)
                        for(c5=c4+1;c5<=k-2;c5++)
                            for(c6=c5+1;c6<=k-1;c6++)
                                printf("%d %d %d %d %d %d\n",s[c1],s[c2],s[c3],s[c4],s[c5],s[c6]);
    }
    return 0;
}
