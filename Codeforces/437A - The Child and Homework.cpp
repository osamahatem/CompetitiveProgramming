#include<bits/stdc++.h>

using namespace std;

int main(){
    char arr[105];
    int len[4];
    vector<int> ans;
    for(int i=0;i<4;i++){
        scanf("%s",arr);
        len[i]=strlen(arr)-2;
    }
    for(int i=0;i<4;i++){
        int small=0,large=0;
        for(int j=0;j<4;j++){
            if(i==j)
                continue;
            if(len[i]*2<=len[j])
                small++;
            if(len[i]>=len[j]*2)
                large++;
        }
        if(small==3 || large==3)
            ans.push_back(i);
    }
    if(ans.size()==1)
        printf("%c\n",'A'+ans[0]);
    else
        printf("C\n");
    return 0;
}
