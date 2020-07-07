#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct triple{
    int cube;
    int a;
    int b;
    int c;
}triple;

bool cmp(triple a,triple b){
    if(a.cube!=b.cube) return a.cube<b.cube;
    if(a.a!=b.a) return a.a<b.a;
    if(a.b!=b.b) return a.b<b.b;
    return a.c<b.c;
}

int main(){
    int cube,a,b,c;
    triple temp;
    vector<triple> answer;
    for(a=2;a<=200;a++)
        for(b=a;b<=200;b++)
            for(c=b;c<=200;c++){
                cube=floor(pow((a*a*a+b*b*b+c*c*c),1.0/3.0)+0.5);
                if((cube*cube*cube)==(a*a*a+b*b*b+c*c*c) && cube<=200){
                    temp.cube=cube;
                    temp.a=a;
                    temp.b=b;
                    temp.c=c;
                    answer.push_back(temp);
                }
            }
    sort(answer.begin(),answer.end(),cmp);
    for(a=0;a<answer.size();a++){
        printf("Cube = %d, Triple = (%d,%d,%d)\n",answer[a].cube,answer[a].a,answer[a].b,answer[a].c);
    }
    return 0;
}
