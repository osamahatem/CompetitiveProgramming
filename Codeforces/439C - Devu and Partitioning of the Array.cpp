#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,p,x;
    vector<int> odd,even;
    scanf("%d%d%d",&n,&k,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x%2)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    if((int)odd.size()<k-p || ((int)odd.size()-(k-p))%2){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    if(p==0){
        for(int i=1;i<k;i++){
            int last=odd.size()-1;
            printf("1 %d\n",odd[last]);
            odd.pop_back();
        }
        printf("%d",even.size()+odd.size());
        for(int i=0;i<even.size();i++)
            printf(" %d",even[i]);
        for(int i=0;i<odd.size();i++)
            printf(" %d",odd[i]);
        printf("\n");
        return 0;
    }
    for(int i=0;i<k-p;i++){
        int last=odd.size()-1;
        printf("1 %d\n",odd[last]);
        odd.pop_back();
    }
    k-=k-p;
    while(k>1 && odd.size()){
        k--;
        int last=odd.size()-1;
        printf("2 %d %d\n",odd[last],odd[last-1]);
        odd.pop_back();
        odd.pop_back();
    }
    while(odd.size()){
        int last=odd.size()-1;
        even.push_back(odd[last]);
        odd.pop_back();
    }
    int idx=0;
    for(int i=1;i<k;i++)
        printf("1 %d\n",even[idx++]);
    printf("%d",even.size()-idx);
    for(;idx<even.size();idx++)
        printf(" %d",even[idx]);
    printf("\n");
    return 0;
}
