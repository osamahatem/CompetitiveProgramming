#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int b[3][3],temp,mini;
    char i_to_c[3]={'B','G','C'};
    string ans,temp_ans;
    while(scanf("%d%d%d%d%d%d%d%d%d",&b[0][0],&b[0][1],&b[0][2],&b[1][0],&b[1][1],&b[1][2],&b[2][0],&b[2][1],&b[2][2])!=EOF){
        mini=1<<30;
        int moves[3]={0,1,2};
        do{
            temp=b[1][moves[0]]+b[2][moves[0]];
            temp+=b[0][moves[1]]+b[2][moves[1]];
            temp+=b[0][moves[2]]+b[1][moves[2]];
            if(temp==mini){
                temp_ans.clear();
                temp_ans+=i_to_c[moves[0]];
                temp_ans+=i_to_c[moves[1]];
                temp_ans+=i_to_c[moves[2]];
                ans=min(ans,temp_ans);
            }else if(temp<mini){
                ans.clear();
                mini=temp;
                ans+=i_to_c[moves[0]];
                ans+=i_to_c[moves[1]];
                ans+=i_to_c[moves[2]];
            }
        }while(next_permutation(moves,moves+3));
        printf("%s %d\n",ans.c_str(),mini);
    }
	return 0;
}
