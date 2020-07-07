#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int n,i,j,c=0,x,y;
    bool flag[100];
    vector<int> a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        a.push_back(x);
        b.push_back(y);
        flag[i]=0;
        c++;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) continue;
            if(a[j]==b[i] && !flag[j])
            {
                c--;
                flag[j]=1;
            }
        }
    }
    printf("%d\n",c);
    return 0;
}
