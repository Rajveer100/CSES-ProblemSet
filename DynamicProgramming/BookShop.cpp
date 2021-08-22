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

  ll n, x;

  std::cin >> n >> x;

  std::vector<int> price(n), pages(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> price[i];
  }

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> pages[i];
  }

  std::vector<std::vector<int>> dp(n + 5, std::vector<int>(x + 5, 0));

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= x; j++) {

      dp[i][j] = dp[i - 1][j];

      if (j - price[i - 1] >= 0) {

        dp[i][j] =
            std::max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
      }
    }
  }

  std::cout << dp[n][x] << "\n";
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