#include<bits/stdc++.h>
using namespace std;

string const gen = "ACTG";

int n;
string s;

int main()
{
  cin >> n >> s;

  int mi = 4*26;
  for(int i = 0; i < s.length()-3; i++) {
    int sum = 0;
    for(int j = 0; j < 4; j++) {
      int d = abs(s[i+j] - gen[j]);
      sum += min(d, 26-d);
    }

    mi = min(mi, sum);
  }

  cout << mi << endl;

  return 0;
}
