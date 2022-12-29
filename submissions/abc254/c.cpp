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
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,K;
  cin >> N >> K;
  vector<priority_queue<int,vector<int>,greater<int>>> modK(K);
  rep(i,N) {
    int a;
    cin >> a;
    modK[i%K].push(a);
  }
  bool flag = true;
  int p = 0;
  rep(i,N) {
    int a = modK[i%K].top();
    modK[i%K].pop();
    if (p>a) {
      flag = false;
    }
    p = a;
  }
  print((flag ? Yes : No));
  return 0;
}
