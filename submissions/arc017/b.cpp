#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main() {
  int N,K;
  cin >> N >> K;
  vi A(N);
  rep(i,N) cin >> A[i];
  int l=0,r=1,ans = 0;
  while (r<N) {
    while (r<N && A[r-1]<A[r]) {
      r++;
    }
    if (r-l>=K)
      ans += r-l-K+1;
    l = r;
    r++;
  }
  print(ans);
  return 0;
}
