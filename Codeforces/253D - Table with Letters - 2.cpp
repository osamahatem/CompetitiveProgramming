#include<cstdio>
#include<vector>

using namespace std;

char grid[405][405];
int n,m,cumulative[405][405];

void build_cumulative(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cumulative[i][j]=(grid[i][j]=='a');
            if(i>0)
                cumulative[i][j]+=cumulative[i-1][j];
            if(j>0)
                cumulative[i][j]+=cumulative[i][j-1];
            if(i>0 && j>0)
                cumulative[i][j]-=cumulative[i-1][j-1];
        }
    }
    return;
}

int get_cumulative(int x1,int y1,int x2,int y2){
    int ans=cumulative[x2][y2];
    if(x1>0)
        ans-=cumulative[x1-1][y2];
    if(y1>0)
        ans-=cumulative[x2][y1-1];
    if(x1>0 && y1>0)
        ans+=cumulative[x1-1][y1-1];
    return ans;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int k,i,j,col,c1,c2;
    long long ans=0;
    vector<int> valid[26];
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        scanf("%s",grid[i]);
    build_cumulative();
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(col=0;col<m;col++){
                if(grid[i][col]==grid[j][col])
                    valid[grid[i][col]-'a'].push_back(col);
            }
            for(col=0;col<26;col++){
                c2=0;
                for(c1=0;c1<valid[col].size();c1++){
                    while(c2<c1 && get_cumulative(i,valid[col][c2],j,valid[col][c1])>k)
                        c2++;
                    ans+=c1-c2;
                }
                valid[col].clear();
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
