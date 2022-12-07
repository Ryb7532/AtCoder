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

template <typename T>
bool isPrime(T n) {
  if (n == 1) return false;
  if (n == 2) return true;
  reps(i,2,sqrt((double)n)+1.1) {
    if (n%i == 0) {
      return false;
    }
  }
  return true;
}


int main() {
  int N;
  cin >> N;
  if (N == 1) {
    print("Not Prime");
  } else if (isPrime(N)) {
    print("Prime");
  } else {
    bool c = (N%2!=0) && (N%3!=0) && (N%5!=0);
    print(c?"Prime":"Not Prime");
  }
  return 0;
}
