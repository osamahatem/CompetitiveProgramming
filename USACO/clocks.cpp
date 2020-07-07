/*
ID: 19semse1
PROG: clocks
LANG: C++
*/

#include<cstdio>
#include<string>

using namespace std;

int clk[3][3];

bool isvalid(){
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(clk[i][j]!=0)
                return false;
    return true;
}

void turn(int m,int d){
    if(m==1 || m==2 || m==4)
        clk[0][0]=(clk[0][0]+d)%12;
    if(m==1 || m==2 || m==3 || m==5)
        clk[0][1]=(clk[0][1]+d)%12;
    if(m==2 || m==3 || m==6)
        clk[0][2]=(clk[0][2]+d)%12;
    if(m==1 || m==4 || m==5 || m==7)
        clk[1][0]=(clk[1][0]+d)%12;
    if(m==1 || m==3 || m==5 || m==7 || m==9)
        clk[1][1]=(clk[1][1]+d)%12;
    if(m==3 || m==5 || m==6 || m==9)
        clk[1][2]=(clk[1][2]+d)%12;
    if(m==4 || m==7 || m==8)
        clk[2][0]=(clk[2][0]+d)%12;
    if(m==5 || m==7 || m==8 || m==9)
        clk[2][1]=(clk[2][1]+d)%12;
    if(m==6 || m==8 || m==9)
        clk[2][2]=(clk[2][2]+d)%12;
    return;
}

void getmove(int i,string moves){
    if(isvalid()){
        moves.erase(moves.end()-1);
        printf("%s\n",moves.c_str());
        return;
    }
    if(i==10)
        return;
    char c=i+'0';
    getmove(i+1,moves);
    turn(i,3);
    moves=moves+c+' ';
    getmove(i+1,moves);
    turn(i,9);
    turn(i,6);
    moves=moves+c+' ';
    getmove(i+1,moves);
    turn(i,6);
    turn(i,9);
    moves=moves+c+' ';
    getmove(i+1,moves);
    turn(i,3);
    return;
}

int main(){
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    int i,j,x;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&x);
            clk[i][j]=x%12;
        }
    }
    getmove(1,"");
    return 0;
}
