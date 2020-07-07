#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

map<string,int> projects;
map<string,string> ID;
vector<string> sorted;

bool cmp(const string& a,const string& b)
{
    if(projects[a]!=projects[b])
    {
        return projects[a]>projects[b];
    }
    return a<b;
}

void counter()
{
    map<string,string>::iterator it;
    for(it=ID.begin();it!=ID.end();it++)
    {
        if(it->second!="X")
        {
            projects[it->second]++;
        }
    }
}

void prepare()
{
    map<string,int>::iterator it;
    for(it=projects.begin();it!=projects.end();it++)
    {
        sorted.push_back(it->first);
    }
    sort(sorted.begin(),sorted.end(),cmp);
}

main()
{
    char x[100000];
    int i;
    string project,name;
    while(1)
    {
        gets(x);
        if(x[0]=='1')
        {
            counter();
            prepare();
            for(i=0;i<sorted.size();i++)
            {
                printf("%s %d\n",sorted[i].c_str(),projects[sorted[i]]);
            }
            ID.clear();
            projects.clear();
            sorted.clear();
        }
        else if(x[0]=='0')
        {
            break;
        }
        else if(x[0]>='A' && x[0]<='Z')
        {
            project=string(x);
            projects[project]=0;
        }
        else
        {
            name=string(x);
            if(ID[name]=="")
            {
                ID[name]=project;
            }
            else if(ID[name]==project);
            else if(ID[name]=="X");
            else
            {
                ID[name]="X";
            }
        }
    }
    return 0;
}
