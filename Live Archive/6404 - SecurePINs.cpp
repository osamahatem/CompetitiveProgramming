#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int n;
    char arr[7];
    scanf("%d",&n);
    while(n--){
        bool flag=1;
        scanf("%s",arr);
        for(int i=0;i<6;i++)
            for(int j=i+1;j<6;j++)
                for(int k=j+1;k<6;k++)
                    if(arr[i]==arr[j] && arr[j]==arr[k])
                        flag=0;
        for(int i=0;i+2<6;i++){
            if(arr[i]-arr[i+1]==1 && arr[i+1]-arr[i+2]==1)
                flag=0;
            if(arr[i]-arr[i+1]==-1 && arr[i+1]-arr[i+2]==-1)
                flag=0;
        }
        printf("%s\n",flag ? "ACCEPTABLE" : "WEAK");
    }
	return 0;
}
