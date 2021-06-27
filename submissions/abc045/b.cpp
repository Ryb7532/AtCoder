#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S[3];
  int w = 0, id[3] = {0, 0, 0}, s[3];
  for (int i=0; i<3; i++) {
    cin >> S[i];
    s[i] = S[i].size();
  }
  while (1) {
    if (id[w] >= s[w])
      break;
    char c = S[w][id[w]];
    id[w]++;
    w = c - 'a';
  }
  cout << (char)('A'+w) << endl;
  return 0;
}
