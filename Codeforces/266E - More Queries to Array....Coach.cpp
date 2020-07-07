#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL MOD = 1e9 + 7;

struct poly{
    valarray<LL> coeffs;

    poly(int degree):coeffs(degree+1){}

    int degree() const{
        return coeffs.size()-1;
    }

    poly operator * (const poly &a) const{
        poly res(a.degree() + degree());
        for(int i=0;i<=degree();i++){
            for(int j=0;j<=a.degree();j++){
                res.coeffs[i+j]+=coeffs[i]*a.coeffs[j]%MOD;
                res.coeffs[i+j]%=MOD;
            }
        }
        return res;
    }

    poly operator ^ (int p){
        /// p<=5
        /// iterative fast power
        poly res(0);
        res.coeffs[0]=1;
        poly temp=*this;
        for(;p;p>>=1){
            if(p&1)
                res=res*temp;
            temp=temp*temp;
        }
        return res;
    }
};

LL fastPower (LL base,int p){
    /// p<=5
    /// iterative fast power
    LL res=1;
    for(;p;p>>=1){
        if(p&1)
            res=res*base%MOD;
        base=base*base%MOD;
    }
    return res;
}

LL dp[100009][7];

LL sumOfPowers(int n,int k){
    if(n==0)
        return 0;

    LL &ret=dp[n][k];
    if(ret!=-1)
        return ret;

    return ret=(sumOfPowers(n-1,k)+fastPower(n,k))%MOD;
}

struct node{
    valarray<LL> vals;
    LL lazy;

    node():vals(6),lazy(-1){}

    void setValue(LL v,int ns,int ne){
        lazy=v;
        for(int i=0;i<6;i++){
            vals[i]=(sumOfPowers(ne,i)-sumOfPowers(ns-1,i)+MOD)%MOD*v%MOD;
        }
    }
}nodes[1<<18];

int qs,qe,n;
LL value;

void update(int ni=0,int ns=1,int ne=n){
    if(ns>qe || ne<qs)
        return;

    node &nd=nodes[ni];
    if(ns>=qs && ne<=qe){
        nd.setValue(value,ns,ne);
        return;
    }

    int mid=(ns+((ne-ns)>>1));
    int left=(ni<<1)+1,right=left+1;

    if(nd.lazy!=-1){
        nodes[left].setValue(nd.lazy,ns,mid);
        nodes[right].setValue(nd.lazy,mid+1,ne);
        nd.lazy=-1;
    }

    update(left,ns,mid);
    update(right,mid+1,ne);
    nd.vals=(nodes[left].vals+nodes[right].vals)%MOD;
    return;
}

valarray<LL> query(int ni=0,int ns=1,int ne=n){
    if(ns>qe || ne<qs)
        return valarray<LL> (6);

    node &nd=nodes[ni];
    if(ns>=qs && ne<=qe)
        return nd.vals;

    int mid=(ns+((ne-ns)>>1));
    int left=(ni<<1)+1,right=left+1;

    if(nd.lazy!=-1){
        nodes[left].setValue(nd.lazy,ns,mid);
        nodes[right].setValue(nd.lazy,mid+1,ne);
        nd.lazy=-1;
    }

    return (query(left,ns,mid)+query(right,mid+1,ne))%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof dp);

    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>value;
        qs=qe=i+1;
        update();
    }
    char a;
    while(q--){
        cin>>a>>qs>>qe>>value;
        if(a=='=')
            update();
        else{
            poly temp(1);
            temp.coeffs[0]=(1-qs+MOD)%MOD;
            temp.coeffs[1]=1;
            temp=temp^value;
            valarray<LL> temp2=query()[slice(0,temp.coeffs.size(),1)];
            cout<<(temp.coeffs*temp2%MOD).sum()%MOD<<"\n";
        }
    }

    return 0;
}
