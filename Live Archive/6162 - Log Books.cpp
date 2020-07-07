#include<cstdio>

bool isNight(int sunrise,int sunset,int st,int ed){
    int dur=ed-st;
    if(st<sunrise && (sunrise-st)*2>=dur)
        return true;
    if(ed>sunset && (ed-sunset)*2>=dur)
        return true;
    return false;
}

int main(){
    int n,h,m,sunrise,sunset,st,ed,tot,night,dur;
    bool valid;
    while(scanf("%d",&n),n!=0){
        valid=1,tot=0,night=0;

        while(n--){
            scanf("%d:%d",&h,&m);
            sunrise=h*60+m;
            scanf("%d:%d",&h,&m);
            sunset=h*60+m;
            scanf("%d:%d",&h,&m);
            st=h*60+m;
            scanf("%d:%d",&h,&m);
            ed=h*60+m;

            dur=ed-st;
            if(dur>120)
                valid=0;
            tot+=dur;
            if(isNight(sunrise,sunset,st,ed))
                night+=dur;
        }

        if(tot<50*60 || night<10*60)
            valid=0;

        if(valid)
            printf("PASS\n");
        else
            printf("NON\n");
    }
    return 0;
}
