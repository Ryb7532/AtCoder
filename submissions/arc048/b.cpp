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


int main() {
  int N;
  cin >> N;
  int R[N], H[N];
  map<pair<int,int>, int> jan;
  map<int, int> r;
  rep(i,N) {
    cin >> R[i] >> H[i];
    H[i]--;
    jan[{R[i],H[i]}]++;
    r[R[i]]++;
  }
  rep1(i,100000) {
    r[i] += r[i-1];
  }
  rep(i,N) {
    int w=0,l=0,d=0;
    w += r[R[i]-1];
    w += jan[{R[i],(H[i]+1)%3}];
    d = jan[{R[i],H[i]}]-1;
    l = N-(w+d)-1;
    cout<<w<<" "<<l<<" "<<d<<endl;
  }
  return 0;
}
