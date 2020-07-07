#include<cstdio>
#include<set>
#include<string>
#include<vector>
#include<utility>

using namespace std;

int main(){
    int n,x,i,j,idx=0,cnt=0;
    set<pair<int,int> > maxi;
    set<int> ind;
    vector<string> push_op,pop_op;
    push_op.push_back("pushStack");
    push_op.push_back("pushQueue");
    push_op.push_back("pushFront");
    pop_op.push_back("popStack");
    pop_op.push_back("popQueue");
    pop_op.push_back("popFront");

    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(x==0){
            j=0;
            for(set<pair<int,int> >::iterator it=maxi.begin();it!=maxi.end();it++){
                ind.insert((*it).second);
                //printf("*****%d\n",(*it).second);
            }
            for(i=0;i<cnt;i++){
                if(!ind.count(i))
                    printf("pushBack\n");
                else
                    printf("%s\n",push_op[j++].c_str());
            }
            printf("%d",maxi.size());
            for(i=0;i<maxi.size();i++)
                printf(" %s",pop_op[i].c_str());
            printf("\n");
            cnt=0;
            idx=0;
            maxi.clear();
            ind.clear();
        }else{
            cnt++;
            maxi.insert(make_pair(x,idx));
            idx++;
            if(maxi.size()>3)
                maxi.erase(maxi.begin());
        }
    }
    for(i=0;i<cnt;i++)
        printf("pushBack\n");
    return 0;
}
