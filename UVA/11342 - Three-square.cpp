#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;1

int main(){
    int n,k,temp,n1,n2,n3;
    bool flag;
    vector<vector<int> > answers;
    vector<int> num;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        n3=floor(sqrt(k)+0.5);
        flag=0;
        answers.clear();
        for(n3;n3>0;n3--){
            temp=k;
            temp-=n3*n3;
            n2=sqrt(temp);
            temp-=n2*n2;
            n1=sqrt(temp);
            if(n1*n1+n2*n2+n3*n3==k){
                flag=1;
                num.clear();
                num.push_back(n1);
                num.push_back(n2);
                num.push_back(n3);
                sort(num.begin(),num.end());
                printf("%d %d %d\n",num[0],num[1],num[2]);
                answers.push_back(num);
            }
        }
        sort(answers.begin(),answers.end());
        if(flag)
            printf("%d %d %d\n",answers[0][0],answers[0][1],answers[0][2]);
        else
            printf("-1\n");
    }
    return 0;
}
