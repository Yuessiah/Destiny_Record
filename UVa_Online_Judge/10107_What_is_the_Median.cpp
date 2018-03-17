#include<cstdio>
#include<vector>
#include<algorithm>
using std::vector;
using std::nth_element;

int main()
{
	vector<int> V;
	int e, l, r;

	while(~scanf("%d", &e)) {
		V.push_back(e);

		nth_element(V.begin(), V.begin() + V.size()/2, V.end());
		nth_element(V.begin(), V.begin() + V.size()/2 - !(V.size()&1), V.end());
		l = V.at(V.size()/2);
		r = V.at(V.size()/2 - !(V.size()&1));

		if(V.size()&1) printf("%d\n", r);
		else printf("%d\n", (l+r)/2);
	}

	return 0;
}
