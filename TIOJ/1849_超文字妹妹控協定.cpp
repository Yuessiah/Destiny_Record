#include<bits/stdc++.h>
using namespace std;

const int maxs = 100 + 5;
const unsigned int hsize = 1572869; //a prime

map<string, string> imouto[hsize];
hash<string> hstr;

void status(const int &code, char *name) {
	printf("\'%d ", code);
	if(code == 200) printf("ONiiChaN!");
	if(code == 201) printf("HaJiMeMaShiTe");
	if(code == 202) printf("SaYouNaRa");
	if(code == 403) printf("IMouTo Unhappy!");
	if(code == 404) printf("IMouTo Not Found!");
	printf("\',\'%s\'", name);
}

int main()
{
	int n;
	scanf("%d%*c", &n);

	while(n--) {
		char name[maxs], text[maxs], c;
		int hcmd = 0; //hash the command string
		while((c = getchar()) && c != ',') hcmd ^= (c=='\'')? 0 : (c|' '); //tolower
		scanf(" '%[^,\n']'%*c", name);

		unsigned int key = hstr(name)%hsize;
		auto it = imouto[key].find(name);
		switch(hcmd) {
			case 124: //NEW
				scanf(" '%[^,\n']'%*c", text);
				if(it != imouto[key].end()) status(403, name);
				else {
					imouto[key].insert(make_pair(name, text));
					status(201, name);
				}
				break;
			case 25: //DELETE
				if(it == imouto[key].end()) status(404, name);
				else {
					imouto[key].erase(name);
					status(202, name);
				}
				break;
			case 118: //GET
				if(it == imouto[key].end()) status(404, name);
				else {
					status(200, name);
					printf(",\'%s\'", (*it).second.c_str());
				}
				break;
			case 24: //POST
				scanf(" '%[^,\n']'%*c", text);
				if(it == imouto[key].end()) status(404, name);
				else {
					(*it).second += string("\\") + string(text);
					status(200, name);
				}
		} putchar('\n');
	}

	return 0;
}
