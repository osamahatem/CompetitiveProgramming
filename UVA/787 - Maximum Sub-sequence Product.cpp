#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct BigInteger{
    vector<int> num;
    int sign;
}BigInteger;

void print_BigInteger(const BigInteger &a){
    if(a.sign==-1)
        printf("-");
    for(int i=a.num.size()-1;i>=0;i--)
        printf("%d",a.num[i]);
    printf("\n");
    return;
}

void multiply_BigInteger(const BigInteger &a,const BigInteger &b,BigInteger &res){
    res.sign=a.sign*b.sign;
    res.num.clear();
    int i,j,t,carry;
    for(i=0;i<a.num.size();i++){
        carry=0;
        for(j=0;j<b.num.size();j++){
            if(i+j==res.num.size())
                res.num.push_back(0);
            t=a.num[i]*b.num[j]+res.num[i+j]+carry;
            carry=t/10;
            res.num[i+j]=t%10;
        }
        if(carry>0){
            if(i+j==res.num.size())
                res.num.push_back(0);
            res.num[i+j]+=carry;
        }
    }
    return;
}

void int_to_BigInteger(int a,BigInteger &res){
    if(a>=0)
        res.sign=1;
    else
        res.sign=-1;
    res.num.clear();
    a=abs(a);
    if(a==0)
        res.num.push_back(0);
    while(a>0){
        res.num.push_back(a%10);
        a/=10;
    }
    return;
}

void copy_BigInteger(const BigInteger &a,BigInteger &res){
    res.sign=a.sign;
    res.num=a.num;
    return;
}

bool isbigger_BigInteger(const BigInteger &a,const BigInteger &b){
    if(a.sign==-1 && b.sign==1)
        return false;
    if(a.sign==1 && b.sign==-1)
        return true;
    if(a.num.size()>b.num.size())
        if(a.sign==1)
            return true;
        else
            return false;
    if(a.num.size()<b.num.size())
        if(a.sign==1)
            return false;
        else
            return true;
    for(int i=a.num.size()-1;i>=0;i--){
        if(a.num[i]<b.num[i]){
            if(a.sign==1)
                return false;
            else
                return true;
        }else if(a.num[i]>b.num[i]){
            if(a.sign==-1)
                return false;
            else
                return true;
        }
    }
    return false;
}

int main(){
    int x,i,j;
    vector<BigInteger> seq;
    BigInteger temp,a,maxi;
    while(scanf("%d",&x)!=EOF){
        int_to_BigInteger(-999999,maxi);
        seq.clear();
        int_to_BigInteger(x,temp);
        seq.push_back(temp);
        while(scanf("%d",&x),x!=-999999){
            int_to_BigInteger(x,temp);
            seq.push_back(temp);
        }
        for(i=0;i<seq.size();i++){
            int_to_BigInteger(1,temp);
            for(j=i;j<seq.size();j++){
                copy_BigInteger(temp,a);
                multiply_BigInteger(a,seq[j],temp);
                if(isbigger_BigInteger(temp,maxi))
                    copy_BigInteger(temp,maxi);
            }
        }
        print_BigInteger(maxi);
    }
	return 0;
}
