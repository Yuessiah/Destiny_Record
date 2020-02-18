#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
  cin >> s;

  long long best = 0;
  for(char a = 'a'; a <= 'z'; a++) {
    for(char b = 'a'; b <= 'z'; b++) {
      long long cnt = 0, res = 0;
      for(int i = 0; i < s.length(); i++) {
        if(s[i] == b) res += cnt;
        if(s[i] == a) cnt++;
      }

      best = max(best, max(res, cnt));
    }
  }

  printf("%lld\n", best);

  return 0;
}
