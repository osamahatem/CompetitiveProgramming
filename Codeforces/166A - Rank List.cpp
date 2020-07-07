#include<bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first!=b.first)
        return a.first>b.first;
    return a.second<b.second;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int n,k;
    pair<int,int> arr[55];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr,arr+n,cmp);
    printf("%d\n",upper_bound(arr,arr+n,arr[k-1],cmp)-lower_bound(arr,arr+n,arr[k-1],cmp));
	return 0;
}
