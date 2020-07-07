#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,v,k,x;
    vector<int> ans;
    scanf("%d%d",&n,&v);
    for(int i=0;i<n;i++){
        bool flag=0;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&x);
            if(x<v)
                flag=1;
        }
        if(flag)
            ans.push_back(i+1);
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        if(i)
            printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
