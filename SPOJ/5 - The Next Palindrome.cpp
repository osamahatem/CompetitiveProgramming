#include<cstdio>
#include<cstring>

char in[1000005];
bool flag;

bool ispal(int len){
    int mid=(len-1)/2;
    while(mid>=0){
        if(in[mid]!=in[len-1-mid])
            return false;
        mid--;
    }
    return true;
}

bool isrev(int len){
    int mid=(len-1)/2;
    while(mid>=0){
        if(in[mid]>in[len-1-mid])
            return false;
        mid--;
    }
    return true;
}

bool do_inc(int len){
    if(ispal(len))
        return true;
    int mid=(len-1)/2;
    if(in[mid]<in[len-1-mid])
        return true;
    if(in[mid]==in[len-1-mid])
        return isrev(len);
    return false;
}

void inc(int mid){
    if(in[mid]=='9'){
        in[mid]='0';
        if(mid==0)
            flag=1;
        else
            inc(mid-1);
    }else
        in[mid]++;
    return;
}

void fix(int len){
    in[len+1]='\0';
    while(len>0){
        in[len]=in[len-1];
        len--;
    }
    in[len]='1';
    return;
}

void gen_pal(int len){
    for(int i=0;i<=len/2;i++)
        in[len-i-1]=in[i];
    return;
}

int main(){
    int t,len,mid;
    scanf("%d ",&t);
    while(t--){
        gets(in);
        len=strlen(in);
        mid=(len-1)/2;
        flag=0;
        if(do_inc(len))
            inc(mid);
        if(flag){
            fix(len);
            len++;
        }
        gen_pal(len);
        printf("%s\n",in);
    }
	return 0;
}
