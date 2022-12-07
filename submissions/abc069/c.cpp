#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a, cnt2 = 0, cnt4 = 0;
  for (int i=0; i<n; i++) {
    cin >> a;
    if (a%4 == 0)
      cnt4++;
    else if (a%2 == 0)
      cnt2++;
  }
  if (n-cnt4-cnt2 <= cnt4)
    cout << "Yes\n";
  else if (cnt2 == 0 && n-cnt4 == cnt4+1)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}