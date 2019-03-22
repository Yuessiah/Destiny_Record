#include<bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);

    string s;
    cin >> s;

    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '<') cnt1++;
      else break;
    }

    int cnt2 = 0;
    for(int i = n-1; i >= 0; i--) {
      if(s[i] == '>') cnt2++;
      else break;
    }

    cout << min(cnt2, cnt1) << endl;
  }

  return 0;
}
