#include<cstdio>
#include<string>

using namespace std;

int c[8];

void zero()
{
    int i;
    for(i=0;i<8;i++)
    {
        c[i]=0;
    }
}

void cnt(string data)
{
    if(data=="TTT") c[0]++;
    if(data=="TTH") c[1]++;
    if(data=="THT") c[2]++;
    if(data=="THH") c[3]++;
    if(data=="HTT") c[4]++;
    if(data=="HTH") c[5]++;
    if(data=="HHT") c[6]++;
    if(data=="HHH") c[7]++;
}

main()
{
    int t,x,i;
    char data[45],seq[4];
    seq[3]='\0';
    scanf("%d",&t);
    while(t--)
    {
        zero();
        scanf("%d %s",&x,data);
        for(i=0;i<38;i++)
        {
            seq[0]=data[i];
            seq[1]=data[i+1];
            seq[2]=data[i+2];
            cnt(string(seq));
        }
        printf("%d",x);
        for(i=0;i<8;i++)
        {
            printf(" %d",c[i]);
        }
        printf("\n");
    }
    return 0;
}
