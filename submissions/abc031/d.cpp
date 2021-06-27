#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int K, N;
  cin >> K >> N;
  string v[N], w[N];
  rep(i,N) {
    cin >> v[i] >> w[i];
  }
  int M = pow((double)3, K);
  rep(k,M) {
    string ans[K];
    int len[K], l = k;
    rep(i,K) {
      len[i] = l%3+1;
      l /= 3;
    }
    bool c = true;
    rep(n,N) {
      int vs = v[n].size(), ws = w[n].size(), id = 0;
      rep(i,vs) {
        int num = v[n][i]-'1';
        if (id+len[num]>ws) {
          c = false;
          break;
        }
        if (ans[num].empty()) {
          rep(j,len[num]) {
            ans[num].push_back(w[n][id+j]);
          }
        } else {
          if (ans[num].compare(w[n].substr(id, len[num])) != 0) {
            c = false;
          }
        }
        id += len[num];
      }
      if (id != ws)
        c = false;
    }
    if (c) {
      rep(i,K) {
        print(ans[i]);
      }
      return 0;
    }
  }
  return 0;
}
