#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> calchange(vector<long long> &table){
    long long i,d=0,n=table.size();
    vector<long long> change;
    change.push_back(0);
    for(i=1;i<n;i++){
        d+=table[i-1]*(i-1);
        change.push_back(d);
    }
    for(i=1;i<=n;i++){
        change[i-1]=change[i-1]-(i-1)*(n-i)*table[i-1];
    }
    return change;
}

int main(){
    long long n,k,i,j,temp;
    bool flag=0;
    vector<long long> table,change;
    scanf("%I64d%I64d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%I64d",&temp);
        table.push_back(temp);
    }
    i=0;
    j=0;
    while(1){
        change=calchange(table);
        for(i;i<change.size();i++){
            if(change[i]<k){
                printf("%I64d\n",++j+i);
                table.erase(table.begin()+i);
                change.clear();
                break;
            }
            else if(i==change.size()-1) flag=1;
        }
        if(flag) break;
    }
    return 0;
}
