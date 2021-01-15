#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int const MOD = 1000000007;

int T, N;

Int exp(Int a, int e) {
  Int x = 1;
  while(e) {
    if(e&1) (x *= a) %= MOD;
    (a *= a) %= MOD;
    e >>= 1;
  }
  return x;
}

int main()
{
  cin >> T;

  int kase = 0;
  while(T--) {
    cin >> N;

    vector<int> K(N);
    for(int i = 0; i < N; i++) cin >> K[i];

    sort(K.begin(), K.end());

    int sum = 0;
    for(int i = 0; i < N; i++)
      sum = (sum + (exp(2, i) - exp(2, N-1-i) + MOD) % MOD * K[i]) % MOD;

    cout << "Case #" << ++kase << ": " << sum << endl;
  }

  return 0;
}
