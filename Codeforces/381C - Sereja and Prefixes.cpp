#include<cstdio>
#include<vector>

using namespace std;

struct op{int t,x,l,c;};

int main(){
    int n,q,i,j,c1,c2;
    long long cur,len=0;
    vector<int> frst,ans;
    op all[100005],temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&all[i].t);
        if(all[i].t==1)
            scanf("%d",&all[i].x);
        else
            scanf("%d%d",&all[i].l,&all[i].c);
    }
    j=0;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%I64d",&cur);
        rep:
        temp=all[j];
        if(temp.t==1 && len+1<cur){
            if(frst.size()<100000)
                frst.push_back(temp.x);
            len++;
            j++;
            goto rep;
        }
        if(temp.t==2 && cur>len+(long long)temp.l*(long long)temp.c){
            c1=0,c2=0;
            while(frst.size()<100000){
                frst.push_back(frst[c1]);
                c1++;
                if(c1==temp.l){
                    c1=0;
                    c2++;
                }
                if(c2==temp.c)
                    break;
            }
            len+=(long long)temp.l*(long long)temp.c;
            j++;
            goto rep;
        }
        if(temp.t==1){
            if(frst.size()<100000)
                frst.push_back(temp.x);
            len++;
            ans.push_back(temp.x);
            j++;
        }else{
            ans.push_back(frst[(cur-len-1)%temp.l]);
            if(cur==len+(long long)temp.l*(long long)temp.c){
                c1=0,c2=0;
                while(frst.size()<100000){
                    frst.push_back(frst[c1]);
                    c1++;
                    if(c1==temp.l){
                        c1=0;
                        c2++;
                    }
                    if(c2==temp.c)
                        break;
                }
                len+=(long long)temp.l*(long long)temp.c;
                j++;
            }
        }
    }
    for(i=0;i<ans.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
