#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main(){
    int i;
    string num[1000];
    num[0]="";
    num[1]="one";
    num[2]="two";
    num[3]="three";
    num[4]="four";
    num[5]="five";
    num[6]="six";
    num[7]="seven";
    num[8]="eight";
    num[9]="nine";
    num[10]="ten";
    num[11]="eleven";
    num[12]="twelve";
    num[13]="thirteen";
    num[14]="fourteen";
    num[15]="fifteen";
    num[16]="sixteen";
    num[17]="seventeen";
    num[18]="eighteen";
    num[19]="nineteen";
    num[20]="twenty";
    num[30]="thirty";
    num[40]="forty";
    num[50]="fifty";
    num[60]="sixty";
    num[70]="seventy";
    num[80]="eighty";
    num[90]="ninety";
    for(i=20;i<100;i++)
        if(i%10==0)
            continue;
        else
            num[i]=num[i/10*10]+num[i%10];
    for(i=100;i<1000;i++)
        if(i%100==0)
            num[i]=num[i/100]+"hundred";
        else
            num[i]=num[i/100*100]+num[i%100];

    char words[25][55];
    int n,tot=0,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",words[i]);
        if(words[i][0]=='$')
            continue;
        tot+=strlen(words[i]);
    }
    for(i=1;i<1000;i++){
        if(tot+num[i].size()==i){
            for(j=0;j<n;j++){
                if(j>0)
                    printf(" ");
                if(words[j][0]=='$')
                    printf("%s",num[i].c_str());
                else
                    printf("%s",words[j]);
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}
