#include<bits/stdc++.h>

using namespace std;

bool check(int seq[]){
    bool empty=1;
    for(int i=1;i<10;i++)
        empty&=(seq[i]==0);
    if(empty)
        return true;
    int temp[10];
    for(int i=1;i<10;i++)
        temp[i]=seq[i];
    for(int i=1;i<10;i++){
        if(temp[i]==3){
            temp[i]=0;
            if(check(temp))
                return true;
            temp[i]=3;
        }
    }
    for(int i=1;i+2<10;i++)
        if(temp[i]>0){
            if(!(temp[i+1]>0 && temp[i+2]>0))
                continue;
            temp[i]--;
            temp[i+1]--;
            temp[i+2]--;
            if(check(temp))
                return true;
            temp[i]++;
            temp[i+1]++;
            temp[i+2]++;
        }
    return false;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int t,x,arr[10];
    scanf("%d",&t);
    while(t--){
        memset(arr,0,sizeof arr);
        for(int i=0;i<14;i++){
            scanf("%d",&x);
            arr[x]++;
        }
        bool flag=0;
        for(int i=1;i<=9;i++){
            if(arr[i]<2)
                continue;
            arr[i]-=2;
            flag|=check(arr);
            arr[i]+=2;
        }
        printf("%s\n",flag ? "Vulnerable" : "Immune");
    }
	return 0;
}
