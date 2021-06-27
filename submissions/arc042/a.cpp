#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N, M;
  cin >> N >> M;
  bool used[N];
  fill(used,used+N,false);
  vector<int> A;
  int a;
  rep(i,M) {
    cin >> a;
    a--;
    A.push_back(a);
  }
  while (!A.empty()) {
    a = A.back();
    A.pop_back();
    if (used[a])
      continue;
    print(a+1);
    used[a] = true;
  }
  rep(i,N) {
    if (used[i])
      continue;
    print(i+1);
  }
  return 0;
}
