#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k, p;
	long long sum = 0;

	cin >> k >> p;

	for(int i = 1; i <= k; i++) {
		string zcy_l = to_string(i), zcy_r(zcy_l);
		reverse(zcy_r.begin(), zcy_r.end());

		sum += stoll(zcy_l + zcy_r)%p, sum %= p;
	}

	cout << sum;

	return 0;
}
