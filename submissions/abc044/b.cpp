#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string w;
  cin >> w;
  int cnt[26], n = w.size();
  fill(cnt, cnt+26, 0);
  for (int i=0; i<n; i++) {
    int id = w[i]-'a';
    cnt[id]++;
  }
  for (int i=0; i<26; i++) {
    if (cnt[i]%2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
