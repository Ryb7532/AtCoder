#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  int N, a;
  cin >> N;
  vector<pii> A;
  for (int i=0; i<N; i++) {
    cin >> a;
    A.push_back({a, i+1});
  }
  sort(A.rbegin(), A.rend());
  for (int i=0; i<N; i++)
    cout << A[i].second << endl;
  return 0;
}
