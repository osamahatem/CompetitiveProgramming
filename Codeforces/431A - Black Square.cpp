#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[4];
    for(int i=0;i<4;i++)
        scanf("%d",&a[i]);
    char arr[100005];
    scanf("%s",arr);
    int len=strlen(arr),ans=0;
    for(int i=0;i<len;i++)
        ans+=a[arr[i]-'1'];
    printf("%d\n",ans);
    return 0;
}
