#include<cstdio>
#include<map>
#include<string>

using namespace std;

int main(){
    int n;
    char buffer[100];
    string country;
    map<string,int> counter;
    map<string,int>::iterator i;
    scanf("%d\n",&n);
    while(n--){
        scanf("%s",buffer);
        country=string(buffer);
        gets(buffer);
        counter[country]++;
    }
    for(i=counter.begin();i!=counter.end();i++){
        printf("%s %d\n",i->first.c_str(),i->second);
    }
    return 0;
}
