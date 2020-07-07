#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int num[200000];
vector<int> t1,t2;

long long cnt_inv(int s,int e){
    if(e-s+1<2)
        return 0;
    if(e-s+1==2){
        if(num[s]>num[e]){
            swap(num[s],num[e]);
            return 1;
        }
        return 0;
    }
    long long ret=0;
    int i,j;
    ret+=cnt_inv(s,(s+e)/2);
    ret+=cnt_inv((s+e)/2+1,e);
    t1.clear();
    t2.clear();
    for(i=s;i<(s+e)/2+1;i++)
        t1.push_back(num[i]);
    for(i=(s+e)/2+1;i<=e;i++)
        t2.push_back(num[i]);
    i=0,j=0;
    while(1){
        if(i==t1.size() && j==t2.size())
            break;
        if(i==t1.size())
            num[s++]=t2[j++];
        else if(j==t2.size())
            num[s++]=t1[i++];
        else if(t1[i]>t2[j]){
            ret+=t1.size()-i;
            num[s++]=t2[j++];
        }else{
            num[s++]=t1[i++];
        }
    }
    return ret;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        printf("%lld\n",cnt_inv(0,n-1));
    }
	return 0;
}
