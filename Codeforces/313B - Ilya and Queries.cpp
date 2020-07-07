#include<cstdio>
#include<cstring>

int main(){
    int i,len,c=0,counter[100000],m,l,r;
    char str[100010];
    counter[0]=0;
    gets(str);
    len=strlen(str);
    for(i=0;i<len-1;i++){
        if(str[i]==str[i+1]) c++;
        counter[i+1]=c;
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        printf("%d\n",counter[r-1]-counter[l-1]);
    }
    return 0;
}
