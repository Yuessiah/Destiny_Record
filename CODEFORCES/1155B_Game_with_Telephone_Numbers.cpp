#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
  cin >> n >> s;

  int m = n - 11; // total moves
  int v = m/2 + (m&1); // Vasya
  int p = m/2; // Petya

  string tel; // telephone number
  for(int i = 0; i < n; i++) {
    int d = s[i] - '0';
    if(d == 8 && p) p--;
    else if(d != 8 && v) v--;
    else tel.push_back(s[i]);
  }

  if(tel[0] == '8') puts("YES");
  else puts("NO");

  return 0;
}
