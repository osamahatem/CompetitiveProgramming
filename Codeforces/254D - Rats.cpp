#include<bits/stdc++.h>

using namespace std;

#define cell(i,j) ((i)*m+(j))

char grid[1005][1005];
set<int> S[2],rats;
int n,m,d,ratsnum,sol[2];
int vis[1000005],vid,currentBomb;
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};
vector<int> emptyCells[2],e;

int findRat(){
    if(rats.empty()) return -1;
    return *rats.begin();
}

bool bfs(int i,int j,bool isBomb){
    queue<int> Q;
    vid++;
    Q.push(cell(i,j));
    vis[cell(i,j)]=vid;

    if(isBomb)
        S[currentBomb].clear();
    else
        emptyCells[currentBomb].clear();
    if(grid[i][j]=='R')
        if(isBomb){
            S[currentBomb].insert(cell(i,j));
            if(!currentBomb) rats.erase(cell(i,j));
        }else
            emptyCells[currentBomb].push_back(cell(i,j));

    for(int s=0;s<d;s++){
        int size=Q.size();
        while(size--){
            i=Q.front()/m;
            j=Q.front()%m;
            Q.pop();
            for(int k=0;k<4;k++){
                int ii=i+di[k];
                int jj=j+dj[k];
                if(grid[ii][jj]=='X' || vis[cell(ii,jj)]==vid)
                    continue;
                if(grid[ii][jj]=='R')
                    if(isBomb){
                        S[currentBomb].insert(cell(ii,jj));
                        if(!currentBomb) rats.erase(cell(ii,jj));
                    }
                if(!isBomb)
                    emptyCells[currentBomb].push_back(cell(ii,jj));
                vis[cell(ii,jj)]=vid;
                Q.push(cell(ii,jj));
            }
        }
    }

    if(isBomb){
        if(currentBomb){    /// After the second bomb explosion
            set<int> ss(S[0].begin(),S[0].end());
            ss.insert(S[1].begin(),S[1].end());
            return ss.size()==ratsnum;
        }else{  /// After the first bomb explosion
            currentBomb++;
            int id=findRat();
            sol[1]=e[e[0]==sol[0]];
            if(id==-1) return true;
            rats.insert(S[0].begin(),S[0].end());
            if(bfs(id/m,id%m,0)) return true;
            currentBomb--;
        }
    }else{  /// Searching for an emplty place to put a bomb
        for(int k=0;k<emptyCells[currentBomb].size();k++){
            int id=emptyCells[currentBomb][k];
            sol[currentBomb]=id;
            if(bfs(id/m,id%m,1)) return true;
        }
    }
    return false;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<n;i++){
        scanf("%s",grid[i]);
        for(int j=0;j<m;j++){
            if(grid[i][j]=='R')
                ratsnum++,rats.insert(cell(i,j));
            if(e.size()<2 && grid[i][j]!='X')
                e.push_back(cell(i,j));
        }
    }
    int id=findRat();
    if(bfs(id/m,id%m,0))
        printf("%d %d %d %d\n",sol[0]/m+1,sol[0]%m+1,sol[1]/m+1,sol[1]%m+1);
    else
        printf("-1\n");
    return 0;
}
