//
//  main.cpp
//  main2
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

  ll n, m;

  std::cin >> n >> m;

  std::vector<ll> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  std::vector<std::vector<ll>> dp(n, std::vector<ll>(m + 5, 0));

  if (a.front()) {

    dp[0][a.front()] = 1;
  } else {

    for (int i = 1; i <= m; i++) {

      dp[0][i] = 1;
    }
  }

  for (int i = 1; i <= n - 1; i++) {

    if (a[i]) {

      (dp[i][a[i]] += (dp[i - 1][a[i]])) %= mod1;
      (dp[i][a[i]] += (dp[i - 1][a[i] - 1])) %= mod1;
      (dp[i][a[i]] += (dp[i - 1][a[i] + 1])) %= mod1;
      continue;
    }

    for (int j = 1; j <= m; j++) {

      (dp[i][j] += (dp[i - 1][j])) %= mod1;
      (dp[i][j] += (dp[i - 1][j - 1])) %= mod1;
      (dp[i][j] += (dp[i - 1][j + 1])) %= mod1;
    }
  }

  ll ans = 0;

  for (int i = 1; i <= m; i++) {

    (ans += dp[n - 1][i]) %= mod1;
  }

  std::cout << ans << "\n";
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