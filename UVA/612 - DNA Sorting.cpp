#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int checksort(char arr[],int n){
    int i,j,index=0;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(arr[i]>arr[j])
                index++;
    return index;
}

bool cmp(pair<string,int> a,pair<string,int> b){
    if(a.second!=b.second) return a.second<b.second;
    return false;
}

int main(){
    int t,n,m,i;
    char buffer[55];
    vector<pair<string,int> > data;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        gets(buffer);
        data.clear();
        while(m--){
            gets(buffer);
            data.push_back(make_pair(string(buffer),checksort(buffer,n)));
        }
        stable_sort(data.begin(),data.end(),cmp);
        for(i=0;i<data.size();i++)
            printf("%s\n",data[i].first.c_str(),data[i].second);
        if(t!=0)
            printf("\n");
    }
    return 0;
}
