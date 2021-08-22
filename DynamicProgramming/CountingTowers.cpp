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

bool test = true;
ll mod1 = 1e9 + 7;
ll mod2 = 998244353;
ll inf = 1e10 + 5;

std::vector<std::vector<ll>> dp(1e6 + 1, std::vector<ll>(2));

void preCalc() {

  dp[1][0] = 1;
  dp[1][1] = 1;

  for (int i = 2; i <= 1e6; i++) {

    (dp[i][0] += dp[i - 1][1]) %= mod1;
    (dp[i][1] += dp[i - 1][0]) %= mod1;

    (dp[i][0] += (2 * dp[i - 1][0])) %= mod1;
    (dp[i][1] += (4 * dp[i - 1][1])) %= mod1;
  }
}

void testCase() {

  ll n;

  std::cin >> n;

  std::cout << (dp[n][0] + dp[n][1]) % mod1 << "\n";
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.precision(15);

  preCalc();

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (ll i = 0; i <= t - 1; i++) {

    //        std::cout<<"Case #"<<i+1<<": ";
    testCase();
  }
}