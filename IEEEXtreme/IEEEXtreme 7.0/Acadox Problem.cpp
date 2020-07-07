#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<stack>

using namespace std;

int hex_to_decimal(char in[5], int len){
    int i,p=1,temp,ret=0;

    for(i=0;i<len;i++)
        in[i]=tolower(in[i]);

    for(i=len-1;i>=0;i--){
        temp=in[i]-'0';
        if(in[i]>='a' && in[i]<='f')
            temp=in[i]-'a'+10;
        ret+=temp*p;
        p*=16;
    }

    return ret;
}

bool is_operator(char x){
    if(isdigit(x) || (isalpha(x) && x!='X'))
        return false;
    return true;
}

int apply_operation(int a,int b,char op){
    int ret;
    if(op=='+')
        ret=a+b;
    if(op=='-')
        ret=a-b;
    if(op=='&')
        ret=a&b;
    if(op=='|')
        ret=a|b;
    if(op=='X')
        ret=a^b;
    return min((1<<16)-1,max(0,ret));
}

int main(){
    char in[5];
    int len,a,b;
    stack<int> st;

    while(scanf("%s",in)!=EOF){
        len=strlen(in);

        if(is_operator(in[0])){
            if(st.size()<2 && in[0]!='~'){
                printf("ERROR\n");
                return 0;
            }
            if(st.size()<1){
                printf("ERROR\n");
                return 0;
            }

            if(in[0]=='~'){
                a=st.top();
                st.pop();
                st.push((1<<16)-1-a);
            }else{
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(apply_operation(b,a,in[0]));
            }
        }else
            st.push(hex_to_decimal(in,len));
    }

    if(st.size()==1){
        a=st.top();
        printf("%04X\n",a);
    }else
        printf("ERROR\n");
    return 0;
}
