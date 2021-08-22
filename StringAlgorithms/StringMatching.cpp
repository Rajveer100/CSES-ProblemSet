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

void testCase() {

  std::string s, t;
  std::cin >> s >> t;

  auto getPrefixFunc = [&](std::string pat) -> std::vector<ll> {
    std::vector<ll> pi(len(pat));

    ll last = 0;

    for (int i = 1; i <= len(pat) - 1; i++) {

      while (last > 0 && pat[i] != pat[last]) {

        last = pi[last - 1];
      }

      if (pat[i] == pat[last]) {

        pi[i] = ++last;
      }
    }

    return pi;
  };

  auto kmpMatcher = [&](std::string s, std::string pat) -> ll {
    std::vector<ll> pi = getPrefixFunc(pat);
    ll j = 0;

    ll cnt = 0;

    for (int i = 0; i <= len(s) - 1; i++) {

      if (s[i] == pat[j]) {

        j++;

        if (j == len(pat)) {

          cnt++;
          j = pi[j - 1];
        }
      } else {

        if (j > 0) {

          j = pi[j - 1];
          i--;
        }
      }
    }

    return cnt;
  };

  std::cout << kmpMatcher(s, t) << '\n';
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
