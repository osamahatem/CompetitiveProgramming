#include<cstdio>
#include<cstring>

char in[50010];

bool check(int s1,int e1,int s2){
    for(int i=s1;i<=e1;i++)
        if(in[i]!=in[s2+i-s1])
            return false;
    return true;
}

int main(){
    int t,T,len,ans=0,st,l,ed;
    bool flag;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%s",in);
        len=strlen(in);
        st=0,ed=len-1,ans=0;
        for(;st<len/2;){
            flag=0;
            for(l=st;l<len/2;l++){
                if(check(st,l,ed+st-l)){
                    flag=1;
                    break;
                }
            }
            if(flag){
                ans+=2;
                ed=ed+st-l-1;
                st=l+1;
                continue;
            }else
                break;
        }
        if(!flag || len%2==1)
            ans++;
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
