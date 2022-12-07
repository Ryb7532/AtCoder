#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  string S[N];
  for (int i=0; i<N; i++)
    cin >> S[i];
  for (int i=0; i<N; i++) {
    for (int j=N-1; j>=0; j--)
      cout << S[j][i];
    cout << endl;
  }
  return 0;
}
