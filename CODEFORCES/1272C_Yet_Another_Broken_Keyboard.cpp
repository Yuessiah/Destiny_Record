#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;
bool c[256];

int main()
{
  cin >> n >> k >> s;

  char p;
  while(k-- && cin >> p) c[p] = true;

  long long sum = 0;
  for(int l = 0, r = 0; r < n; r++, l=r) {
    while(r < n && c[s[r]]) r++;
    sum += (r-l)*(r-l+1ll)/2;
  }

  printf("%lld\n", sum);

  return 0;
}
