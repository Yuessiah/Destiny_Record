#include<bits/stdc++.h>
using namespace std;

int N;

int main()
{
  cin >> N;

  vector<int> A(N);
  for(int& x: A) cin >> x;


  auto check = [](vector<double> B) {
    vector<double> t{0, 0};
    for(double v: B) t = {t[1], max(t[0], t[1])+v};
    return max(t[0], t[1]);
  };

  {
    double l = 0, r = 1e9;
    for(int t = 0; t < 100; t++) {
      double m = (l+r)/2;
      vector<double> B(N);

      transform(A.begin(), A.end(), B.begin(), [&](int x) { return x-m; });
      if(check(B) >= 0) l = m;
      else r = m;
    }

    cout << fixed << setprecision(15) << (l+r)/2 << endl;
  }

  {
    int l = 0, r = 1e9;
    while(l < r) {
      int m = (l+r+1)/2;
      vector<double> B(N);

      transform(A.begin(), A.end(), B.begin(), [&](int x) { return x<m? -1 : 1; });
      if(check(B) > 0.1) l = m;
      else r = m - 1;
    }

    cout << l << endl;
  }

  return 0;
}
