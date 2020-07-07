#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n,m;
	scanf("%d%d",&n,&m);
	n=min(n,m);
	printf("%s\n",n&1 ? "Akshat" : "Malvika");

	return 0;
}
