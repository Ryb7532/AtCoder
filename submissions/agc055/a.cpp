#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


vector<string> str_pattern = {"ABC", "ACB", "BCA", "BAC", "CAB", "CBA"};

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<vector<int>> cnt(3, vector<int>(3,0));
  rep(i,3) {
    rep(j,N) {
      int c = S[i*N+j]-'A';
      cnt[i][c]++;
    }
  }
  vector<int> pattern(6,0);
  vector<bool> over(3,false);
  rep(i,3) {
    over[i] = cnt[0][i]-cnt[1][(i+1)%3]>0;
  }
  int start = 0;
  rep(i,3) {
    if (over[i] && !over[(i+2)%3])
      start = i;
  }
  rep(i,3) {
    int j = (start+i)%3;
    pattern[j*2] = min(cnt[0][j], cnt[1][(j+1)%3]);
    cnt[0][j] -= pattern[j*2];
    cnt[1][(j+1)%3] -= pattern[j*2];
    pattern[j*2+1] = cnt[0][j];
    cnt[1][(j+2)%3] -= pattern[j*2+1];
  }
  vector<int> res(3*N);
  rep(i,3) {
    vector<int> p = pattern;
    vector<vector<int>> char2id(3);
    rep(j,6) {
      int c = str_pattern[j][i]-'A';
      char2id[c].push_back(j);
    }
    rep(j,N) {
      int c = S[i*N+j]-'A';
      int id0 = char2id[c][0];
      int id1 = char2id[c][1];
      if (p[id0]>0) {
        res[i*N+j] = id0;
        p[id0]--;
      } else {
        res[i*N+j] = id1;
        p[id1]--;
      }
    }
  }
  rep(i,3*N) {
    cout << res[i]+1;
  }
  cout << endl;
  return 0;
}
