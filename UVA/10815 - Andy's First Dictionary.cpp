#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<map>

using namespace std;

string a;

int getstr(char x[],int i,int n)
{
    a.clear();
    for(;i<n;i++)
    {
        if(isalpha(x[i]))
        {
            a.push_back(tolower(x[i]));
        }
        else
        {
            i++;
            break;
        }
    }
    return i;
}

main()
{
    map<string,string> dic;
    map<string,string>::iterator it;
    char x[1000010];
    int l,i;
    while(scanf("%s",x)!=EOF)
    {
        i=0;
        l=strlen(x);
        while(i<l)
        {
            i=getstr(x,i,l);
            dic[a]=a;
        }
    }
    i=0;
    for(it=dic.begin();it!=dic.end();it++)
    {
        if(it->first[0]>='a')
        {
            printf("%s\n",it->first.c_str());
        }
    }
    return 0;
}
