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
  ll N;
  cin >> N;
  ll d = 1;
  ll cnt = 0, comma = 0;
  while (d*1000<=N) {
    cnt += comma*d*999;
    d *= 1000;
    comma++;
  }
  cnt += comma*(N-d+1);
  print(cnt);
  return 0;
}
