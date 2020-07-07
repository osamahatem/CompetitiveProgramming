#include<cstdio>
#include<string>

using namespace std;

int main(){
    long long a,b,maxi=0;
    string res="",temp;
    scanf("%I64d%I64d",&a,&b);
    if(a==0){
        for(int i=0;i<b;i++)
            res+='x';
        maxi-=b*b;
        printf("%I64d\n%s\n",maxi,res.c_str());
        return 0;
    }
    long long b1=b/2,b2=b-b1;
    maxi=a*a-b1*b1-b2*b2;
    if(maxi>=0){
        for(int i=0;i<b1;i++)
            res+='x';
        for(int i=0;i<a;i++)
            res+='o';
        for(int i=0;i<b2;i++)
            res+='x';
        printf("%I64d\n%s\n",maxi,res.c_str());
        return 0;
    }
    long long step=b/(a+1),extra=b%(a+1),l;
    maxi=0;
    for(int i=0;i<a;i++){
        temp.clear();
        l=0;
        for(int j=0;j<step;j++){
            temp+='x';
            l++;
        }
        if(extra){
            temp+='x';
            l++;
            extra--;
        }
        maxi-=l*l;
        maxi++;
        temp+='o';
        res+=temp;
    }
    temp.clear();
    l=0;
    for(int j=0;j<step;j++){
        temp+='x';
        l++;
    }
    maxi-=l*l;
    res+=temp;
    printf("%I64d\n%s\n",maxi,res.c_str());
    return 0;
}
