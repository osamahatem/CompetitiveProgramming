#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

main()
{
    int t,i,j,x,maxi,c;
    vector<int> courses;
    map<vector<int>,int> frosh;
    map<vector<int>,int>::iterator it;
    while(1)
    {
        scanf("%d",&t);
        if(t==0)
        {
            break;
        }
        maxi=0;
        c=0;
        frosh.erase(frosh.begin(),frosh.end());
        for(i=0;i<t;i++)
        {
            courses.erase(courses.begin(),courses.end());
            for(j=0;j<5;j++)
            {
                scanf("%d",&x);
                courses.push_back(x);
            }
            sort(courses.begin(),courses.end());
            frosh[courses]++;
        }
        for(it=frosh.begin();it!=frosh.end();it++)
        {
            if(it->second>maxi)
            {
                maxi=it->second;
            }
        }
        for(it=frosh.begin();it!=frosh.end();it++)
        {
            if(it->second==maxi)
            {
                c+=maxi;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
