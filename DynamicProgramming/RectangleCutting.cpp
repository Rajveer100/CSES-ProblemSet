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
ll inf = 1e10 + 5;

void testCase() {

  ll a, b;

  std::cin >> a >> b;

  std::vector<std::vector<ll>> dp(a + 1, std::vector<ll>(b + 1, inf));

  dp[0][0] = 0;
  dp[1][0] = 0;
  dp[0][1] = 0;

  for (int i = 1; i <= b; i++) {

    for (int j = 1; j <= a; j++) {

      for (int k = 1; k <= j; k++) {

        if (j == i) {

          dp[j][i] = 0;
        } else {

          dp[j][i] = std::min(dp[j][i], dp[k][i] + dp[j - k][i] + 1);
        }
      }

      for (int k = 1; k <= i; k++) {

        if (j == i) {

          dp[j][i] = 0;
        } else {

          dp[j][i] = std::min(dp[j][i], dp[j][k] + dp[j][i - k] + 1);
        }
      }
    }
  }

  std::cout << dp[a][b] << "\n";
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