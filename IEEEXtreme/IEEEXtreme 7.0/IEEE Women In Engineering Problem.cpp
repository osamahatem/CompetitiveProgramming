#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>

using namespace std;

const double convert=5.0/18.0;
const double v=90*convert;
const double a1=2.7*convert;
const double a2=3.8*convert;
const double min_dist=v*v/(2*a1)+v*v/(2*a2);

int get_time(double dist){
    double ret;
    if(dist<min_dist){
        ret=sqrt((2*dist)/(a2*a2/a1+a2));
        ret+=ret*a2/a1;
    }else{
        dist-=min_dist;
        ret=dist/v;
        ret+=v/a1+v/a2;
    }
    return (int)ceil(ret);
}

int main(){
    int n,time[11][2],st=0,temp=0,i,j;
    char in[100000];
    bool flag=1;
    vector<int> inp;

    for(i=0;i<11;i++)
        for(j=0;j<2;j++)
            time[i][j]=0;

    gets(in);
    int len=strlen(in);

    for(i=0;i<len;i++){
        if(isdigit(in[i])){
            temp=temp*10+in[i]-'0';
            flag=0;
        }
        else{
            if(!flag){
                inp.push_back(temp);
                flag=1;
            }
            temp=0;
        }
    }
    if(!flag)
        inp.push_back(temp);

    n=inp[0];
    st=inp.size()-1;

    if(n<1 || n>5 || st<1 || st>10){
        printf("ERROR\n");
        return 0;
    }

    st=0;
    for(i=1;i<inp.size();i++){
        st+=inp[i];
        if(inp[i]<500){
            printf("ERROR\n");
            return 0;
        }
    }
    if(st!=100000){
        printf("ERROR\n");
        return 0;
    }

    for(i=1;i<=n;i++){
        if(i==1){
            time[0][0]=1;
        }else{
            time[0][0]=max(time[0][1],time[1][0])+1;
        }
        printf("%d : *****",i);
        for(j=1;j<inp.size();j++){
            printf(" - %5d  ",time[j-1][0]);
            time[j-1][1]=time[j-1][0]+get_time((double)inp[j]);
            printf("%5d",time[j-1][1]);
            if(j<inp.size()-1){
                time[j][0]=max(time[j-1][1]+121,time[j][1]+1);
            }
        }
        printf(" *****\n");
    }

    return 0;
}
