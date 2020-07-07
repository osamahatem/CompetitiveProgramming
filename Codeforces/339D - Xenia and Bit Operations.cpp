#include<cstdio>

int main(){
    int n,m,i,tree[300000],po[20],temp=1;
    for(i=0;i<20;i++){
        po[i]=temp;
        temp*=2;
    }
    scanf("%d%d",&n,&m);
    int st=po[n]-1,cnt=po[n];
    for(i=0;i<cnt;i++){
        scanf("%d",&temp);
        tree[st+i]=temp;
    }
    bool x=0;
    int v;
    while(st){
        for(i=0;i<cnt;i+=2){
            if(x)
                v=tree[st+i]^tree[st+i+1];
            else
                v=tree[st+i]|tree[st+i+1];
            tree[(st+i)/2]=v;
        }
        x=!x;
        cnt/=2;
        st/=2;
    }
    int p,b;
    while(m--){
        st=po[n]-1;
        x=0;
        scanf("%d%d",&p,&b);
        st+=--p;
        tree[st]=b;
        while(st>0){
            if(st%2==0)
                st--;
            if(x)
                v=tree[st]^tree[st+1];
            else
                v=tree[st]|tree[st+1];
            tree[st/2]=v;
            x=!x;
            st/=2;
        }
        printf("%d\n",tree[0]);
    }
	return 0;
}
