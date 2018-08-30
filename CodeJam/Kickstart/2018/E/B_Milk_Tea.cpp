#include<bits/stdc++.h>
using namespace std;

int const maxp = 110;

int N, M, P, one[maxp];
set<string> ban;
string pf; //preference

int main()
{
  int T, kase = 0;
  cin >> T;

  while(T--) {
    //init
    memset(one, 0, sizeof(one));
    ban.clear();

    cin >> N >> M >> P;

    for(int i = 0; i < N; i++) {
      cin >> pf;
      for(int j = 0; j < P; j++) if(pf[j] == '1') one[j]++;
    }

    for(int i = 0; i < M; i++) {
      cin >> pf;
      ban.insert(pf);
    }

    //solve
    priority_queue<pair<int, string> > span;
    span.emplace(0, "");

    for(int i = 0; i < P; i++) {
      priority_queue<pair<int, string> > seed;
      swap(seed, span);

      while(!seed.empty()) {
        int cp; //complaints
        string op; //options
        tie(cp, op) = seed.top(); seed.pop();

        span.emplace(cp+one[i],     op+"0");
        span.emplace(cp+(N-one[i]), op+"1");
      }

      while(span.size() > M+1) span.pop();
    }

    int ans;
    while(!span.empty()) {
      if(!ban.count((span.top()).second)) ans = (span.top()).first;
      span.pop();
    }

    cout << "Case #" << ++kase << ": " << ans << endl;
  }

  return 0;
}
