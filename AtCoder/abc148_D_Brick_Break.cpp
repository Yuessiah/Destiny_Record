#include<bits/stdc++.h>
using namespace std;

int N, a;

int main()
{
  scanf("%d", &N);

  int x = 1;
  for(int i = 0; i < N; i++) {
    scanf("%d", &a);
    if(a == x) x++;
  }
  x--;

  printf("%d\n", x==0? -1 : N - x);

  return 0;
}
