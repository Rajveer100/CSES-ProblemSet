//
//  main.cpp
//  CPWorkSpace
//
//  Created by Rajveer Singh on 23/09/21.
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
ll inf = 1e15 + 5;

void testCase() {

  ll n;

  std::cin >> n;

  ll s = n * (n + 1) / 2;

  if (s % 2) {

    std::cout << "0\n";
    return;
  }

  s /= 2;

  std::vector<std::vector<ll>> dp(s + 1, std::vector<ll>(n, 0));

  dp[0][0] = 1;

  for (int i = 0; i <= s; i++) {

    for (int j = 1; j <= n - 1; j++) {

      dp[i][j] = dp[i][j - 1];

      if (i - j - 1 >= 0 && dp[i - j - 1][j - 1]) {

        (dp[i][j] += dp[i - j - 1][j - 1]) %= mod1;
      }
    }
  }

  std::cout << dp[s][n - 1] << "\n";
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.precision(15);

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (ll i = 0; i <= t - 1; i++) {

    //        std::cout<<"Case #"<<i+1<<": ";
    testCase();
  }
}