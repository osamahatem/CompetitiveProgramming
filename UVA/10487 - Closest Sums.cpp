#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main(){
    int n,m,i,j,x,num[1000],sums[1000000],s1,s2,t=1;
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        printf("Case %d:\n",t++);
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        int k=0;
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                sums[k++]=num[i]+num[j];
        sort(sums,sums+k);
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&x);
            printf("Closest sum to %d is ",x);
            s1=lower_bound(sums,sums+k,x)-sums;
            s2=s1-1;
            if(s1==k)
                printf("%d.\n",sums[s2]);
            else if(s2<=0)
                printf("%d.\n",sums[s1]);
            else if(abs(x-sums[s1])<abs(x-sums[s2]))
                printf("%d.\n",sums[s1]);
            else
                printf("%d.\n",sums[s2]);
        }
    }
    return 0;
}
