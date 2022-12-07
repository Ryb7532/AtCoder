#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vec<bool> match(N);
  bool judge = false;
  rep(i,N) {
    int d1,d2;
    cin >> d1 >> d2;
    match[i] = (d1 == d2);
  }
  rep(i,N-2) {
    if (match[i] && match[i+1] && match[i+2])
      judge = true;
  }
  print(((judge)?Yes:No));
  return 0;
}
