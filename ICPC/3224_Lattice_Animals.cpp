#include<bits/stdc++.h>
#define R first
#define C second
using namespace std;

const int lim = 10, INF = 0x3f3f3f3f;
const int dr[] = { 0, 0, -1, 1 }, dc[] = { -1, 1, 0, 0 };

typedef pair<int, int> pos;
typedef set<pos> shape;
typedef set<shape> polyominoes[lim+1];

int n, h, w, ans[lim+1][lim+1][lim+1];
polyominoes P;

shape normalize(shape poly)
{
	int minr = INF, minc = INF;
	for(auto it: poly) {
		minr = min(minr, it.R);
		minc = min(minc, it.C);
	}

	shape new_poly;
	for(auto it: poly) new_poly.insert(make_pair(it.R-minr, it.C-minc));

	return new_poly;
}

shape flip(shape poly)
{
	shape new_poly;
	for(auto it: poly) new_poly.insert(make_pair(-it.R, it.C));

	return normalize(new_poly);
}

shape rotate(shape poly)
{
	shape new_poly;
	for(auto it: poly) new_poly.insert(make_pair(it.C, -it.R));

	return normalize(new_poly);
}

void try_to_insert(shape poly)
{
	int N = poly.size();
	poly = normalize(poly);
	shape tmp(poly);

	int two = 2; while(two--) {
		int four = 4; while(four--) {
			if(P[N].count(tmp)) return;
			tmp = rotate(tmp);
		}
		if(two) tmp = flip(tmp);
	}

	P[N].insert(poly);
}


void create()
{
	shape _1_poly; _1_poly.insert(make_pair(0, 0));
	P[1].insert(_1_poly);

	for(int N = 2; N <= lim; N++)
		for(auto S: P[N-1]) for(auto it: S) {
			for(int di = 0; di < 4; di++) {
				int rn = it.R + dr[di], cn = it.C + dc[di];
				shape _N_poly(S);
				_N_poly.insert(make_pair(rn, cn));
				try_to_insert(_N_poly);
			}
		}

	for(int N = 1; N <= lim; N++)
		for(int H = 1; H <= lim; H++) for(int W = 1; W <= lim; W++) {
			ans[N][W][H] = 0;

			for(auto S: P[N]) {
				int maxr = 0, maxc = 0;
				for(auto it: S) {
					maxr = max(maxr, it.R);
					maxc = max(maxc, it.C);
				}
				if(min(maxr,maxc) < min(H,W) && max(maxr,maxc) < max(H,W)) ans[N][W][H]++;
			}
		}
}


int main()
{
	create();
	while(~scanf("%d%d%d", &n, &w, &h)) printf("%d\n", ans[n][w][h]);

	return 0;
}
