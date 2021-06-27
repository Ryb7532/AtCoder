#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S;
  string s;
  for (int i=0; i<N; i++) {
    cin >> s;
    S.push_back(s);
  }
  sort(S.begin(), S. end());
  s = S[0];
  int ans = 1;
  for (int i=1; i<N; i++)
    if (s != S[i]) {
      s = S[i];
      ans++;
    }
  cout << ans << endl;
  return 0;
}
