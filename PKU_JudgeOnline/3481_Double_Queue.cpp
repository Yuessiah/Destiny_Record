#include<cstdio>
#include<set>
using namespace std;

struct client {
	int K, P;
	client(int K, int P): K(K), P(P){}
};

struct cmp {
	bool operator()(const client& a, const client& b) { return a.P < b.P; }
};

int op;
set<client, cmp> S;
set<client, cmp>::iterator it;

int main()
{
	while(scanf("%d", &op) && op) {
		if(op == 1) {
			int K, P;
			scanf("%d%d", &K, &P);
			S.insert(client(K, P));
		}
		else if(S.size() > 0) {
			if(op == 2) {
				it = S.end(); --it;
				printf("%d\n", (*it).K);
				S.erase(it);
			}

			if(op == 3) {
				it = S.begin();
				printf("%d\n", (*it).K);
				S.erase(it);
			}
		} else puts("0");
	}

	return 0;
}
