//
//  main.cpp
//  CPWorkSpace
//
//  Created by Rajveer Singh on 21/01/22.
//

#include <algorithm>
#include <array>
#include <chrono>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// MARK:- PRACTICE

#define len(a) (ll) a.size()
typedef long long ll;
typedef long double ld;

constexpr bool test = false;
constexpr ll mod1 = 1e9 + 7;
constexpr ll mod2 = 998244353;
constexpr ll inf = 1e18 + 5;
constexpr ll lim = 2e5 + 5;

class TrieNode {

public:
  std::vector<TrieNode *> child;
  bool isEnd;

  TrieNode() {

    child.resize(26, nullptr);
    isEnd = false;
  }
};

class Trie {

public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  bool nodeIsEmpty(TrieNode *node) {

    bool isEmpty = true;

    for (auto c : node->child) {

      isEmpty &= (c == nullptr);
    }

    return isEmpty;
  }

  void insert(std::string word) {

    TrieNode *curNode = root;

    for (auto c : word) {

      TrieNode *childNode = curNode->child[c - 'a'];

      if (childNode == nullptr) {

        childNode = new TrieNode();
        curNode->child[c - 'a'] = childNode;
      }

      curNode = childNode;
    }

    curNode->isEnd = true;
  }

  bool find(std::string word) {

    TrieNode *curNode = root;

    for (auto c : word) {

      TrieNode *childNode = curNode->child[c - 'a'];

      if (childNode == nullptr)
        return false;

      curNode = childNode;
    }

    return curNode->isEnd;
  }

  void erase(std::string word) { _erase(root, 0, word); }

  bool _erase(TrieNode *curNode, ll pos, std::string &word) {

    if (pos == len(word)) {

      if (!curNode->isEnd)
        return false;

      curNode->isEnd = false;

      return nodeIsEmpty(curNode);
    }

    char ch = word[pos];
    TrieNode *childNode = curNode->child[ch - 'a'];

    if (childNode == nullptr)
      return false;

    bool shouldDelete = _erase(childNode, pos + 1, word);

    if (shouldDelete) {

      curNode->child[ch - 'a'] = nullptr;

      return nodeIsEmpty(curNode);
    }

    return false;
  }
};

void testCase() {

  std::string s;
  ll k;

  std::cin >> s;
  std::cin >> k;

  Trie trie;

  for (int i = 0; i <= k - 1; i++) {

    std::string t;
    std::cin >> t;

    trie.insert(t);
  }

  std::vector<ll> dp(len(s) + 1);
  dp[len(s)] = 1;

  for (ll i = len(s) - 1; i >= 0; i--) {

    TrieNode *cur = trie.root;

    for (ll j = i; j <= len(s) - 1; j++) {

      if (cur->child[s[j] - 'a'] == nullptr)
        break;

      cur = cur->child[s[j] - 'a'];

      if (cur->isEnd) {

        dp[i] = (dp[i] + dp[j + 1]) % mod1;
      }
    }
  }

  std::cout << dp[0] << '\n';
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.precision(20);

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (int i = 0; i <= t - 1; i++) {

    //        std::cout << "Case #" << i + 1 << ": ";
    testCase();
  }
}
