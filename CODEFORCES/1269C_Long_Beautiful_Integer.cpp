#include<bits/stdc++.h>
using namespace std;

int n, k;
string a, b;

int main()
{
  cin >> n >> k >> a;

  for(int i = 0; i < n; i++) b += a[i%k];
  if(b < a) {
    for(int i = k-1; i >= 0; i--) {
      if(b[i] == '9') b[i] = '0';
      else { b[i]++; break; }
    }

    for(int i = k; i < n; i++) b[i] = b[i-k];
  }

  cout << n << endl;
  cout << b << endl;

  return 0;
}
