#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, L;
  cin >> N >> L;
  vector<string> S;
  string s;
  for (int i=0; i<N; i++) {
    cin >> s;
    S.push_back(s);
  }
  sort(S.begin(), S.end());
  for (int i=0; i<N; i++)
    cout << S[i];
  return 0;
}
