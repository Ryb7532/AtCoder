#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int N, t;
  cin >> N;
  vector<int> T;
  rep(i, N) {
    cin >> t;
    T.push_back(t);
  }
  sort(all(T));
  print(T[0]);
  return 0;
}
