#include<iostream>
#include<string>
using namespace std;

int const maxn = 1e6 + 10;

int q, n;
long long k;
string a;

int main()
{
  cin >> q;

  while(q--) {
    cin >> n >> k >> a;

    for(int i = 0, l = 0; i < n; i++) {
      if(a[i] != '0') continue;

      if(i-l >= k) { swap(a[i], a[i-k]); break; }

      k -= i-l;
      swap(a[i], a[l]);
      l++;
    }

    cout << a << endl;
  }

  return 0;
}
