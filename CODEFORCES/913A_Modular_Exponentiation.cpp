#include<bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
  scanf("%d%d", &n, &m);
  printf("%d\n", n < 30? m%(1<<n) : m);

  return 0;
}
