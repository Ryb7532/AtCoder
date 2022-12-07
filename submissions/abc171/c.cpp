#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  int i = 0;
  char ans[100];
  while (1) {
    N--;
    ll a = N%26;
    ans[i] = 'a' + a;
    i++;
    N /= 26;
    if (N == 0)
      break;
  }
  for (int j=i-1; j>=0; j--) 
    cout << ans[j];
  cout << endl;
  return 0;
}
