#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n,g,s,r,i,maxi;
    vector<int> scores;

    while(scanf("%d%d",&n,&g)!=EOF){
        maxi=0;
        scores.clear();

        while(n--){
            scanf("%d%d",&s,&r);
            scores.push_back(r-s);
        }

        sort(scores.begin(),scores.end());

        i=0;
        while(i<scores.size()){
            if(scores[i]<0)
                maxi+=3;
            if(scores[i]==0){
                if(g>=1){
                    maxi+=3;
                    g--;
                }else
                    maxi++;
            }
            if(scores[i]>0){
                if(g>scores[i]){
                    g-=scores[i]+1;
                    maxi+=3;
                }else if(g==scores[i]){
                    g-=scores[i];
                    maxi++;
                }
            }
            i++;
        }

        printf("%d\n",maxi);
    }
    return 0;
}
