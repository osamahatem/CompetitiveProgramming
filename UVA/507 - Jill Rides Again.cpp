#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int t,T,i,n,x,max_so_far,max_ending_here,beg_temp,beg,en;
    vector<int> seq;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        seq.clear();
        scanf("%d",&n);
        for(i=1;i<n;i++){
            scanf("%d",&x);
            seq.push_back(x);
        }
        max_so_far=max_ending_here=seq[0];
        beg_temp=beg=1;
        en=2;
        for(i=1;i<seq.size();i++){
            if(max_ending_here<0){
                max_ending_here=seq[i];
                beg_temp=i+1;
            }else
                max_ending_here+=seq[i];
            if(max_ending_here>=max_so_far){
                if(max_ending_here>max_so_far){
                    max_so_far=max_ending_here;
                    beg=beg_temp;
                    en=i+2;
                }else if(i+2-beg_temp>en-beg){
                    beg=beg_temp;
                    en=i+2;
                }else if(beg_temp<beg){
                    beg=beg_temp;
                    en=i+2;
                }
            }
        }
        if(max_so_far<=0)
            printf("Route %d has no nice parts\n",t);
        else
            printf("The nicest part of route %d is between stops %d and %d\n",t,beg,en);
    }
	return 0;
}
