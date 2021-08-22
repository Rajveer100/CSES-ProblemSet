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

  ll n;

  std::cin >> n;

  std::string s[n];

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> s[i];
  }

  std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, 0));

  dp[0][0] = 1;

  for (int i = 0; i <= n - 1; i++) {

    for (int j = 0; j <= n - 1; j++) {

      if (s[i][j] != '*') {

        (dp[i][j] += (i >= 1 ? dp[i - 1][j] : 0)) %= mod1;
        (dp[i][j] += (j >= 1 ? dp[i][j - 1] : 0)) %= mod1;
      } else {

        dp[i][j] = 0;
      }
    }
  }

  std::cout << dp[n - 1][n - 1] << "\n";
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