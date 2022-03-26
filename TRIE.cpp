#include <bits/stdc++.h>
using namespace std;

/************************************************************************************************/

struct trie {
     trie *child[26];
     bool isEnd;
     trie() {
          memset(child, 0, sizeof(child));
          isEnd = false;
     }
};
trie *root = new trie();
void append(string str) {
     trie *current_node = root;
     for (char ch : str) {
          int indx = ch - 'a';
          if (current_node->child[indx] == NULL) {
               current_node->child[indx] = new trie();
          }
          current_node = current_node->child[indx];

     }
     current_node->isEnd = true;

}
bool search(string str) {
     trie *current_node = root;
     for (char ch : str) {
          int indx = ch - 'a';
          if (current_node->child[indx] == NULL) {

               return false;
          }

          current_node = current_node->child[indx];
     }

     return current_node->isEnd;
}

void solve() {
     int n;
     cin >> n;
     for (int i = 0; i < n; i++) {
          string str;
          cin >> str;
          append(str);
     }
     int q;
     cin >> q;
     while (q--) {
          string str;
          cin >> str;
          bool ans = search(str);
          if (ans) {
               cout << "Word is present" << endl;
          }
          else {
               cout << "Word is not present" << endl;
          }
     }
}

int main() {
    
     solve();

}
