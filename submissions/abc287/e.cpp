#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
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
  vector<pair<string,int>> S(N);
  rep(i,N) {
    cin >> S[i].first;
    S[i].second = i;
  }
  sort(all(S));
  vector<int> res(N,0);
  rep(i,N-1) {
    int lcp = 0;
    int s0 = S[i].first.size(), s1 = S[i+1].first.size();
    int i0 = S[i].second, i1 = S[i+1].second;
    for (int j=0; j<min(s0, s1); j++) {
      if (S[i].first[j] == S[i+1].first[j])
        lcp++;
      else
        break;
    }
    res[i0] = max(res[i0], lcp);
    res[i1] = max(res[i1], lcp);
  }
  rep(i,N) {
    print(res[i]);
  }
  return 0;
}
