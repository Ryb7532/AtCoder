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
  int N;
  cin >> N;
  vector<int> t(N);
  rep(i,N) {
    cin >> t[i];
  }
  rsort(t);
  int t1=0,t2=0;
  rep(i,N) {
    if (t1<=t2)
      t1 += t[i];
    else
      t2 += t[i];
  }
  print(max(t1,t2));
  return 0;
}
