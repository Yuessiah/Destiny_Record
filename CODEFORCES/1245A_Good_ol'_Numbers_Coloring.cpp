#include<bits/stdc++.h>
using namespace std;

int t, a, b;

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &a, &b);
    puts((__gcd(a, b) == 1)? "Finite" : "Infinite");
  }

  return 0;
}
