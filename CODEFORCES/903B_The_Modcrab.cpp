#include<bits/stdc++.h>
using namespace std;

int main()
{
	int h1, a1, c1, h2, a2;
	scanf("%d%d%d%d%d", &h1, &a1, &c1, &h2, &a2);

	vector<string> p;
	while(1) {
		if(h2 <= a1) {
			p.push_back("STRIKE");

			cout << p.size() << endl;
			for(int i = 0, l = p.size(); i < l; i++) cout << p[i] << endl;

			return 0; //the monster has died!
		} else if(h1 <= a2) {
			h1 += c1;
			p.push_back("HEAL");
		} else {
			h2 -= a1;
			p.push_back("STRIKE");
		}
		h1 -= a2;
	}
}
