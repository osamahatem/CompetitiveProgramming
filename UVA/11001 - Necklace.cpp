#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int main(){
    double total,v;
    while(scanf("%lf%lf",&total,&v),total>0.0){
        int cnt=1,maxi_cnt=1;
        double maxi=0.0;
        bool flag=0;
        while(total/cnt>v){
            double temp=0.3*sqrt(total/cnt-v)*cnt;
            if(fabs(maxi-temp)<EPS)
                flag=1;
            else if(temp>maxi){
                flag=0;
                maxi=temp;
                maxi_cnt=cnt;
            }
            cnt++;
        }
        if(maxi<EPS || flag)
            printf("0\n");
        else
            printf("%d\n",maxi_cnt);
    }
    return 0;
}
