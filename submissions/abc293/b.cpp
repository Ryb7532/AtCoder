#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N;
  cin >> N;
  vector<int> cnt(N,0);
  rep(i,N) {
    int a;
    cin >> a;
    a--;
    if (cnt[i] == 0)
      cnt[a]++;
  }
  vector<int> res;
  rep(i,N) {
    if (cnt[i] == 0)
      res.push_back(i+1);
  }
  print(res.size());
  for (int e: res) {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}
