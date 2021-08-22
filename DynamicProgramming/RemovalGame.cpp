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

  std::vector<ll> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  ll s = std::accumulate(a.begin(), a.end(), 0ll);
  std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(n + 1, -inf));

  for (ll i = 0; i <= n - 1; i++) {

    for (ll j = i; j >= 0; j--) {

      if (i == j) {

        dp[i][j] = a[i];
        continue;
      }

      dp[i][j] = std::max(a[i] - dp[i - 1][j], a[j] - dp[i][j + 1]);
    }
  }

  std::cout << (s + dp[n - 1][0]) / 2 << "\n";
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