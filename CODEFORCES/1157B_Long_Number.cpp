#include<bits/stdc++.h>
using namespace std;

int n, f[10];
string a;

int main()
{
  cin >> n >> a;
  for(int i = 1; i <= 9; i++) cin >> f[i];

  for(int i = 0; i < n; i++) {
    int d = a[i] - '0';

    if(f[d] > d) {
      do {
        d = a[i] - '0';
        if(f[d] < d) break;
        a[i] = f[d] + '0';
      } while(++i != n);

      break;
    }
  }

  cout << a << endl;

  return 0;
}
