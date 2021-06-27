#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  ll T[N], A[N];
  for (int i=0; i<N; i++)
    cin >> T[i] >> A[i];
  for (int i=1; i<N; i++) {
    ll t = (T[i]+T[i-1]-1)/T[i], a = (A[i]+A[i-1]-1)/A[i], t1, t2, a1, a2;
    t1 = t*T[i];
    a1 = t*A[i];
    t2 = a*T[i];
    a2 = a*A[i];
    if (t < a) {
      if (a1 >= A[i-1]) {
        T[i] = t1;
        A[i] = a1;
      } else {
        T[i] = t2;
        A[i] = a2;
      }
    } else {
      if (t2 >= T[i-1]) {
        T[i] = t2;
        A[i] = a2;
      } else {
        T[i] = t1;
        A[i] = a1;
      }
    }
  }
  cout << T[N-1]+A[N-1] << endl;
  return 0;
}