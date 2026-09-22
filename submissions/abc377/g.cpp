#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}
template<class... T> void scan(T&... a) {(cin >> ... >> a);}

struct Node {
  int min_depth;
  map<char, Node*> next;

  Node(const char* s, int size) {
    if (size == 0) {
      min_depth = 0;
    } else {
      min_depth = size;
      next[s[0]] = new Node(s + 1, size - 1);
    }
  }

  void update(const char* s, int size) {
    if (size == 0) {
      min_depth = 0;
    } else {
      chmin(min_depth, size);
      if (next.find(s[0]) == next.end()) {
        next[s[0]] = new Node(s + 1, size - 1);
      } else {
        next[s[0]]->update(s + 1, size - 1);
      }
    }
  }
};

int main() {
  int N;
  scan(N);
  vector<string> S(N);
  rep(i, N) scan(S[i]);
  Node root("$", 0);
  rep(i, N) {
    string s = S[i];
    int L = s.size();
    Node* node = &root;
    ll res = L;
    rep(j, L) {
      char c = s[j];
      if (node->next.find(c) == node->next.end()) {
        break;
      }
      node = node->next[c];
      chmin(res, (ll)node->min_depth + L - j - 1);
    }
    print(res);
    root.update(s.c_str(), s.size());
  }
  return 0;
}