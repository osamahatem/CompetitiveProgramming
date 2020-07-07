#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

bool isheavy(char arr[],int i){
    if(arr[i]=='h' && arr[i+1]=='e' && arr[i+2]=='a' && arr[i+3]=='v' && arr[i+4]=='y')
        return true;
    return false;
}

bool ismetal(char arr[],int i){
    if(arr[i]=='m' && arr[i+1]=='e' && arr[i+2]=='t' && arr[i+3]=='a' && arr[i+4]=='l')
        return true;
    return false;
}

int main(){
    int len,i,temp;
    long long c=0;
    char arr[1000005];
    vector<int> heavy;
    vector<int> metal;
    gets(arr);
    len=strlen(arr);
    for(i=0;i<len-4;i++){
        if(isheavy(arr,i))
            heavy.push_back(i);
        if(ismetal(arr,i))
            metal.push_back(i);
    }
    for(i=0;i<heavy.size();i++){
        temp=lower_bound(metal.begin(),metal.end(),heavy[i])-metal.begin();
        c+=metal.size()-temp;
    }
    printf("%I64d\n",c);
    return 0;
}
