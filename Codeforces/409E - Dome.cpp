#include<bits/stdc++.h>

using namespace std;

#define pi acos(-1.0)
#define eps 1e-9

double vol(int a,int h){
    return pi*h*(3*a*a+h*h)/6.0;
}

int main(){
    double x;
    cin>>x;
    cout<<vol(3,2);
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(fabs(vol(i,j)-x)<eps){
                cout<<i<<j<<endl;
                return 0;
            }
        }
    }
    return 0;
}
