#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
  scanf("%d", &n);

  set<int> S;
  while(!S.count(n)) {
    S.insert(n);

    n++;
    while(n % 10 == 0) n /= 10;
  }

  printf("%d\n", S.size());

  return 0;
}
