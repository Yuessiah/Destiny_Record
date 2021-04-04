#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

Int constexpr maxx = 1e13 + 100;
int constexpr maxn = 1e5 + 10;

int n;
Int x[maxn];

int main()
{
  cin >> n;
  for(int i = 1; i < n; i+=2) cin >> x[i];

  set<Int> s;
  for(Int d = 1; d*d < maxx; d++) s.insert(d*d);

  int i = 0;
  Int sum = 0;
  for(auto it = s.begin(); it != s.end(); it++) {
    if(!s.count(*it + x[i+1])) continue;
    x[i] = *it-sum;

    it = s.find(sum + x[i] + x[i+1]);
    sum += x[i] + x[i+1];
    i += 2;

    if(i >= n) break;
  }

  if(i < n) puts("No");
  else {
    puts("Yes");
    for(int i = 0; i < n; i++) cout << x[i] << ' ';
    cout << endl;
  }

  return 0;
}
