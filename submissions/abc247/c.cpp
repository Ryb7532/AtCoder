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
  stringstream ss;
  rep(i,(1<<N)-1) {
    int n = 1;
    int m = i+1;
    while (m%2 == 0) {
      m /= 2;
      n++;
    }
    ss << n << " ";
  }
  string res = ss.str();
  res.pop_back();
  print(res);
  return 0;
}
