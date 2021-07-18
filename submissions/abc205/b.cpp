#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vec<int> cnt(N,0);
  int A;
  rep(_,N) {
    cin >> A;
    A--;
    cnt[A]++;
  }
  bool can = true;
  rep(i,N) {
    can &= cnt[i]>0;
  }
  print((can ? Yes : No));
  return 0;
}
