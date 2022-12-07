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
  vec<int> P(N);
  rep(i,N) {
    cin >> P[i];
  }
  vec<bool> used(N-1,false);
  vec<int> res;
  rep(i,N) {
    if (P[i]==i+1)
      continue;
    int pos=i,tmp=P[pos];
    vec<int> order;
    P[pos]=i+1;
    while (!used[pos]) {
      used[pos]=true;
      order.push_back(pos+1);
      swap(P[pos+1],tmp);
      pos++;
      if (tmp==i+1)
        break;
    }
    if (tmp!=i+1) {
      print(-1);
      return 0;
    }
    while (!order.empty()) {
      res.push_back(order.back());
      order.pop_back();
    }
  }
  if (res.size()!=N-1) {
    print(-1);
  } else {
    for (int e: res)
      print(e);
  }
  return 0;
}
