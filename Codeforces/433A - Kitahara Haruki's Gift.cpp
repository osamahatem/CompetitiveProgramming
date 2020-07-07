#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,arr[105],a=0,b=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n,greater<int>());
    for(int i=0;i<n;i++)
        if(a<b)
            a+=arr[i];
        else
            b+=arr[i];
    if(a==b)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
