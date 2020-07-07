#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int num[9];
bool vis[10][2][2];
vector<int> dp[10][2][2];

vector<int> cnt(int idx,bool lim,bool trail){
    printf("**%d %d %d\n",idx,num[idx],trail);
    if(idx==8){
        vector<int> ret;
        for(int i=0;i<10;i++){
            if(i==0 && trail)
                ret.push_back(0);
            else if(i>num[idx] && lim)
                ret.push_back(0);
            else
                ret.push_back(1);
        }
        return ret;
    }
    if(vis[idx][lim][trail])
        return dp[idx][lim][trail];
    vis[idx][lim][trail]=1;
    if(num[idx]==0 && trail)
        return dp[idx][lim][trail]=cnt(idx+1,lim,trail);
    int i,j,sum;
    vector<int> ret(10,0),temp;
    for(i=0;i<num[idx];i++){
        if(i==0 && trail)
            temp=cnt(idx+1,0,1);
        else
            temp=cnt(idx+1,0,0);
        sum=0;
        for(j=0;j<10;j++){
            sum+=temp[j];
            ret[j]+=temp[j];
        }
        if(i!=0 || !trail)
            ret[i]+=sum;
    }
    if(lim){
        if(i==0 && trail)
            temp=cnt(idx+1,1,1);
        else
            temp=cnt(idx+1,1,0);
        sum=0;
        for(j=0;j<10;j++){
            sum+=temp[j];
            ret[j]+=temp[j];
        }
        if(i!=0 || !trail)
            ret[i]+=sum;
    }else{
        for(i=num[idx];i<10;i++){
            if(i==0 && trail)
                temp=cnt(idx+1,0,1);
            else
                temp=cnt(idx+1,0,0);
            sum=0;
            for(j=0;j<10;j++){
                sum+=temp[j];
                ret[j]+=temp[j];
            }
            if(i!=0 || !trail)
                ret[i]+=sum;
        }
    }
    return dp[idx][lim][trail]=ret;
}

int main(){
    int a,b,i;
    vector<int> cnt_1,cnt_2;
    while(scanf("%d%d",&a,&b),a!=0){
        if(a>b)
            swap(a,b);
        a--;
        for(i=8;i>=0;i--){
            num[i]=a%10;
            a/=10;
        }
        memset(vis,0,10*2*2);
        cnt_1=cnt(0,1,1);
        for(i=0;i<10;i++)
            printf("%d ",cnt_1[i]);
        printf("\n");
        for(i=8;i>=0;i--){
            num[i]=b%10;
            b/=10;
        }
        memset(vis,0,10*2*2);
        cnt_2=cnt(0,1,1);
        for(i=0;i<10;i++)
            printf("%d ",cnt_2[i]);
        printf("\n");
        for(i=0;i<10;i++){
            if(i>0)
                printf(" ");
            printf("%d",cnt_2[i]-cnt_1[i]);
        }
        printf("\n");
    }
	return 0;
}
