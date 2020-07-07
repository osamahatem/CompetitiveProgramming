#include<cstdio>
#include<cstring>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char in[100005];
        scanf("%s",in);
        int len=strlen(in),ans[100005],last[26],i;
        ans[0]=1;
        memset(last,-1,sizeof last);
        for(i=1;i<=len;i++){
            ans[i]=ans[i-1]*2;
            ans[i]%=1000000007;
            if(last[in[i-1]-'A']!=-1)
                ans[i]-=ans[last[in[i-1]-'A']-1];
            if(ans[i]<0)
                ans[i]+=1000000007;
            last[in[i-1]-'A']=i;
            ans[i]%=1000000007;
        }
        printf("%d\n",ans[len]);
    }
	return 0;
}
