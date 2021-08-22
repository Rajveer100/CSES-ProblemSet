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

  ll n, x;

  std::cin >> n >> x;

  std::vector<ll> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  std::vector<std::pair<ll, ll>> dp(1ll << n);

  dp[0] = {1, 0};

  for (ll i = 1; i <= (1ll << n) - 1; i++) {

    dp[i] = {n + 1, 0};

    for (int j = 0; j <= n - 1; j++) {

      if (i & (1ll << j)) {

        std::pair<ll, ll> cur = dp[i ^ (1ll << j)];

        if (cur.second + a[j] <= x) {

          cur.second += a[j];
        } else {

          cur.first++;
          cur.second = a[j];
        }

        dp[i] = std::min(dp[i], cur);
      }
    }
  }

  std::cout << dp[(1ll << n) - 1].first << "\n";
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