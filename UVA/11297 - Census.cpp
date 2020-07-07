#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct node{
    int maxi,mini;
}node;

int arr[501][501];
node tree[1000000],ans;

void build(int n,int sx,int sy,int ex,int ey,bool flag){
    if(sx==ex && sy==ey){
        tree[n].maxi=arr[sx][sy];
        tree[n].mini=arr[sx][sy];
        return;
    }
    int mx=(sx+ex)/2,my=(sy+ey)/2;
    if((flag && sx!=ex) || sy==ey){
        build(n*2,sx,sy,mx,ey,!flag);
        build(n*2+1,mx+1,sy,ex,ey,!flag);
    }else if((!flag && sy!=ey) || sx==ex){
        build(n*2,sx,sy,ex,my,!flag);
        build(n*2+1,sx,my+1,ex,ey,!flag);
    }
    tree[n].maxi=max(tree[n*2].maxi,tree[n*2+1].maxi);
    tree[n].mini=min(tree[n*2].mini,tree[n*2+1].mini);
    return;
}

void query(int n,int sx,int sy,int ex,int ey,int &x1,int &y1,int &x2,int &y2,bool flag){
    if(sx>x2 || ex<x1 || sy>y2 || ey<y1)
        return;
    if(sx>=x1 && ex<=x2 && sy>=y1 && ey<=y2){
        ans.maxi=max(ans.maxi,tree[n].maxi);
        ans.mini=min(ans.mini,tree[n].mini);
        return;
    }
    int mx=(sx+ex)/2,my=(sy+ey)/2;
    if((flag && sx!=ex) || sy==ey){
        query(n*2,sx,sy,mx,ey,x1,y1,x2,y2,!flag);
        query(n*2+1,mx+1,sy,ex,ey,x1,y1,x2,y2,!flag);
    }else if((!flag && sy!=ey) || sx==ex){
        query(n*2,sx,sy,ex,my,x1,y1,x2,y2,!flag);
        query(n*2+1,sx,my+1,ex,ey,x1,y1,x2,y2,!flag);
    }
    return;
}

void update(int n,int sx,int sy,int ex,int ey,int &x,int &y,int &v,bool flag){
    if(sx>x || ex<x || sy>y || ey<y)
        return;
    if(sx==ex && sy==ey){
        tree[n].maxi=v;
        tree[n].mini=v;
        arr[sx][sy]=v;
        return;
    }
    int mx=(sx+ex)/2,my=(sy+ey)/2;
    if((flag && sx!=ex) || sy==ey){
        update(n*2,sx,sy,mx,ey,x,y,v,!flag);
        update(n*2+1,mx+1,sy,ex,ey,x,y,v,!flag);
    }else if((!flag && sy!=ey) || sx==ex){
        update(n*2,sx,sy,ex,my,x,y,v,!flag);
        update(n*2+1,sx,my+1,ex,ey,x,y,v,!flag);
    }
    tree[n].maxi=max(tree[n*2].maxi,tree[n*2+1].maxi);
    tree[n].mini=min(tree[n*2].mini,tree[n*2+1].mini);
    return;
}

int main(){
    int n,m,i,j,q,x1,y1,x2,y2,v;
    char c;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
    build(1,0,0,n-1,m-1,0);
    scanf("%d\n",&q);
    for(i=0;i<q;i++){
        scanf("%c",&c);
        if(c=='q'){
            scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
            ans.maxi=arr[x1-1][y1-1],ans.mini=arr[x1-1][y1-1];
            query(1,0,0,n-1,m-1,--x1,--y1,--x2,--y2,0);
            printf("%d %d\n",ans.maxi,ans.mini);
        }else{
            scanf("%d%d%d\n",&x1,&y1,&v);
            update(1,0,0,n-1,m-1,--x1,--y1,v,0);
        }
    }
	return 0;
}
