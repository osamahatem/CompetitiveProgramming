#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int gcd(int x,int y){
    if(y==0)
        return x;
    return gcd(y,x%y);
}

int main(){
    int n,maxi,i,j,num[100],read,c,total;
    char temp[200000];
    scanf("%d\n",&n);
    while(n--){
        gets(temp);
        c=0;
        i=0;
        maxi=0;
        while(sscanf(temp+c,"%d%n",&j,&read)!=EOF){
            c+=read;
            num[i]=j;
            i++;
        }
        total=i;
        for(i=0;i<total;i++){
            for(j=i+1;j<total;j++){
                maxi=max(maxi,gcd(num[i],num[j]));
            }
        }
        printf("%d\n",maxi);
    }
    return 0;
}
