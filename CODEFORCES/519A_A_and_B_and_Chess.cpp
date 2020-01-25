#include<bits/stdc++.h>
using namespace std;

char p;

int main()
{
  int d = 0;
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++) {
      scanf(" %c", &p);
      if(p == 'q') d -= 9;
      if(p == 'r') d -= 5;
      if(p == 'b') d -= 3;
      if(p == 'n') d -= 3;
      if(p == 'p') d -= 1;
      if(p == 'Q') d += 9;
      if(p == 'R') d += 5;
      if(p == 'B') d += 3;
      if(p == 'N') d += 3;
      if(p == 'P') d += 1;
    }

  if(d >  0) puts("White");
  if(d == 0) puts("Draw");
  if(d <  0) puts("Black");

  return 0;
}
