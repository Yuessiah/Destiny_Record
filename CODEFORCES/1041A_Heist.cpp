#include<bits/stdc++.h>
using namespace std;

int N;

int main()
{
  scanf("%d", &N);

  int a, mini = 1e9+10, maxi = 0;
  for(int i = 0; i < N; i++) {
    scanf("%d", &a);
    mini = min(a, mini);
    maxi = max(a, maxi);
  }

  printf("%d", (maxi - mini + 1) - N);

  return 0;
}
