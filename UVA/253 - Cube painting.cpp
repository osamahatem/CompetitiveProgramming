#include<cstdio>

int rx[6]={0,3,4,2,1,5},ry[6]={1,5,2,3,0,4},rz[6]={3,1,0,5,4,2};

bool are_equal(char a[],char b[]){
    for(int i=0;i<6;i++)
        if(a[i]!=b[i])
            return false;
    return true;
}

void turn(char a[],int t){
    if(t==1)
}

bool check(char cur[],char target[],int x,int y,int z){
    if(x==4 || y==4 || z==4)
        return false;
    if(are_equal(target,cur))
        return true;
    bool ret=0;
}

int main(){
    char first[6],second[6];
    while(scanf("%6s%6s",first,second)!=EOF){
        bool ans=check(second,first,0,0,0);
    }
	return 0;
}
