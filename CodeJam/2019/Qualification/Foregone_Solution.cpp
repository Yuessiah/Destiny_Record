#include<bits/stdc++.h>
using namespace std;

int T, kase = 0;
string N, A, B;

int main()
{
  cin >> T;

  while(T--) {
    A.clear(); B.clear();

    cin >> N;

    for(auto &c: N) {
      if(c == '4') {
        A.push_back('2');
        B.push_back('2');
      } else {
        A.push_back(c);
        B.push_back('0');
      }
    }

    for(int i = 0; i < B.length(); i++)
      if(B[i] != '0') {
        B = B.substr(i);
        break;
      }

    cout << "Case #" << ++kase << ": " << A << ' ' << B << '\n';
  }

  return 0;
}
