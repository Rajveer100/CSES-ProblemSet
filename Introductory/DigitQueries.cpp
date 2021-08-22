//
//  main.cpp
//  CompetitiveProgramming
//
//  Created by Rajveer Singh on 14/01/20.
//  Copyright © 2020 Rajveer Singh. All rights reserved.
//

#include <algorithm>
#include <array>
#include <chrono>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
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

bool test = false;
ll mod1 = 1e9 + 7;
ll mod2 = 998244353;

void testCase() {

  ll q;

  std::cin >> q;

  std::vector<ll> l(18, 0);

  for (ll i = 1, ten = 1; i <= 17; i++, ten *= 10) {

    l[i] += l[i - 1] + 9 * i * ten;
  }

  // 9 180 2700 36000....
  // 9 99 999 9999....

  for (int i = 0; i <= q - 1; i++) {

    ll k;

    std::cin >> k;

    ll max = 0, cur = 0;

    for (int i = 1; i <= 17; i++) {

      if (k > l[i]) {

        cur = (cur * 10) + 9;
        max++;
      } else {

        break;
      }
    }

    ll d = (k - l[max]) / (max + 1), pos = (k - l[max]) % (max + 1);
    cur += d;

    if (pos > 0) {

      cur++;
      std::string s = std::to_string(cur);
      std::cout << s[pos - 1] << "\n";
    } else {

      std::cout << cur % 10 << "\n";
    }
  }
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (ll i = 0; i <= t - 1; i++) {

    testCase();
  }
}