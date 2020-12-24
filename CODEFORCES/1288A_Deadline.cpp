#include<bits/stdc++.h>
using namespace std;

int T, n, d;

int main()
{
  cin >> T;
  while(T--) {
    cin >> n >> d;

    int s1 = ceil(sqrt(d)), s2 = sqrt(d);
    int b1 = ceil(s1-1 + (double)d/s1);
    int b2 = ceil(s2-1 + (double)d/s2);

    if(s1 <= n && b1 <= n) puts("YES");
    else if(s2 <= n && b2 <= n) puts("YES");
    else puts("NO");
  }

  return 0;
}
