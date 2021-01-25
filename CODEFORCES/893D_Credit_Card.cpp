#include<bits/stdc++.h>
using namespace std;

int n, d, a;

int main()
{
  cin >> n >> d;

  bool ok = true;
  int dep = 0, tran = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> a;

    tran += a;
    if(tran > d) ok = false;

    if(a == 0 && tran < 0) {
      if(-tran > dep) ans++, dep = d;
      else dep += tran;
      tran = 0;
    }

    dep = min(dep, d - tran); // deposit + transaction <= d
  }

  printf("%d\n", ok? ans : -1);

  return 0;
}
