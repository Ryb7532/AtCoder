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
  ll N,M;
  cin >> N;
  M = N;
  map<int,int> m;
  for (int i=2; i<sqrt((double)M)+0.01; i++) {
    int cnt=0;
    while (M%i == 0) {
      cnt++;
      M /= i;
    }
    if (cnt)
      m[i] = cnt;
  }
  if (M!=1) {
    m[M] = 1;
  }
  ll sum=1;
  for (auto e : m) {
    ll tmp=0,n=1;
    rep(i,e.second+1) {
      tmp += n;
      n *= e.first;
    }
    if (2*N/sum<tmp) {
      print("Abundant");
      return 0;
    }
    sum *= tmp;
  }
  sum -= N;
  if (sum == N) {
    print("Perfect");
  } else if (sum < N) {
    print("Deficient");
  } else {
    print("Abundant");
  }
  return 0;
}
