#include<cstdio>

int p,votes[20],majority,original_index,original_votes;

int getpower(int i,int sum,int last_sum){
    if(sum>=majority)
        return 0;
    int power=0;
    if(sum+original_votes>=majority && sum!=last_sum)
        power++;
    if(i==p)
        return power;
    power+=getpower(i+1,sum,sum);
    if(i!=original_index)
        power+=getpower(i+1,sum+votes[i],sum);
    return power;
}

int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&p);
        majority=0;
        for(i=0;i<p;i++){
            scanf("%d",&votes[i]);
            majority+=votes[i];
        }
        majority=majority/2+1;
        for(i=0;i<p;i++){
            original_index=i;
            original_votes=votes[i];
            printf("party %d has power index %d\n",i+1,getpower(0,0,0));
        }
        printf("\n");
    }
    return 0;
}
