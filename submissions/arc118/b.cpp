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


int main() {
  int K;
  ll N,M;
  cin >> K >> N >> M;
  vector<ll> A(K);
  vector<int> B(K);
  vector<pair<ld,int>> D(K);
  int total = 0;
  rep(i,K) {
    cin >> A[i];
    int b = A[i]*M/N;
    B[i] = b;
    total += b;
    D[i] = {abs(N*B[i]-M*A[i])/(ld)M*N, i};
  }
  sort(rall(D));
  int i=0;
  while(total != M) {
    B[D[i].second]++;
    total++;
    i++;
    i%=K;
  }
  cout << B[0];
  rep(i,K-1) {
    cout << " " << B[i+1];
  }
  cout << endl;
  return 0;
}
