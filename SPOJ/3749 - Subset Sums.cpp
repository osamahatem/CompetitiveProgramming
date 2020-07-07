#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n,num[34],a,b,x;
    long long sol=0;
    vector<int> fh,sh;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    x=n/2;
    for(int i=0;i<1<<x;i++){
        int sum=0;
        for(int j=0;j<x;j++){
            if(i&(1<<j))
                sum+=num[j];
        }
        fh.push_back(sum);
    }
    if(n%2)
        x++;
    for(int i=0;i<1<<x;i++){
        int sum=0;
        for(int j=0;j<x;j++){
            if(i&(1<<j))
                sum+=num[j+n/2];
        }
        sh.push_back(sum);
    }
    sort(fh.begin(),fh.end());
    sort(sh.begin(),sh.end());
    for(int i=0;i<fh.size();i++){
        int mini=a-fh[i];
        int maxi=b-fh[i];
        int st=lower_bound(sh.begin(),sh.end(),mini)-sh.begin();
        int ed=upper_bound(sh.begin(),sh.end(),maxi)-sh.begin();
        sol+=ed-st;
    }
    printf("%lld\n",sol);
    return 0;
}
