#include<cstdio>
#include<stack>
#include<algorithm>

using namespace std;

typedef struct op{
    bool type;
    int st,ed,val;
}op;

int main(){
    int arr[5000],n,m,i,t,l,r,v,maxi;
    bool set_val[5000],invalid[5000],flag;
    stack<op> ops;
    op temp;
    for(i=0;i<5000;i++){
        arr[i]=0;
        set_val[i]=0;
        invalid[i]=0;
    }

    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d%d",&t,&l,&r,&v);
        temp.type=t-1;
        temp.st=l-1;
        temp.ed=r-1;
        temp.val=v;
        ops.push(temp);
    }

    while(!ops.empty()){
        temp=ops.top();
        ops.pop();
        if(temp.type==0){
            for(i=temp.st;i<=temp.ed;i++){
                arr[i]-=temp.val;
                if(set_val[i]==1)
                    invalid[i]=1;
            }
        }else{
            flag=1;
            maxi=arr[temp.st];
            for(i=temp.st;i<=temp.ed;i++){
                if(invalid[i] && arr[i]>temp.val){
                    printf("NO\n");
                    return 0;
                }
                flag&=set_val[i];
                if(!invalid[i]){
                    arr[i]=temp.val;
                    set_val[i]=1;
                }
                maxi=max(maxi,arr[i]);
            }
            if(flag && maxi!=temp.val){
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    for(i=0;i<n;i++){
        if(i>0)
            printf(" ");
        printf("%d",arr[i]);
    }
    printf("\n");

    return 0;
}
