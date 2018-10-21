#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int N, a[maxn];

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%d", &N);

    int cnt = 0;
    for(int i = 0; i < N; i++) {
      scanf("%d", &a[i]);
      if(i && a[i-1] > a[i]) cnt++;
    }
    if(a[N-1] > a[0]) cnt++;

    puts((cnt <= 1)? "YES" : "NO");
  }

  return 0;
}
