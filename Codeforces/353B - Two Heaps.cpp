#include<cstdio>
#include<set>
#include<vector>

using namespace std;

int main(){
    int n,i,x,j;
    bool flag=0,heap[200];
    vector<int> cnt[100];
    set<int> first,second;
    scanf("%d",&n);
    for(i=0;i<2*n;i++){
        scanf("%d",&x);
        cnt[x].push_back(i);
    }
    for(i=0;i<100;i++){
        for(j=0;j<cnt[i].size();j++){
            heap[cnt[i][j]]=flag;
            if(flag)
                second.insert(i);
            else
                first.insert(i);
            flag=!flag;
        }
    }
    printf("%d\n",(int)first.size()*(int)second.size());
    for(i=0;i<2*n;i++){
        if(i>0)
            printf(" ");
        printf("%d",(int)heap[i]+1);
    }
    printf("\n");
	return 0;
}
