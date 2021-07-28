#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

bool check_uruu(int y) {
  if (y%400==0)
    return true;
  else if (y%100==0)
    return false;
  else if (y%4==0)
    return true;
  else
    return false;
}

vec<int> Days = {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
  string S;
  cin >> S;
  int Y=0,M=0,D=0;
  rep(i,4) {
    Y*=10;
    Y+=S[i]-'0';
  }
  rep(i,2) {
    M*=10;
    M+=S[i+5]-'0';
  }
  rep(i,2) {
    D*=10;
    D+=S[i+8]-'0';
  }
  bool uruu = check_uruu(Y);
  while (Y%(M*D)) {
    if (D>=Days[M-1]) {
      if (M==12) {
        Y++;
        M=1;
        D=1;
      } else if (M==2 && uruu && D==28) {
        D++;
      } else {
        M++;
        D=1;
      }
    } else {
      D++;
    }
  }
  stringstream ss;
  ss << Y << '/';
  ss << setw(2) << setfill('0') << M << '/';
  ss << setw(2) << setfill('0') << D;
  print(ss.str());
  return 0;
}
