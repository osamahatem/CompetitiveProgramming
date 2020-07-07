#include<cstdio>
#include<algorithm>

using namespace std;

bool in[105],temp[105];
int n;

void reset(){
    int i;
    for(i=0;i<n;i++)
        temp[i]=in[i];
}

void flip(int i,int j){
    for(;i<=j;i++)
        temp[i]=!in[i];
}

int getcount(){
    int c=0,i;
    for(i=0;i<n;i++)
        if(temp[i]==1)
            c++;
    return c;
}

int main(){
    int i,j,maxi=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            reset();
            flip(i,j);
            maxi=max(maxi,getcount());
        }
    }
    printf("%d\n",maxi);
    return 0;
}
