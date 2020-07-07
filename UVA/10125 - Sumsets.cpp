#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct sum{
    int s;
    int st;
    int ed;
}sum;

sum sums[1000000];

bool cmp(const sum &a,const sum &b){
    if(a.s!=b.s)
        return a.s<b.s;
    if(a.st!=b.st)
        return a.st<b.st;
    return a.ed<b.ed;
}

int bsearch(int i,int j,sum arr[],int val){
    int h=(i+j)/2;
    while(i<=j){
        if(arr[h].s==val)
            return h;
        if(arr[h].s<val)
            i=h+1;
        else
            j=h-1;
        h=(i+j)/2;
    }
    return 1000000;
}

int main(){
    int n,num[1000];
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        int i,j,c=0;
        sum temp;
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        sort(num,num+n);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++){
                temp.s=num[i]+num[j];
                temp.st=i;
                temp.ed=j;
                sums[c++]=temp;
            }
        sort(sums,sums+c,cmp);
        int maxi=-1800000000;
        for(i=0;i<n;i++)
            for(j=0;j<i;j++){
                int b=bsearch(0,c,sums,num[i]-num[j]);
                if(b!=1000000 && i!=sums[b].st && i!=sums[b].ed && j!=sums[b].st && j!=sums[b].ed)
                    maxi=max(maxi,num[i]);
            }
        if(maxi==-1800000000)
            printf("no solution\n");
        else
            printf("%d\n",maxi);
    }
    return 0;
}
