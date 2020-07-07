#include<cstdio>
#include<string>

using namespace std;

string add(string x,string y){
    int a,b,c=0,i;
    char d;
    string temp1="",temp2="";
    for(i=x.size()-1;i>=0;i--){
        a=x[i]-'0';
        b=y[i]-'0';
        d=((a+b+c)%10)+'0';
        c=(a+b+c)/10;
        temp1+=d;
    }
    if(c>0){
        d=c+'0';
        temp1+=d;
    }
    for(i=temp1.size()-1;i>=0;i--){
        temp2+=temp1[i];
    }
    return temp2;
}

string inc(string x){
    int i,c=1;
    char d;
    string temp1="",temp2="";
    for(i=x.size()-1;i>=0;i--){
        if(c>0){
            if(x[i]<'9'){
                d=x[i]+1;
                c=0;
            }else{
                d='0';
            }
        }else
            d=x[i];
        temp1+=d;
    }
    if(c>0){
        d=c+'0';
        temp1+=d;
    }
    for(i=temp1.size()-1;i>=0;i--){
        temp2+=temp1[i];
    }
    return temp2;
}

int main(){
    string ans[1000][2];
    int i,n;
    ans[0][0]="0";
    ans[0][1]="0";
    for(i=1;i<1000;i++){
        if(i%2){
            ans[i][0]=add(ans[i-1][0],ans[i-1][1]);
            ans[i][1]=ans[i][0];
        }else{
            ans[i][1]=add(ans[i-1][1],ans[i-1][1]);
            ans[i][0]=inc(ans[i][1]);
        }
    }
    while(scanf("%d",&n)!=EOF)
        printf("%s\n",ans[n][0].c_str());
	return 0;
}
