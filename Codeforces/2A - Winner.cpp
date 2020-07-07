#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
map<string,int> score;
map<string,int>::iterator i;
map<string,map<int,int> > order;

bool cmp(string a,string b)
{
    int c;
    if(score[a]!=score[b])
    {
        return score[a]>score[b];
    }
    for(c=0;c<n;c++)
    {
        if(order[a][c]>=score[a])
        {
            return true;
        }
        else if(order[b][c]>=score[b])
        {
            return false;
        }
    }
}

main()
{
    int x,j;
    char buffer[35];
    vector<string> sorted;
    string name;
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%s%d",buffer,&x);
        name=string(buffer);
        score[name]+=x;
        order[name][j]=score[name];
    }
    for(i=score.begin();i!=score.end();i++)
    {
        sorted.push_back(i->first);
    }
    sort(sorted.begin(),sorted.end(),cmp);
    printf("%s\n",sorted[0].c_str());
    return 0;
}
