#include<iostream>
#include<string>
using namespace std;

int t, n, a, b, c;
string B; // Bob

int main()
{
  cin >> t;

  while(t--) {
    cin >> n >> a >> b >> c;
    cin >> B;

    string A(n, '?'); // Alice
    for(int i = 0; i < n; i++) {
      if(B[i] == 'R' && b) b--, A[i] = 'P';
      if(B[i] == 'P' && c) c--, A[i] = 'S';
      if(B[i] == 'S' && a) a--, A[i] = 'R';
    }

    if(a+b+c > n/2) puts("NO");
    else {
      for(auto& ch: A) if(ch == '?') {
        if(a) a--, ch = 'R';
        else if(b) b--, ch = 'P';
        else if(c) c--, ch = 'S';
      }

      cout << "YES\n" << A << endl;
    }
  }

  return 0;
}
