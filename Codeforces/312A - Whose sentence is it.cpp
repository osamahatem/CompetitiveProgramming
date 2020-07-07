#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int n,i,len;
    bool flagf,flagl;
    char in[100],first[6]="miao.",last[6]=".alal";
    scanf("%d",&n);
    gets(in);
    while(n--){
        gets(in);
        flagf=1;
        flagl=1;
        len=strlen(in);
        for(i=0;i<5;i++){
            if(in[i]!=first[i]) flagf=0;
            if(in[len-1-i]!=last[i]) flagl=0;
        }
        if(flagf && !flagl) printf("Rainbow's\n");
        else if(!flagf && flagl) printf("Freda's\n");
        else printf("OMG>.< I don't know!\n");
    }
    return 0;
}
