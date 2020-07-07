#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

char b[10];

void convert(int x)
{
    int i=0;
    while(x!=0)
    {
        if(x%26==0)
        {
            b[i]='Z';
        }
        else
        {
            b[i]=(x%26)+'A'-1;
        }
        x-=b[i]-'A'-1;
        x/=26;
        i++;
    }
    b[i]='\0';
}

main()
{
    int n,i,j,k,x,y,z;
    char c;
    bool flag;
    scanf("%d\n",&n);
    for(n;n>0;n--)
    {
        x=0;
        y=0;
        j=0;
        vector<char> v;
        while(1)
        {
            scanf("%c",&c);
            if(c=='\n')
            {
                break;
            }
            v.push_back(c);
        }
        k=1;
        for(i=v.size()-1;i>=0;i--)
        {
            if(v[i]>='A' && v[i]<='Z')
            {
                break;
            }
            else
            {
                y+=(v[i]-'0')*k;
                k*=10;
            }
        }
        j=i;
        flag=0;
        for(j;j>=0;j--)
        {
            if(v[j]>='0' && v[j]<='9')
            {
                flag=1;
                break;
            }
        }
        z=j;
        if(!flag)
        {
            j=1;
            k=0;
            for(i;i>=0;i--)
            {
                k=v[i]-'A'+1;
                x+=j*k;
                j*=26;
            }
            printf("R%dC%d",y,x);
        }
        else
        {
            j=0;
            for(z;z>0;z--)
            {
                i=(v[z]-'0');
                for(k=0;k<j;k++)
                {
                    i*=10;
                }
                x+=i;
                j++;
            }
            j=x;
            convert(y);
            j=strlen(b);
            for(i=j-1;i>=0;i--)
            {
                printf("%c",b[i]);
            }
            printf("%d",x);
        }
        printf("\n");
    }
    return 0;
}
