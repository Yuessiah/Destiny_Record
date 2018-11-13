#include<bits/stdc++.h>
using namespace std;

typedef long long int Int;

enum { LEFT, RIGHT };

int N, Q;
Int X[3], A1, B1, C1, M1;
Int Y[3], A2, B2, C2, M2;
Int Z[3], A3, B3, C3, M3;
vector<pair<Int, Int> > LR, K; //LR := left-closed and right-open interval

int main()
{
  int T, kase = 0;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d", &N, &Q);
    scanf("%lld%lld%lld%lld%lld%lld", &X[1], &X[2], &A1, &B1, &C1, &M1);
    scanf("%lld%lld%lld%lld%lld%lld", &Y[1], &Y[2], &A2, &B2, &C2, &M2);
    scanf("%lld%lld%lld%lld%lld%lld", &Z[1], &Z[2], &A3, &B3, &C3, &M3);

    //initialization
    LR.clear();
    K.clear();

    for(int i = 1; i <= N; i++) {
      if(i <= 2) {
        LR.emplace_back(min(X[i], Y[i]) + 1, LEFT);
        LR.emplace_back(max(X[i], Y[i]) + 2, RIGHT);
        continue;
      }

      Int Xi = (A1*X[2] + B1*X[1] + C1) % M1;
      Int Yi = (A2*Y[2] + B2*Y[1] + C2) % M2;
      LR.emplace_back(min(Xi, Yi) + 1, LEFT);
      LR.emplace_back(max(Xi, Yi) + 2, RIGHT);
      X[1] = X[2], X[2] = Xi;
      Y[1] = Y[2], Y[2] = Yi;
    }

    for(int i = 1; i <= Q; i++) {
      if(i <= 2) {
        K.emplace_back(Z[i] + 1, i);
        continue;
      }

      Int Zi = (A3*Z[2] + B3*Z[1] + C3) % M3;
      K.emplace_back(Zi+1, i);
      Z[1] = Z[2], Z[2] = Zi;
    }

    //solution
    sort(LR.rbegin(), LR.rend());
    sort(K.rbegin(), K.rend());

    Int r_val = 0, intvl = 0, past = 0, ans = 0; //r_val := right-value is arbitrary selected initially, intvl := intervals
    for(auto it: LR) {
      Int l_val = it.first;
      Int len = r_val - l_val, total = len * intvl;

      while(!K.empty()) {
        Int rank = K.back().first - past;

        if(rank <= total) {
          ans += K.back().second * ((r_val-1) - (rank-1)/intvl);
          K.pop_back();
        } else break;
      }

      past += total;
      if(it.second == RIGHT) intvl++;
      if(it.second == LEFT ) intvl--;
      r_val = l_val;
    }

    printf("Case #%d: %lld\n", ++kase, ans);
  }

  return 0;
}
