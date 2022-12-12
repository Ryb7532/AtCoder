#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vector<bool> used(2*N+1, false);
  print(1);
  used[0] = true;
  int i = 0;
  rep(_,N) {
    int M;
    cin >> M;
    used[--M] = true;
    while (used[i]) {
      i++;
    }
    print(i+1);
    used[i] = true;
  }
  return 0;
}
