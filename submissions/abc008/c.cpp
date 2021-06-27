#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
vec<vec<ld>> comb(101,vec<ld>(101)); //comb[a][b] = aCb

void combination_init(int n) {
  comb[0][0] = 1.0;
  rep1(i,n) {
    comb[i][0] = 1.0;
    rep1(j,i) {
      comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
    }
  }
  return ;
}


int main() {
  int N;
  cin >> N;
  vec<int> C(N);
  map<int,int> cnt;
  rep(i,N) {
    cin >> C[i];
    cnt[C[i]]++;
  }
  sort(all(C));
  vec<int> div_cnt(N,0);
  rep(i,N) {
    rep(j,i) {
      if (C[j] == C[i]) break;
      if (C[i]%C[j] == 0) div_cnt[i]++;
    }
    div_cnt[i] += cnt[C[i]]-1;
  }
  combination_init(N);
  ld ans = 0.0;
  rep(i,N) {
    int d = div_cnt[i];
    for (int j=0; j<=d; j+=2) {
      rep(k,N-j) {
        ans += comb[d][j]*comb[N-1-d][k]/comb[N-1][j+k];
      }
    }
  }
  ans /= N;
  cout.precision(10);
  print(ans);
  return 0;
}
