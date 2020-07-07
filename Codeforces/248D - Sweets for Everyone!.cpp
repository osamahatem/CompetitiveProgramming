#include<bits/stdc++.h>

using namespace std;

int last=0;

long long check(string street,int sweets,int homes){
    int houses_before=0,first_house_before=-1,curSweets=sweets;
    long long t=0;
    for(int i=0;i<=last;i++){
        if(homes==0)
            return t;
        t++;
        if(street[i]=='S'){
            curSweets++,street[i]='.';
            if(curSweets==houses_before && first_house_before!=-1){
                int before=i-first_house_before,after=last-i;
                if(before<=after || homes==houses_before){
                    t+=before;
                    if(homes!=houses_before)
                        t+=before;
                    curSweets-=houses_before;
                    homes-=houses_before;
                    houses_before=0;
                    first_house_before=-1;
                }
            }
        }
        if(street[i]=='H'){
            if(curSweets>0 && first_house_before==-1)
                curSweets--,street[i]='.',homes--;
            else{
                houses_before++;
                if(first_house_before==-1)
                    first_house_before=i;
            }
        }
    }
    if(curSweets<houses_before)
        return 1ll<<60;
    if(first_house_before==-1)
        return t;
    return t+last-first_house_before;
}

int main(){
    int n,homes=0;
    long long t;
    string street;
    cin>>n>>t>>street;
    int lo=0,hi=0,mid,ans=-1;
    for(int i=0;i<n;i++){
        if(street[i]=='H')
            hi++,last=i,homes++;
        if(street[i]=='S')
            last=i;
    }
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(check(street,mid,homes)<=t)
            hi=mid-1,ans=mid;
        else
            lo=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
