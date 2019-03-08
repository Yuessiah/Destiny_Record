#include<bits/stdc++.h>
using namespace std;

int h1, h2, m1, m2;

int main()
{
  scanf("%d:%d", &h1, &m1);
  scanf("%d:%d", &h2, &m2);

  m1 += h1 * 60;
  m2 += h2 * 60;

  int m3 = (m1 + m2)/2;

  printf("%02d:%02d\n", m3/60, m3%60);

  return 0;
}
