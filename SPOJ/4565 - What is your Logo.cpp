#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<vector>

using namespace std;

main()
{
    int i,l,c;
    set<vector<int> > flag;
    char in[1010];
    vector<int> pos;
    while(1)
    {
        pos.clear();
        pos.push_back(0);
        pos.push_back(0);
        flag.clear();
        flag.insert(pos);
        c=0;
        gets(in);
        if(in[0]=='Q')
        {
            break;
        }
        else
        {
            l=strlen(in);
            for(i=0;i<l;i++)
            {
                if(in[i]=='U')
                {
                    pos[0]++;
                }
                else if(in[i]=='D')
                {
                    pos[0]--;
                }
                else if(in[i]=='R')
                {
                    pos[1]++;
                }
                else if(in[i]=='L')
                {
                    pos[1]--;
                }
                else
                {
                    break;
                }
                if(flag.count(pos))
                {
                    c++;
                }
                else
                {
                    flag.insert(pos);
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
