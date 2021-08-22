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

  std::string a, b;

  std::cin >> a;
  std::cin >> b;

  std::vector<std::vector<ll>> dp(len(a) + 1, std::vector<ll>(len(b) + 1, inf));

  dp[0][0] = 0;

  for (int i = 0; i <= len(a); i++) {

    for (int j = 0; j <= len(b); j++) {

      if (i) {

        dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
      }

      if (j) {

        dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
      }

      if (i && j) {

        dp[i][j] =
            std::min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
      }
    }
  }

  std::cout << dp[len(a)][len(b)] << "\n";
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