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
};

ostream& operator << (ostream& os,const bigInt& a){
    string temp=a.num;
    reverse(temp.begin(),temp.end());
    os<<temp;
    return os;
}

int main(){
    int n;
    vector<bigInt> fid;
    fid.push_back(bigInt(0));
    fid.push_back(bigInt(1));
    fid.push_back(bigInt(1));
    cin>>n;
    for(int i=3;i<=n;i++)
        fid.push_back(fid[i-1]+fid[i-3]);
    cout<<fid[n]<<endl;
    return 0;
}
