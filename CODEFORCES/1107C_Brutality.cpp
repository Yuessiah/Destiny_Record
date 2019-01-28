#include<bits/stdc++.h>
using namespace std;

int const maxn = 2*1e5 + 100;

int n, k, a[maxn];
string s;
long long int sum = 0;

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> s;

  int r = 0;
  while(r < n) {
    int l = r;
    while(r < n && s[l] == s[r]) r++;

    sort(a+l, a+r);
    sum = accumulate(a+max(l, r-k), a+r, sum);
  }

  cout << sum << endl;

  return 0;
}
