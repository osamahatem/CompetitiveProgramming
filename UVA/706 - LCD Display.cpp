#include<cstdio>
#include<cstring>

void print(char arr[][4],int line,int s){
    int i;
    printf("%c",arr[line][0]);
    for(i=0;i<s;i++) printf("%c",arr[line][1]);
    printf("%c",arr[line][2]);
    return;
}

int main(){
    char zero[5][4]={" - ","| |","   ","| |"," - "};
    char one[5][4]={"   ","  |","   ","  |","   "};
    char two[5][4]={" - ","  |"," - ","|  "," - "};
    char three[5][4]={" - ","  |"," - ","  |"," - "};
    char four[5][4]={"   ","| |"," - ","  |","   "};
    char five[5][4]={" - ","|  "," - ","  |"," - "};
    char six[5][4]={" - ","|  "," - ","| |"," - "};
    char seven[5][4]={" - ","  |","   ","  |","   "};
    char eight[5][4]={" - ","| |"," - ","| |"," - "};
    char nine[5][4]={" - ","| |"," - ","  |"," - "};
    int s,i,j,k,len;
    char n[10];
    while(1){
        scanf("%d%s",&s,n);
        if(s==0)
            break;
        len=strlen(n);
        for(i=0;i<5;i++){
            if(i%2==0){
                for(j=0;j<len;j++){
                    if(n[j]=='0') print(zero,i,s);
                    if(n[j]=='1') print(one,i,s);
                    if(n[j]=='2') print(two,i,s);
                    if(n[j]=='3') print(three,i,s);
                    if(n[j]=='4') print(four,i,s);
                    if(n[j]=='5') print(five,i,s);
                    if(n[j]=='6') print(six,i,s);
                    if(n[j]=='7') print(seven,i,s);
                    if(n[j]=='8') print(eight,i,s);
                    if(n[j]=='9') print(nine,i,s);
                    if(j!=len-1) printf(" ");
                }
            }else{
                for(k=0;k<s;k++){
                    for(j=0;j<len;j++){
                        if(n[j]=='0') print(zero,i,s);
                        if(n[j]=='1') print(one,i,s);
                        if(n[j]=='2') print(two,i,s);
                        if(n[j]=='3') print(three,i,s);
                        if(n[j]=='4') print(four,i,s);
                        if(n[j]=='5') print(five,i,s);
                        if(n[j]=='6') print(six,i,s);
                        if(n[j]=='7') print(seven,i,s);
                        if(n[j]=='8') print(eight,i,s);
                        if(n[j]=='9') print(nine,i,s);
                        if(j!=len-1) printf(" ");
                    }
                    printf("\n");
                }
            }
            if(i%2==0) printf("\n");
        }
        printf("\n");
    }
    return 0;
}
