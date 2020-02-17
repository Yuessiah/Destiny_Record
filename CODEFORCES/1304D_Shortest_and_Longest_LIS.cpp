#include<bits/stdc++.h>
using namespace std;

int t, n;
string s;
vector<int> a;

int main()
{
  cin >> t;

  while(t--) {
    cin >> n >> s;
    s += '\0';

    int cnt = 0;
    a.resize(n);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
      if(s[i] == '<') cnt++;
      else if(i && s[i] != s[i-1]) {
        reverse(a.begin()+i-cnt, a.begin()+i+1);
        cnt = 0;
      }
    }
    for(int x: a) printf("%d ", x);
    putchar('\n');


    cnt = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
      if(s[i] == '>') cnt++;
      else if(i && s[i] != s[i-1]) {
        reverse(a.begin()+i-cnt, a.begin()+i+1);
        cnt = 0;
      }
    }
    for(int x: a) printf("%d ", x);
    putchar('\n');
  }

  return 0;
}
