#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int cntl = 0, cntr = 0, addr, addl;
  for (int i=0; i<N; i++) {
    if (S[i] == '(')
      cntl++;
    else if (S[i] == ')' && cntl == 0)
      cntr++;
    else
      cntl--;
  }
  addr = cntr;
  cntr = 0;
  cntl = 0;
  for (int i=N-1; i>=0; i--) {
    if (S[i] == ')')
      cntr++;
    else if (S[i] == '(' && cntr == 0)
      cntl++;
    else
      cntr--;
  }
  addl = cntl;
  while (addr != 0) {
    cout << '(';
    addr--;
  }
  cout << S;
  while (addl != 0) {
    cout << ')';
    addl--;
  }
  cout << endl;
  return 0;
}
