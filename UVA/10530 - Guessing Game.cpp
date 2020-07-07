#include<cstdio>
#include<string>

using namespace std;

int main(){
    int x;
    char buffer[10];
    bool flag[11]={0,0,0,0,0,0,0,0,0,0};
    string state;
    while(1){
        scanf("%d",&x);
        gets(buffer);
        if(x==0)
            break;
        gets(buffer);
        state=string(buffer);
        if(state=="too high"){
            for(x;x<=10;x++)
                flag[x]=1;
        }else if(state=="too low"){
            for(x;x>0;x--)
                flag[x]=1;
            }else{
                if(flag[x])
                    printf("Stan is dishonest\n");
                else
                    printf("Stan may be honest\n");
                for(x=0;x<11;x++)
                    flag[x]=0;
            }
    }
    return 0;
}
