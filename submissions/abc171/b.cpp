#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K, v, ans = 0;
  cin >> N >> K;
  vector<int> p;
  for (int i=0; i<N; i++) {
    cin >> v;
    p.push_back(v);
  }
  sort(p.begin(), p.end());
  for (int i=0; i<K; i++) {
    ans += p[i];
  }
  cout << ans << endl;
  return 0;
}
