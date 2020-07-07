#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,maxi_idx=0;
    double maxi=0,x;
    vector<double> p,have;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&x);
        p.push_back(x);
        if(p[i]>maxi){
            maxi=p[i];
            maxi_idx=i;
        }
    }
    have.push_back(p[maxi_idx]);
    p.erase(p.begin()+maxi_idx);
    while(p.size()){
        double temp_max=maxi;
        int temp_max_idx=-1;
        for(int i=0;i<p.size();i++){
            double cur=maxi*(1-p[i]),add=p[i];
            for(int j=0;j<have.size();j++)
                add*=1-have[j];
            cur+=add;
            if(cur>temp_max){
                temp_max=cur;
                temp_max_idx=i;
            }
        }
        if(temp_max_idx!=-1){
            have.push_back(p[temp_max_idx]);
            p.erase(p.begin()+temp_max_idx);
            maxi=temp_max;
        }else
            break;
    }
    printf("%.9f\n",maxi);
    return 0;
}
