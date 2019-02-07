#include<cstdio>
#include<cstring>

int const maxs = 1010;

char a[maxs], b[maxs];

bool is_vowel(char c)
  { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

int main()
{
  scanf("%s%s", &a, &b);

  if(strlen(a) != strlen(b)) { puts("No"); return 0; }

  for(int i = 0; i < strlen(a); i++)
    if(is_vowel(a[i]) != is_vowel(b[i])) { puts("No"); return 0; }

  puts("Yes"); return 0;
}
