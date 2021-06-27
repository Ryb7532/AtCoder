#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int cnt[26] = {}, n = S.length();
  bool chk = true;
  for (int i=0; i<n; i++)
    cnt[S[i]-'a']++;
  for (int i=0; i<26; i++)
    if (cnt[i]>1)
      chk = false;
  if (chk)
    cout << "yes\n";
  else
    cout << "no\n";
  return 0;
}
