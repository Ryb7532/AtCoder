#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string S[n];
  for (int i=0; i<n; i++)
    cin >> S[i];
  int ans[26] = {};
  for (int i=0; i<S[0].size(); i++)
    ans[S[0][i]-'a']++;
  for (int i=1; i<n; i++) {
    int cnt[26] = {};
    for (int j=0; j<S[i].size(); j++)
      cnt[S[i][j]-'a']++;
    for (int j=0; j<26; j++)
      if (ans[j] > cnt[j])
        ans[j] = cnt[j];
  }
  for (int i=0; i<26; i++) {
    char c = i+'a';
    int num = ans[i];
    while (num>0) {
      printf("%c", c);
      num--;
    }
  }
  cout << endl;
  return 0;
}