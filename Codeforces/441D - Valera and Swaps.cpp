#include<bits/stdc++.h>

using namespace std;

int getF(vector<int> p){
    int ret=0;
    for(int i=0;i<p.size();i++){
        if(p[i]!=i){
            ret++;
            swap(p[i],p[p[i]]);
        }
    }
    return ret;
}

int main(){
    int n,m,x;
    vector<int> p;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        p.push_back(x-1);
    }
    scanf("%d",&m);
    int fp=getF(p);
    printf("%d\n",abs(fp-m));
    return 0;
}
