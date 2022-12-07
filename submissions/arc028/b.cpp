#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N,K;
  cin >> N >> K;
  vector<pii> X(N);
  rep(i,N) {
    cin >> X[i].first;
    X[i].second = i+1;
  }
  set<pii> Y;
  rep(i,N) {
    Y.insert(X[i]);
    int s = Y.size();
    if (s>K) {
      Y.erase(--Y.end());
      s--;
    }
    if (s==K) {
      print((--Y.end())->second);
    }
  }
  return 0;
}
