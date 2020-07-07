#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,m,s1[10000],s2[10000];
    while(1){
        int i,j=0,sum1=0,sum2=0,maxi=0;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&s1[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&s2[i]);
        i=0;
        while(1){
            if(i==n && j==m)
                break;
            if(i==n){
                sum2+=s2[j];
                j++;
                continue;
            }
            if(j==m){
                sum1+=s1[i];
                i++;
                continue;
            }
            if(s1[i]==s2[j]){
                maxi+=max(sum1,sum2)+s1[i];
                sum1=0,sum2=0;
                i++;
                j++;
                continue;
            }
            if(s1[i]>s2[j]){
                sum2+=s2[j];
                j++;
            }else{
                sum1+=s1[i];
                i++;
            }
        }
        maxi+=max(sum1,sum2);
        printf("%d\n",maxi);
    }
    return 0;
}
