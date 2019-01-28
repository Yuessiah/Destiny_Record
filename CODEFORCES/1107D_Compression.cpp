#include<bits/stdc++.h>
using namespace std;

int const maxn = 5300;

int n;
string in, s[maxn];

int main()
{
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    cin >> in;
    for(auto &it : in) {
      if(it == '0') s[i] += "0000";
      if(it == '1') s[i] += "0001";
      if(it == '2') s[i] += "0010";
      if(it == '3') s[i] += "0011";
      if(it == '4') s[i] += "0100";
      if(it == '5') s[i] += "0101";
      if(it == '6') s[i] += "0110";
      if(it == '7') s[i] += "0111";
      if(it == '8') s[i] += "1000";
      if(it == '9') s[i] += "1001";
      if(it == 'A') s[i] += "1010";
      if(it == 'B') s[i] += "1011";
      if(it == 'C') s[i] += "1100";
      if(it == 'D') s[i] += "1101";
      if(it == 'E') s[i] += "1110";
      if(it == 'F') s[i] += "1111";
    }
  }

  //for(int i = 0; i < n; i++) cout << s[i] << endl;

  int len = n;

  for(int i = 0, k = 1; i < n; i+=k, k=1) {
    while(i+k < n && s[i] == s[i+k]) k++;
    len = __gcd(len, k);
  }

  for(int i = 0; i < n; i++) {
    for(int l = 0, r = 1; l < n; l=r) {
      while(r < n && s[i][l] == s[i][r]) r++;
      len = __gcd(len, r-l);
    }
  }

  cout << len << endl;

  return 0;
}
