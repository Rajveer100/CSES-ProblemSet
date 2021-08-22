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

  std::vector<std::pair<std::pair<ll, ll>, ll>> a;

  for (int i = 0; i <= n - 1; i++) {

    ll l, r, val;

    std::cin >> l >> r >> val;

    a.push_back({{l, r}, val});
  }

  std::sort(a.begin(), a.end(),
            [](auto &l, auto &r) { return l.first.second < r.first.second; });

  std::vector<ll> dp(n, 0);

  dp[0] = a.front().second;

  for (int i = 1; i <= n - 1; i++) {

    dp[i] = dp[i - 1];

    ll l = 0, r = i - 1, mid = (l + r) / 2;
    bool vis = false;

    while (l <= r) {

      mid = (l + r) / 2;

      if (a[mid].first.second < a[i].first.first) {

        if (a[mid + 1].first.second < a[i].first.first) {

          l = mid + 1;
        } else {

          vis = true;
          break;
        }
      } else {

        r = mid - 1;
      }
    }

    dp[i] = std::max(dp[i], a[i].second + (vis ? dp[mid] : 0));
  }

  std::cout << dp[n - 1] << "\n";
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