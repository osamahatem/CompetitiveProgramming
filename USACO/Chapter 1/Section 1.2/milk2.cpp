/*
ID: 19semse1
PROG: milk2
LANG: C++
*/

#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int n,x,y,i,j,maxi,mini,milk=0,nomilk=0;
    vector<pair<int,int> > primary_list,merged_list;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&x,&y);
        primary_list.push_back(make_pair(x,y));
    }
    sort(primary_list.begin(),primary_list.end());
    i=0;
    j=1;
    while(i<primary_list.size()){
        mini=primary_list[i].first;
        maxi=primary_list[i].second;
        if(i+1==primary_list.size()){
            merged_list.push_back(make_pair(mini,maxi));
            break;
        }
        while(maxi>=primary_list[j].first && j<primary_list.size()){
            maxi=max(maxi,primary_list[j].second);
            j++;
            i++;
        }
        merged_list.push_back(make_pair(mini,maxi));
        i++;
        j++;
    }
    i=0;
    while(i+1<merged_list.size()){
        milk=max(milk,merged_list[i].second-merged_list[i].first);
        nomilk=max(nomilk,merged_list[i+1].first-merged_list[i].second);
        i++;
    }
    milk=max(milk,merged_list[i].second-merged_list[i].first);
    printf("%d %d\n",milk,nomilk);
    return 0;
}
