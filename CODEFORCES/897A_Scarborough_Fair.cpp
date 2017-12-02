#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, l, r;
	char a, b;
	string s;

	cin >> n >> m >> s;

	while(m--) {
		cin >> l >> r >> a >> b;
		for(int i = l; i <= r; i++) if(s[i-1] == a) s[i-1] = b;
	}

	cout << s;

	return 0;
}
