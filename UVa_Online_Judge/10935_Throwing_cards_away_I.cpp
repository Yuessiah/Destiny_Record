#include<cstdio>
#include<deque>
#include<vector>
using namespace std;

deque<int> cards;
vector<int> discard;
int n;

int main()
{
	while(scanf("%d", &n) && n) {
		discard.resize(0);
		cards.resize(0);
		for(int i = 1; i <= n; i++) cards.push_back(i);

		int draw;
		while(1) {
			draw = cards.front();
			if(cards.size() == 1) break;
			cards.pop_front();
			discard.push_back(draw);

			draw = cards.front();
			cards.pop_front();
			if(cards.empty()) break;
			cards.push_back(draw);
		}

		printf("Discarded cards:");
		for(int i = 0; i < discard.size(); i++) {
			if(!i) putchar(' ');
			printf("%d", discard[i]);
			if(i < discard.size()-1) printf(", ");
		} putchar('\n');

		printf("Remaining card: %d\n", draw);
	}
}
