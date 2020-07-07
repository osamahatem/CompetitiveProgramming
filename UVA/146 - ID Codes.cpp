#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    char in[100];
    while(1){
        gets(in);
        if(in[0]=='#')
            break;
        if(next_permutation(in,in+strlen(in)))
            printf("%s\n",in);
        else
            printf("No Successor\n");
    }
	return 0;
}
