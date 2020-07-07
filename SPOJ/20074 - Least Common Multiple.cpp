#include<bits/stdc++.h>

using namespace std;

struct bigInt{
    string num;

    bigInt(int n){
        num="";
        do{
            num+=(n%10)+'0';
            n/=10;
        }while(n);
    }

    bigInt(string num) : num(num) {}

    const bigInt operator + (const bigInt &a) const{
        int i=0,c=0,x,y,s;
        string ret="";
        while(i<num.size() || i<a.num.size()){
            x=(i<num.size()) ? num[i]-'0' : 0 ;
            y=(i<a.num.size()) ? a.num[i]-'0' : 0 ;
            s=x+y+c;
            ret+=(s%10)+'0';
            c=s/10;
            i++;
        }
        if(c)
            ret+=c+'0';
        return bigInt(ret);
    }

    const bigInt operator += (const bigInt &a){
        *this=*this+a;
        return *this;
    }

    const bigInt operator * (const bigInt &a) const{
        bigInt ret(0);
        for(int i=0;i<a.num.size();i++){
            string temp="";
            for(int j=0;j<i;j++)
                temp+="0";
            int c=0,x=a.num[i]-'0',y,p;
            for(int j=0;j<num.size();j++){
                y=num[j]-'0';
                p=x*y+c;
                temp+=(p%10)+'0';
                c=p/10;
            }
            if(c)
                temp+=c+'0';
            ret+=bigInt(temp);
        }
        while(ret.num.size()>1 && ret.num[ret.num.size()-1]=='0')
            ret.num.erase(ret.num.size()-1);
        return ret;
    }

    const bigInt operator *= (const bigInt &a){
        *this=*this*a;
        return *this;
    }
};

ostream& operator << (ostream& os,const bigInt &a){
    string temp=a.num;
    reverse(temp.begin(),temp.end());
    os<<temp;
    return os;
}

map<int,int> factors;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int c,x=i;
        for(int j=2;j*j<=x;j++){
            c=0;
            while(x%j==0){
                x/=j;
                c++;
            }
            factors[j]=max(factors[j],c);
        }
        if(x>1)
            factors[x]=max(factors[x],1);
    }
    bigInt ans(1);
    map<int,int>::iterator it;
    for(it=factors.begin();it!=factors.end();it++)
        for(int i=0;i<it->second;i++)
            ans*=bigInt(it->first);
    cout<<ans<<endl;
    return 0;
}
