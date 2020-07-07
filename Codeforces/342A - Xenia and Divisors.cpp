#include<cstdio>

int main(){
    int n,i,x,freq[8]={0,0,0,0,0,0,0,0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        freq[x]++;
    }
    if(freq[5] || freq[7]){
        printf("-1\n");
        return 0;
    }
    for(i=1;i<8;i++){
        if(freq[i]>n/3){
            printf("-1\n");
            return 0;
        }
    }
    if(freq[1]!=n/3 || freq[2]+freq[3]!=n/3 || freq[4]+freq[6]!=n/3){
        printf("-1\n");
        return 0;
    }
    if(freq[6]<freq[3]){
        printf("-1\n");
        return 0;
    }
    for(i=0;i<n/3;i++){
        printf("1");
        freq[1]--;
        if(freq[2]){
            printf(" 2");
            freq[2]--;
            if(freq[4]){
                printf(" 4\n");
                freq[4]--;
            }else{
                printf(" 6\n");
                freq[6]--;
            }
        }else{
            printf(" 3");
            freq[3]--;
            printf(" 6\n");
            freq[6]--;
        }
    }
	return 0;
}
