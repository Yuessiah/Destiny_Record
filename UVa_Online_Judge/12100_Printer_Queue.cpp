#include<cstdio>
#include<queue>
using namespace std;

struct job {
	int priority, position;
};

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		queue<job> Q;
		priority_queue<int> PQ;

		int n, m;
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; i++) {
			job J;
			scanf("%d", &J.priority);
			J.position = i;
			Q.push(J); PQ.push(J.priority);
		}

		int minute = 0;
		while(!Q.empty()) {
			job J = Q.front(); Q.pop();

			if(PQ.top() != J.priority) Q.push(J);
			else {
				minute++;
				if(J.position == m) { printf("%d\n", minute); break; }
				PQ.pop();
			}
		}
	}

	return 0;
}
