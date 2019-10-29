#include<bits/stdc++.h>
using namespace std;

int Q, n;
string s;

int main()
{
  scanf("%d", &Q);

  while(Q--) {
    scanf("%d", &n);

    int ev = 0; // even length
    bool od = false; // odd length
    for(int i = 0; i < n; i++) {
      cin >> s;

      int one = 0;
      for(int k = 0; k < s.size(); k++) if(s[k] == '1') one++;

      if(!(s.size()&1) && (one&1)) ev++;
      if(s.size()&1) od = true;
    }

    if(od) printf("%d\n", n);
    else printf("%d\n", n-ev%2);
  }

  return 0;
}
