#include<bits/stdc++.h>
using namespace std;

typedef long long int Int;

int const maxn = 55;
Int INF = pow(2, maxn);

int N, P;

int main() {
  int T, kase = 0;
  cin >> T;

  while(T--) {
    cin >> N >> P;

    string s;
    vector<string> S;
    for(int i = 0; i < P; i++) {
      cin >> s;
      for(int j = s.size(); j < N; j++) s.push_back('Z'); // keep same size
      S.push_back(s);
    }

    sort(S.rbegin(), S.rend()); // neighbor the same prefix

    Int ans = pow(2, N);
    string lowest('Z', N);

    for(int i = 0; i < P; i++) {
      s =  S[i].substr(0, lowest.size());
      if(lowest != s) { // prefixes are not same
        int size = 0;
        for(int j = 0; S[i][j] != 'Z' && j < S[i].size(); j++) size++;
        lowest = S[i].substr(0, size);
        ans -= pow(2, N-size);
      }
    }

    printf("Case #%d: %lld\n", ++kase, ans);
  }

  return 0;
}
