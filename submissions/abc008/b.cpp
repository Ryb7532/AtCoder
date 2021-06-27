#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int N;
  cin >> N;
  string s;
  vector<string> S;
  rep(i, N) {
    cin >> s;
    S.push_back(s);
  }
  sort(all(S));
  string name = S[0], ans = S[0];
  int m = 1, cnt = 1;
  rep1(i, N-1) {
    if (name.compare(S[i]) == 0) {
      cnt++;
    } else {
      if (cnt>m) {
        m = cnt;
        ans = name;
      }
      name = S[i];
      cnt = 1;
    }
  }
  if (cnt>m)
    ans = name;
  print(ans);
  return 0;
}
