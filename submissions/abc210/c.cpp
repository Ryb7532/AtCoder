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
  int N,K;
  cin >> N >> K;
  vec<int> c(N);
  rep(i,N) {
    cin >> c[i];
  }
  multiset<int> in;
  int num_color = 0,res = 0;
  rep(i,K) {
    if (in.find(c[i])==in.end())
      num_color++;
    in.insert(c[i]);
  }
  res = num_color;
  rep(i,N-K) {
    auto it = in.find(c[i]);
    in.erase(it);
    if (in.find(c[i])==in.end())
      num_color--;
    if (in.find(c[i+K]) == in.end())
      num_color++;
    in.insert(c[i+K]);
    res = max(res,num_color);
  }
  print(res);
  return 0;
}
