#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int len;
char temp[210];
vector<string> path;

void editpath(){
    int i=0;
    string dir;
    len=strlen(temp);
    if(temp[i]=='/')
        path.clear();
    while(i<len){
        dir.clear();
        while(temp[i]!='/' && i<len){
            dir+=temp[i];
            i++;
        }
        i++;
        if(dir=="..")
            path.pop_back();
        else if(dir.size()>0)
            path.push_back(dir);
    }
    return;
}

int main(){
    int n,i;
    scanf("%d",&n);
    while(n--){
        scanf("%s",temp);
        len=strlen(temp);
        if(len==3){
            i=0;
            while(1){
                printf("/");
                if(i>=path.size())
                    break;
                printf("%s",path[i].c_str());
                i++;
            }
            printf("\n");
        }else{
            scanf("%s",temp);
            editpath();
        }
    }
    return 0;
}
