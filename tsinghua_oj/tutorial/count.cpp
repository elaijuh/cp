#include <cctype>
#include <cstdio>
#include <cstring>

#define STR_LEN 4096

int main() {
  char s[STR_LEN + 1];
  fgets(s, STR_LEN, stdin);
  int cnt[26];
  for (int i = 0; i < 26; i++) cnt[i] = 0;
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    char c = s[i];
    if (isalpha(c)) cnt[toupper(c) - 'A']++;
  }

  for (int i = 0; i < 26; i++) {
    if (cnt[i]) printf("%c: %d\n", 'A' + i, cnt[i]);
  }

  return 0;
}
