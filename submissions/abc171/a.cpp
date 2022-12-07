#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  char alpha;
  cin >> alpha;
  if (alpha-'a' < 26 && alpha-'a'>=0)
    cout << 'a' << endl;
  else
    cout << 'A' << endl;
  return 0;
}
