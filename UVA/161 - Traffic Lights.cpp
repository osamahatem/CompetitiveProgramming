#include<cstdio>
#include<set>
#include<vector>

using namespace std;

int main(){
    int x,i,temp,time,hr,mn,sec;
    vector<int> cycle;
    set<int> events;
    set<int>::iterator it;
    bool flag;
    while(scanf("%d",&x),x!=0){
        cycle.clear();
        events.clear();
        cycle.push_back(x);
        while(scanf("%d",&x),x!=0)
            cycle.push_back(x);
        for(i=0;i<cycle.size();i++){
            temp=cycle[i]*2;
            while(temp<=18000){
                events.insert(temp);
                temp+=cycle[i]*2;
            }
        }
        for(it=events.begin();it!=events.end();it++){
            flag=1;
            for(i=0;i<cycle.size();i++){
                temp=*it%(cycle[i]*2);
                if(temp>=cycle[i]-5){
                    flag=0;
                    break;
                }
            }
            if(flag){
                time=*it;
                break;
            }
        }
        if(flag){
            sec=time%60;
            time/=60;
            mn=time%60;
            time/=60;
            hr=time;
            printf("%02d:%02d:%02d\n",hr,mn,sec);
        }else{
            printf("Signals fail to synchronise in 5 hours\n");
        }
    }
	return 0;
}
