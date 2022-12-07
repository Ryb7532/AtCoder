#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, Q, l, r, cnt = 0;
  cin >> N >> Q;
  vector<int> L, R;
  for (int i=0; i<Q; i++) {
    cin >> l >> r;
    l--;
    L.push_back(l);
    R.push_back(r);
  }
  sort(L.rbegin(), L.rend());
  sort(R.rbegin(), R.rend());
  for (int i=0; i<N; i++) {
    while (!L.empty() && L.back() == i) {
      cnt++;
      L.pop_back();
    }
    while (!R.empty() && R.back() == i) {
      cnt--;
      R.pop_back();
    }
    cout << cnt%2;
  }
  cout << endl;
  return 0;
}
