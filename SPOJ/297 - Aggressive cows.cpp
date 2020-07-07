#include<cstdio>
#include<algorithm>

using namespace std;

int n,c,st[100000];

bool isvalid(int ans){
    int left=c-1;
    int s=st[0];
    int idx=1;
    while(left>0){
        if(idx>=n)
            return false;
        if(st[idx]>=s+ans){
            left--;
            s=st[idx];
        }
        idx++;
    }
    return true;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&c);
        for(int i=0;i<n;i++)
            scanf("%d",&st[i]);
        sort(st,st+n);
        int s=0,e=st[n-1],maxans=0,cur;
        while(s<=e){
            cur=(s+e)/2;
            if(isvalid(cur)){
                s=cur+1;
                maxans=cur;
            }
            else
                e=cur-1;
        }
        printf("%d\n",maxans);
    }
    return 0;
}
