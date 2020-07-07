#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

int main(){
    int n,i,x;
    bool flag[3000],jolly;
    vector<int> numbers;
    while(scanf("%d",&n)!=EOF){
        numbers.clear();
        jolly=1;
        for(i=0;i<3000;i++)
            flag[i]=0;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            numbers.push_back(x);
        }
        if(n==1)
            jolly=1;
        else{
            for(i=1;i<n;i++)
                flag[abs(numbers[i]-numbers[i-1])]=1;
            for(i=1;i<n;i++)
                if(!flag[i])
                    jolly=0;
        }
        if(jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
