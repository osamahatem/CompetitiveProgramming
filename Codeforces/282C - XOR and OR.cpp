#include<bits/stdc++.h>

using namespace std;

char a[1000005],b[1000005];

int main(){
    scanf("%s%s",a,b);
    int len_a=strlen(a),len_b=strlen(b);
    if(len_a!=len_b){
        printf("NO\n");
        return 0;
    }
    int x=0,y=0;
    for(int i=0;i<len_a;i++){
        x+=a[i]-'0';
        y+=b[i]-'0';
    }
    if(x==0 ^ y==0)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
