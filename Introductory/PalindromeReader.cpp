//
//  main3.cpp
//  main3
//
//  Created by Rajveer Singh on 05/11/20.
//  Copyright © 2020 Rajveer Singh. All rights reserved.
//

#include <algorithm>
#include <array>
#include <chrono>
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
#include <vector>

// MARK:- PRACTICE

typedef long long ll;
typedef long double ld;

bool test = false;
ll mod1 = 1e9 + 7;
ll mod2 = 998244353;

void testCase() {

  std::string s;

  std::cin >> s;

  std::map<ll, ll> cnt;

  for (int i = 0; i <= (ll)s.size() - 1; i++) {

    cnt[s[i] - 'A']++;
  }

  ll odd = 0, c = 0;

  std::string f, b;

  for (int i = 0; i <= 25; i++) {

    if (cnt[i] % 2) {

      if (odd) {

        std::cout << "NO SOLUTION\n";
        return;
      } else {

        odd = i + 1;
        c = cnt[i];
        cnt[i] = 0;
      }
    } else {

      ll c = cnt[i];

      char ch = i + 65;

      for (int j = 1; j <= c / 2; j++) {

        f.push_back(ch);
      }

      cnt[i] = 0;
    }
  }

  b = f;
  std::reverse(b.begin(), b.end());

  if (odd) {

    char middle = 65 + odd - 1;

    for (int i = 1; i <= c; i++) {

      f.push_back(middle);
    }
  }

  std::cout << f + b << "\n";
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