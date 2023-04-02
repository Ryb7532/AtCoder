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
#define printYorN(f) cout << (f ? Yes : No) << endl


// Task: Longest Common Prefix between S[0:|S|-1] and S[i:|S|-1] (0<=i<|S|)
// Z-Algorithm (O(|S|))
vector<int> z_algorithm(const string &s) {
  int l = s.size();
  vector<int> prefix(l,0);
  for (int i=1, j=0; i<l; i++) {
    if (i + prefix[i-j] < j + prefix[j])
      prefix[i] = prefix[i-j];
    else {
      int k = max(0, j+prefix[j]-i);
      while (i + k < l && s[k] == s[i+k])
        k++;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = l;
  return prefix;
}


int main() {
  int N;
  string T;
  cin >> N >> T;
  string T1 = T.substr(0,N), T2 = T.substr(N);
  reverse(all(T2));
  string S1 = T1 + T2;
  reverse(all(T1));
  reverse(all(T2));
  string S2 = T1 + T2;
  reverse(all(T1));
  auto prefix1 = z_algorithm(S1);
  auto prefix2 = z_algorithm(S2);
  int res = -1;
  string S;
  if (prefix1[N] == N) {
    res = 0;
  }
  rep(i,N-1) {
    if (prefix1[N+1+i] == N-1-i && prefix2[2*N-1-i] == 1+i) {
      res = N-1-i;
    }
  }
  if (res != -1) {
    rep(i,res) {
      cout << T1[i];
    }
    rep(i,N-res) {
      cout << T1[N-1-i];
    }
    cout << endl;
  }
  print(res);
  return 0;
}
