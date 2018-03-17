#include<cstdio>
#include<map>
#include<string>
using std::map;
using std::string;

const int maxc = 76;

int main()
{
	int n;

	while (~scanf("%d", &n)) {
		map<string, int> country;

		char input[maxc];
		while (n--) {
			scanf("%s", input);
			while (getchar() != '\n');
			if (country.count(input)) country[input]++;
			else country[input] = 1;
		}

		for (auto it: country) printf("%s %d\n", it.first.c_str(), it.second);
	}

	return 0;
}
