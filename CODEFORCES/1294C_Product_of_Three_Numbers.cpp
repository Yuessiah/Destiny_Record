#include<bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);

    int N = n;
    vector<int> fac;
    for(int p = 2; p*p <= N; p++) {
      if(N%p == 0) {
        fac.push_back(p);
        N /= p;
      }
    }
    if(!fac.empty() && N > fac.back()) fac.push_back(N);

    if(fac.size() >= 3) {
      puts("YES");
      printf("%d %d %d\n", fac[0], fac[1], n/(fac[0]*fac[1]));
    } else puts("NO");
  }

  return 0;
}
