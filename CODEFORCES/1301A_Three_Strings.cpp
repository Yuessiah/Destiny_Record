#include<bits/stdc++.h>
using namespace std;

int t;
string a, b, c;

int main()
{
  scanf("%d", &t);
  while(t--) {
    cin >> a >> b >> c;

    bool ok = true;
    for(int i = 0; i < a.length(); i++) {
      if(a[i] != c[i] && b[i] != c[i]) {
        ok = false;
        break;
      }
    }

    puts(ok? "YES" : "NO");
  }

  return 0;
}
