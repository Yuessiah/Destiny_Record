#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > PQ;

int main()
{
	while(scanf("%d", &N) && N) {
		while(N--) {
			int num;
			scanf("%d", &num);
			PQ.push(num);
		}

		int cost = 0;
		while(PQ.size() != 1) {
			int a = PQ.top(); PQ.pop();
			int b = PQ.top(); PQ.pop();
			cost += a += b;
			PQ.push(a);
		} PQ.pop();

		printf("%d\n", cost);
	}

	return 0;
}
