#include<bits/stdc++.h>
using namespace std;

int L;
string A, B;

int main()
{
  int T, kase = 0;
  cin >> T;

  while(T--) {
    cin >> L >> A >> B;

    int ans = 0;
    for(int i = 0; i < L; i++) for(int j = i+1; j <= L; j++) {
      int len = j-i;

      string C(A.substr(i, len));
      sort(C.begin(), C.end());

      for(int k = 0; k < L-len+1; k++) {
        string D(B.substr(k, len));
        sort(D.begin(), D.end());

        if(C == D) { ans++; break; }
      }
    }

    cout << "Case #" << ++kase << ": " << ans << endl;
  }

  return 0;
}
