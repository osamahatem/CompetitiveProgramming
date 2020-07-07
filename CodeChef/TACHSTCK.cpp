#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main(){
    int n,d,l[100000],ans=0;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++)
        scanf("%d",&l[i]);
    sort(l,l+n);
    for(int i=0;i<n-1;i++){
        if(abs(l[i]-l[i+1])<=d){
            ans++;
            i++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
