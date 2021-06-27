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
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N;
  cin >> N;
  vi L(N);
  rep(i,N) {
    cin >> L[i];
  }
  sort(all(L));
  int ans = 0;
  rep(i,N) {
    reps(j,i+1,N) {
      if (L[i] == L[j])
        continue;
      reps(k,j+1,N) {
        if (L[j] == L[k])
          continue;
        if (L[k] < L[i]+L[j])
          ans++;
      }
    }
  }
  print(ans);
  return 0;
}
