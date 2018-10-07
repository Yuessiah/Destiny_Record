#include<bits/stdc++.h>
using namespace std;

typedef long long int Int;

Int a, b;

int main()
{
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%lld%lld", &a, &b);
    if(a-b > 1) { puts("NO"); continue; }

    Int c = a + b;
    bool prime = true;
    for(int i = 2; i <= (Int)sqrt(c); i++)
      if(c%i == 0) { prime = false; break; }

    puts(prime? "YES" : "NO");
  }

  return 0;
}
