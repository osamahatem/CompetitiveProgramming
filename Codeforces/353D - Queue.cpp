#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    char in[1000000];
    int len,i,ans=0,f=0,m=0,last=0;
    scanf("%s",in);
    len=strlen(in);
    for(i=0;i<len;i++){
        if(in[i]=='F' && (last>0 || m>0)){
            ans=m+f+last;
            last=ans;
        }
        if(in[i]=='F'){
            f++;
            m=0;
        }
        if(in[i]=='M'){
            m++;
            f=0;
        }
    }
    printf("%d\n",ans);
	return 0;
}
