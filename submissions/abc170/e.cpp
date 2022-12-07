#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

set<pi, greater<pi>> K[200000];
set<pi> H;

int main() {
  int N, Q;
  cin >> N >> Q;
  int A[N], B[N], C, D;
  for (int i=0; i<N; i++) {
    cin >> A[i] >> B[i];
    B[i]--;
    K[B[i]].insert({A[i], i});
  }
  for (int i=0; i<200000; i++) {
    if (K[i].empty())
      continue;
    H.insert(*(K[i].begin()));
  }
  for (int i=0; i<Q; i++) {
    cin >> C >> D;
    C--; D--;
    H.erase(*(K[B[C]].begin()));
    K[B[C]].erase({A[C], C});
    if (!K[B[C]].empty())
      H.insert(*(K[B[C]].begin()));
    if (!K[D].empty())
      H.erase(*(K[D].begin()));
    K[D].insert({A[C], C});
    H.insert(*(K[D].begin()));
    B[C] = D;
    cout << (H.begin())->first << endl;
  }
  return 0;
}
