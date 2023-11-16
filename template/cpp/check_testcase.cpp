#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

using val = struct{
  ll i;
  ld f;
  string s;
};

pair<int,val> parse(const string &input) {
  static const regex floatRegex{R"([+\-]?(?:0|[1-9]\d*)(?:\.\d*)?(?:[eE][+\-]?\d+)?)"};
  static const regex integerRegex{R"([+\-]?\d+)"};
  istringstream inputStream(input);

  int t = 3;
  val v;
  v.s = input;
  if (regex_match(input, floatRegex)) {
    v.f = stold(input);
    t = 2;
  }
  if (regex_match(input, integerRegex)) {
    v.i = stoll(input);
    t = 1;
  }
  return {t, v};
}


int main(int argc, char *argv[]) {
  if (argc < 3) {
    cerr << "fewer arguments." << endl;
    return 1;
  }
  ifstream fin1(argv[1]), fin2(argv[2]);
  if (fin1.fail()) {
    cerr << "cannot open file: " << argv[1] << endl;
    return 1;
  }
  if (fin2.fail()) {
    cerr << "cannot open file: " << argv[2] << endl;
    return 1;
  }
  const ld fp_error = 1e-9;
  string input1, input2;
  bool flag = true;
  while (true) {
    bool f1 = fin1.eof();
    bool f2 = fin2.eof();
    if (f1 && f2)
      break;
    if (f1 || f2) {
      flag = false;
      break;
    }
    fin1 >> input1;
    fin2 >> input2;
    auto p1 = parse(input1);
    auto p2 = parse(input2);
    if (p1.first == 1 && p2.first == 1) {
      if (p1.second.i != p2.second.i) {
        flag = false;
        break;
      }
    } else if (p1.first <= 2 && p2.first <= 2) {
      ld f1 = p1.second.f, f2 = p2.second.f;
      if (abs(f1-f2) > fp_error && abs(f1-f2)/f1 > fp_error) {
        flag = false;
        break;
      }
    } else {
      if (p1.second.s != p2.second.s) {
        flag = false;
        break;
      }
    }
  }
  if (flag)
    cout << 0 << endl;
  else
    cout << 1 << endl;
  return 0;
}