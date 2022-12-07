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
  multiset<ll, greater<ll>> A;
  int res = 0;
  rep(i,N) {
    int a;
    cin >> a;
    A.insert(a);
  }
  while (!A.empty()) {
    auto first = A.begin();
    ll a = *first;
    A.erase(first);
    ll pow = 1;
    while (pow <= a) {
      pow *= 2;
    }
    auto it = A.find(pow-a);
    if (it == A.end())
      continue;
    res++;
    A.erase(it);
  }
  print(res);
  return 0;
}
