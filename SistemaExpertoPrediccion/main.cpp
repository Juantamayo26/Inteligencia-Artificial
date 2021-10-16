#include <bits/stdc++.h>

using namespace std;

void toLower(string &ans) {
  transform(ans.begin(), ans.end(), ans.begin(),
            [](unsigned char c) { return std::tolower(c); });
}

int main() {
  unordered_map<string, vector<string>> brain;
  string objeto, atributo, ans;
  bool win = true;
  while (true) {
    if (ans != "jugar") {
      if (!brain.size()) {
        cout << "No se nada. En que piensas?" << endl;
      } else if (!win) {
        cout << "Que era?" << endl;
      }
      getline(cin, objeto);
      cout << "Dime un atributo" << endl;
      getline(cin, atributo);
      brain[objeto].push_back(atributo);
    } else {
      for (auto i : brain) {
        win = true;
        for (auto j : i.second) {
          cout << "Es un " << j << "?" << endl;
          cin >> ans;
          toLower(ans);
          if (ans == "no") {
            win = false;
            break;
          }
        }
        if (win) {
          cout << "Es un " << i.first << "?" << endl;
          cin >> ans;
          toLower(ans);
          if (ans == "no") {
            // brain.erase(i.first);
            win = false;
          }
        }
        if (win) {
          cout << "Gane!!" << endl;
          return 0;
        }
      }
    }
    cout << "Quieres jugar de nuevo o entrenarme?" << endl;
    getline(cin, ans);
    //   cin >> ans;
    toLower(ans);
  }
}
