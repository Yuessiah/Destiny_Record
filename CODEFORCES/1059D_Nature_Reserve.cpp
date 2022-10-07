#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int n;
double x[maxn], y[maxn];

int main()
{
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];

    if(y[i]*y[0] < 0) {
      cout << -1 << endl;
      return 0;
    }
  }


  auto check = [](double r) {
    double d_mi = -1e7, d_mx = 1e7;
    for(int i = 0; i < n; i++) {
      if(2*r < abs(y[i])) return false;

      double d = sqrt(abs(y[i])*(2*r - abs(y[i])));
      d_mi = max(d_mi, x[i]-d);
      d_mx = min(d_mx, x[i]+d);

      if(d_mx < d_mi) return false;
    }

    return true;
  };

  double l = 0, r = 1e14;
  for(int t = 0; t < 100; t++) {
    double m = (l+r)/2;
    if(check(m)) r = m;
    else l = m;
  }

  cout << fixed << setprecision(15) << l << endl;

  return 0;
}

