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
  int N, a;
  cin >> N;
  set<int, greater<int>> A;
  rep(i, N) {
    cin >> a;
    A.insert(a);
  }
  print(*(++A.begin()));
  return 0;
}
