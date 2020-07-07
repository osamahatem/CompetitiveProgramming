#include<bits/stdc++.h>

using namespace std;

int mod(int x,int m){
    return (x+m)%m;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

    int T;
    scanf("%d",&T);
    while(T--){
        int t,n,arr[20];
        queue<int> triangles;
        scanf("%d%d",&t,&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            if(arr[i]==1)
                triangles.push(i);
        }

        bool flag=0;
        vector< pair< int,pair<int,int> > > ans;
        while(triangles.size()){
            int temp=triangles.front();
            triangles.pop();
            if(arr[temp]!=1)
                continue;
            int before=mod(temp-1,n),after=mod(temp+1,n);
            for(;arr[before]==0;before=mod(before-1,n));
            for(;arr[after]==0;after=mod(after+1,n));
            if(before==after)
                continue;
            arr[before]--;
            arr[temp]--;
            arr[after]--;
            if(arr[before]==1)
                triangles.push(before);
            if(arr[after]==1)
                triangles.push(after);
            ++temp,++before,++after;
            if(before>temp)
                ans.push_back(make_pair(temp,make_pair(after,before)));
            else if(after<temp)
                ans.push_back(make_pair(after,make_pair(before,temp)));
            else
                ans.push_back(make_pair(before,make_pair(temp,after)));
        }
        for(int i=0;i<n;i++)
            if(arr[i]!=0)
                flag=1;
        printf("%d %c\n",t,flag ? 'N' : 'Y');
        if(!flag){
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
                printf("%d %d %d\n",ans[i].first,ans[i].second.first,ans[i].second.second);
        }
    }
	return 0;
}
