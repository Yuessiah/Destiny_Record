// This solution is to imitate dotorya's code.
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1e5 + 100;
const long long INF = 0x3f3f3f3f3f3f3f3f;

const char f0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
const char fi[] = "What are you doing while sending \"@\"? Are you busy? Will you send \"@\"?";
const int f0_len = strlen(f0), fi_len = strlen(fi);

long long f_l[maxn]; //length of f_i

char dfs(int n, long long k) {
	if(n == 0) return f0[k];

	for(int c = 0; c < fi_len; c++) {
		if(fi[c] == '@') {
			if(k < f_l[n-1]) return dfs(n-1, k);
			k -= f_l[n-1];
		} else {
			if(k == 0) return fi[c];
			k--;
		}
	}

	return '.';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//init
	f_l[0] = f0_len;
	for(int i = 1; i < maxn; i++) f_l[i] = min(INF, 2*f_l[i-1] + fi_len - 2);

	long long q, n, k;
	cin >> q;

	while(q--) {
		cin >> n >> k;
		if(k > f_l[n]) cout << '.';
		else cout << dfs(n, k-1);
	}

	return 0;
}
