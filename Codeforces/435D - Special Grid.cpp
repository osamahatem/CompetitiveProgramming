#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,ver[405][405],hor[405][405],ans=0;
    char arr[405][405];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",arr[i]);
    for(int i=0;i<n;i++){
        hor[i][0]=arr[i][0]-'0';
        for(int j=1;j<m;j++)
            hor[i][j]=hor[i][j-1]+arr[i][j]-'0';
    }
    for(int i=0;i<m;i++){
        ver[0][i]=arr[0][i]-'0';
        for(int j=1;j<n;j++)
            ver[j][i]=ver[j-1][i]+arr[j][i]-'0';
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='1')
                continue;
            int temp;
            bool flagl=0,flagr=0;
            for(int c=1;i+c<n && arr[i+c][j]!='1';c++){
                int cur=0;
                if(flagl && flagr)
                    break;
                if(j-c<0 || arr[i+c][j-c]=='1')
                    flagl=1;
                if(j+c>=m || arr[i+c][j+c]=='1')
                    flagr=1;
                if(!flagl){
                    temp=hor[i+c][j];
                    if(j-c>0)
                        temp-=hor[i+c][j-c-1];
                    if(temp==0)
                        cur++;
                }
                if(!flagr){
                    temp=hor[i+c][j+c];
                    if(j>0)
                        temp-=hor[i+c][j-1];
                    if(temp==0)
                        cur++;
                }
                if(cur==2)
                    cur++;
                ans+=cur;
            }
            flagl=0,flagr=0;
            for(int c=1;i-c>=0 && arr[i-c][j]!='1';c++){
                int cur=0;
                if(flagl && flagr)
                    break;
                if(j-c<0 || arr[i-c][j-c]=='1')
                    flagl=1;
                if(j+c>=m || arr[i-c][j+c]=='1')
                    flagr=1;
                if(!flagl){
                    temp=hor[i-c][j];
                    if(j-c>0)
                        temp-=hor[i-c][j-c-1];
                    if(temp==0)
                        cur++;
                }
                if(!flagr){
                    temp=hor[i-c][j+c];
                    if(j>0)
                        temp-=hor[i-c][j-1];
                    if(temp==0)
                        cur++;
                }
                if(cur==2)
                    cur++;
                ans+=cur;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='1')
                continue;
            int temp;
            bool flagl=0,flagr=0;
            for(int c=1;j+c<m && arr[i][j+c]!='1';c++){
                int cur=0;
                if(flagl && flagr)
                    break;
                if(i-c<0 || arr[i-c][j+c]=='1')
                    flagl=1;
                if(i+c>=n || arr[i+c][j+c]=='1')
                    flagr=1;
                if(!flagl){
                    temp=ver[i][j+c];
                    if(i-c>0)
                        temp-=ver[i-c-1][j+c];
                    if(temp==0)
                        cur++;
                }
                if(!flagr){
                    temp=ver[i+c][j+c];
                    if(i>0)
                        temp-=ver[i-1][j+c];
                    if(temp==0)
                        cur++;
                }
                if(cur==2)
                    cur++;
                if(cur==3)
                    ans++;
            }
            flagl=0,flagr=0;
            for(int c=1;j-c>=0 && arr[i][j-c]!='1';c++){
                int cur=0;
                if(flagl && flagr)
                    break;
                if(i-c<0 || arr[i-c][j-c]=='1')
                    flagl=1;
                if(i+c>=n || arr[i+c][j-c]=='1')
                    flagr=1;
                if(!flagl){
                    temp=ver[i][j-c];
                    if(i-c>0)
                        temp-=ver[i-c-1][j-c];
                    if(temp==0)
                        cur++;
                }
                if(!flagr){
                    temp=ver[i+c][j-c];
                    if(i>0)
                        temp-=ver[i-1][j-c];
                    if(temp==0)
                        cur++;
                }
                if(cur==2)
                    cur++;
                if(cur==3)
                    ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
