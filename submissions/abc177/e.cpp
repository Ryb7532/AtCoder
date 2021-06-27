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

ll gcd(ll a,ll b) {
  if (b == 0)
    return a;
  return gcd(b,a%b);
}

int main() {
  int N;
  cin >> N;
  vec<ll> A(N);
  vec<ll> Gcd(N);
  rep(i,N) {
    cin >> A[i];
  }
  Gcd[N-1] = A[N-1];
  repr(i,N-1,0) {
    Gcd[i] = gcd(Gcd[i+1],A[i]);
  }
  if (Gcd[0] != 1) {
    print("not coprime");
    return 0;
  }
  vec<bool> num(1e6+1,false);
  rep(i,N) {
    if (num[A[i]]) {
      print("setwise coprime");
      return 0;
    }
    reps(j,2,sqrt((double)A[i])+0.01) {
      if (A[i]%j == 0) {
        int id = j;
        while (id<=1e6) {
          num[id] = true;
          id += j;
        }
      }
      while (A[i]%j == 0) {
        A[i] /= j;
      }
    }
    if (A[i] != 1) {
      int id = A[i];
      while (id<=1e6) {
        num[id] = true;
        id += A[i];
      }
    }
  }
  print("pairwise coprime");
  return 0;
}
