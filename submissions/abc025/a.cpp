#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  string S;
  int N;
  cin >> S >> N;
  vector<string> ans;
  rep(i, 5) {
    rep(j, 5) {
      string tmp;
      tmp.push_back(S[i]);
      tmp.push_back(S[j]);
      ans.push_back(tmp);
    }
  }
  print(ans[N-1]);
  return 0;
}
