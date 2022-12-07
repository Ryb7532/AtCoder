#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0; i<n; i++)
#define reps(i,s,n) for (int i=s, i<n; i++)
#define rep1(i,n) for (int i=1; i<=n; i++)
#define print(a) cout << a << endl;

int main() {
  int N;
  cin >> N;
  string S;
  int P, sum = 0;
  vector<pair<int, string>> C;
  rep(i, N) {
    cin >> S >> P;
    sum += P;
    C.push_back(make_pair(P, S));
  }
  sort(C.rbegin(), C.rend());
  if (2*C[0].first > sum) {
    print(C[0].second);
  } else {
    print("atcoder");
  }
  return 0;
}
