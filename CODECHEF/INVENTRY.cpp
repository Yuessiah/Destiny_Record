#include<bits/stdc++.h>
using namespace std;

int N;
string S;

int main()
{
  int T;
  cin >> T;

  while(T--) {
    cin >> N >> S;

    long long int ans = 0;
    int need = 0, dot = 0, i = 0;

    for(; i < N && S[i] == '#'; i++);
    for(; i < N; i++) {
      if(S[i] == '#') ans += 2*need + dot, need++;
      if(S[i] == '.') dot++, need -= !!need; // need can't less than 0
    }

    if(need > 0) puts("-1");
    else printf("%lld\n", ans);
  }

  return 0;
}
