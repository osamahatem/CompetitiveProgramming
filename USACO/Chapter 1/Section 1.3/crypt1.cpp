/*
ID: 19semse1
PROG: crypt1
LANG: C++
*/

#include<cstdio>

int n,digits[10],num3[1000],num2[100];

void numgen(){
    int i,j,k,c2=0,c3=0,temp,temp2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            temp=digits[i];
            temp*=10;
            temp+=digits[j];
            num2[c2]=temp;
            c2++;
            for(k=0;k<n;k++){
                temp2=temp*10;
                temp2+=digits[k];
                num3[c3]=temp2;
                c3++;
            }
        }
    }
}

bool ispresent(int a){
    int i;
    for(i=0;i<n;i++)
        if(a==digits[i])
            return true;
    return false;
}

bool isvalid(int a){
    while(a>0){
        if(!ispresent(a%10))
            return false;
        a/=10;
    }
    return true;
}

int main(){
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    int i,j,sol=0,a,b,flag;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&digits[i]);
    numgen();
    for(i=0;i<n*n*n;i++){
        for(j=0;j<n*n;j++){
            flag=0;
            a=num3[i]*(num2[j]%10);
            b=num3[i]*(num2[j]/10);
            if(a>999 || b>999 || a+b*10>9999)
                flag=1;
            if(!isvalid(a) || !isvalid(b) || !isvalid(a+b*10))
                flag=1;
            if(!flag)
                sol++;
        }
    }
    printf("%d\n",sol);
    return 0;
}
