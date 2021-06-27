#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
  int N, total = 0;
  cin >> N;
  string S;
  vector<P> p, m;
  for (int i = 0; i < N; i++) {
    cin >> S;
    int d = 0, b = 0;
    for (char c: S) {
      if (c == '(')
        d++;
      else
        d--;
      b = min(b, d);
    }
    if (d>=0)
      p.push_back({b, d});
    else
      m.push_back({b-d, d});
    total += d;
  }
  sort(p.rbegin(), p.rend());
  sort(m.begin(), m.end());
  bool check = (total == 0);
  int h = 0;
  for (P e: p) {
    if (h+e.first<0)
      check = false;
    h += e.second;
  }
  for (P e: m) {
    if (h+e.first+e.second<0)
      check = false;
    h += e.second;
  }
  if (check)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
