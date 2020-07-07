#include<cstdio>
#include<string>

using namespace std;

string getlast(int n)
{
    n=n-4;
    if(n%6==0) return "050";
    if(n%6==1) return "080";
    if(n%6==2) return "170";
    if(n%6==3) return "020";
    if(n%6==4) return "200";
    if(n%6==5) return "110";
}

main()
{
    int n,i;
    string out="";
    scanf("%d",&n);
    if(n==1 || n==2)
    {
        printf("-1\n");
    }
    else if(n==3)
    {
        printf("210\n");
    }
    else
    {
        out+="1";
        for(i=0;i<n-4;i++)
        {
            out+="0";
        }
        out+=getlast(n);
        printf("%s\n",out.c_str());
    }
    return 0;
}
