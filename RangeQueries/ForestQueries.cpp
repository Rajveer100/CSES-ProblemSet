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

  ll n, q;

  std::cin >> n >> q;

  std::vector<std::vector<ll>> s(n, std::vector<ll>(n));

  for (int i = 0; i <= n - 1; i++) {

    for (int j = 0; j <= n - 1; j++) {

      char c;
      std::cin >> c;

      s[i][j] = (c == '*');
    }
  }

  std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, 0));

  for (int i = 0; i <= n - 1; i++) {

    for (int j = 0; j <= n - 1; j++) {

      dp[i][j] += s[i][j];
      dp[i][j] += (i ? dp[i - 1][j] : 0);
      dp[i][j] += (j ? dp[i][j - 1] : 0);
      dp[i][j] -= (i && j ? dp[i - 1][j - 1] : 0);
    }
  }

  for (int i = 0; i <= q - 1; i++) {

    ll x1, x2, y1, y2;

    std::cin >> x1 >> y1 >> x2 >> y2;

    ll xMax = std::max(x1, x2) - 1, yMax = std::max(y1, y2) - 1;
    ll xMin = std::min(x1, x2) - 1, yMin = std::min(y1, y2) - 1;

    ll ans = dp[xMax][yMax], vis = 0;

    if (yMin) {

      ans -= dp[xMax][yMin - 1];
      vis++;
    }

    if (xMin) {

      ans -= dp[xMin - 1][yMax];
      vis++;
    }

    if (vis == 2) {

      ans += dp[xMin - 1][yMin - 1];
    }

    std::cout << ans << "\n";
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