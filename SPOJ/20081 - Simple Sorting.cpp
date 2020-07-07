#include<bits/stdc++.h>

using namespace std;

int arr[66000],temp[66000];

void merge_sort(int *s,int *e){
    if(e==s+1)
        return;
    int *m=s+(e-s)/2;
    merge_sort(s,m);
    merge_sort(m,e);
    int *i=s,*j=m;
    int k=0;
    while(i<m && j<e){
        if(*i<*j)
            temp[k++]=*i,i++;
        else
            temp[k++]=*j,j++;
    }
    while(i<m)
        temp[k++]=*i,i++;
    while(j<e)
        temp[k++]=*j,j++;
    for(int c=0;c<k;c++)
        *(s+c)=temp[c];
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    merge_sort(arr,arr+n);
    if(n%2==0)
        reverse(arr,arr+n);
    printf("%d\n",arr[0]);
    int last=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]==last)
            continue;
        last=arr[i];
        printf("%d\n",arr[i]);
    }
    return 0;
}
