#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

template <typename T>
bool isPrime(T n) {
  if (n == 1) return false;
  reps(i,2,sqrt((double)n)+0.1) {
    if (n%i == 0) {
      return false;
    }
  }
  return true;
}


int main() {
  int N;
  cin >> N;
  print((isPrime<int>(N))?"YES":"NO");
  return 0;
}
