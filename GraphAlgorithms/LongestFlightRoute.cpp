//
//  main.cpp
//  CPWorkSpace
//
//  Created by Rajveer Singh on 21/01/22.
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
ll inf = 1e18 + 5;
ll lim = 1e5 + 5;

void testCase() {

  ll n, m;

  std::cin >> n >> m;

  std::vector<std::vector<ll>> adj(n + 1);

  for (int i = 0; i <= m - 1; i++) {

    ll u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
  }

  std::vector<ll> vis(n + 1);
  std::vector<ll> dp(n + 1, -1), child(n + 1, -1);

  auto dfs = [&](ll i, auto &&dfs) -> void {
    if (i == n) {

      vis[i] = 2;
      dp[i] = 1;
      return;
    }

    vis[i] = 1;

    for (auto j : adj[i]) {

      if (!vis[j]) {

        dfs(j, dfs);
      }

      if (vis[j] == 2 && dp[j] != -1 && dp[j] + 1 > dp[i]) {

        child[i] = j;
        dp[i] = dp[j] + 1;
      }
    }

    vis[i] = 2;
  };

  dfs(1, dfs);

  if (dp[1] == -1) {

    std::cout << "IMPOSSIBLE\n";
    return;
  }

  std::cout << dp[1] << "\n";

  ll cur = 1;

  while (cur != -1) {

    std::cout << cur << " ";
    cur = child[cur];
  }

  std::cout << "\n";
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