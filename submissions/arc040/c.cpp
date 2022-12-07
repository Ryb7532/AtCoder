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
  int N;
  cin >> N;
  string S[N];
  rep(i,N) {
    cin >> S[i];
  }
  int c = N, ans = 0;
  rep(i,N) {
    int j=c-1;
    while (j>=0) {
      if (S[i][j] == '.')
        break;
      j--;
    }
    if (j>=0) {
      c = j;
      ans++;
    } else {
      c = N;
    }
  }
  print(ans);
  return 0;
}
