#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    char in[105];
    vector<int> num;
    int x,c=0,r;
    gets(in);
    while(sscanf(in+c,"%d%n",&x,&r)!=EOF){
        num.push_back(x);
        c+=r;
    }
    sort(num.begin(),num.end());
    for(int i=0;i<num.size();i++){
        if(i>0)
            printf("+");
        printf("%d",num[i]);
    }
    printf("\n");
	return 0;
}
