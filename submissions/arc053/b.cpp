#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())
int cnt[26];

int main() {
  string S;
  cin >> S;
  int n = S.size();
  rep(i,n) {
    cnt[S[i]-'a']++;
  }
  int ans = 0, sum = 0, o = 0;
  rep(i,26) {
    sum += cnt[i];
    if (cnt[i]%2)
      o++;
  }
  if (o) {
    sum -= o;
    sum /= 2;
    ans = 2*(sum/o)+1;
  } else {
    ans = sum;
  }
  print(ans);
  return 0;
}
