/*
ID: 19semse1
PROG: milk
LANG: C++
*/

#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    int n,m,i,p;
    vector<pair<int,int> > price;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&i,&p);
        price.push_back(make_pair(i,p));
    }
    sort(price.begin(),price.end());
    i=0;
    p=0;
    while(n>0){
        if(n<price[i].second){
            p+=price[i].first*n;
            n=0;
        }else{
            p+=price[i].first*price[i].second;
            n-=price[i].second;
        }
        i++;
    }
    printf("%d\n",p);
    return 0;
}
