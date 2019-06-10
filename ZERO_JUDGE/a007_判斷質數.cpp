#include<bits/stdc++.h>
using namespace std;

int const maxn = 7e5;

int x;
bool is_p[maxn];
vector<int> prime;

int main()
{
  fill(is_p, is_p+maxn, true);

  for(int n = 2; n < maxn; n++) {
    if(is_p[n]) prime.push_back(n);

    for(long long p: prime) {
      if(p*n >= maxn) break;

      is_p[p*n] = false;
      if(n%p == 0) break;
    }
  }


  while(~scanf("%d", &x)) {
    bool ok = true;

    for(long long p: prime) {
      if(p*p > x) break;
      if(x%p == 0) { ok = false; break; }
    }

    puts(ok? "質數" : "非質數");
  }

  return 0;
}
