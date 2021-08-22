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
ll lim = 1e6 + 5;

void testCase() {

  ll n, m;

  std::cin >> n >> m;

  std::vector<std::vector<ll>> adj(n + 1);

  for (int i = 0; i <= m - 1; i++) {

    ll u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
  }

  std::vector<ll> topo, vis(n + 1, 0);

  auto dfs = [&](ll i, ll p, auto &&dfs) -> void {
    vis[i] = true;

    for (auto j : adj[i]) {

      if (!vis[j]) {

        dfs(j, i, dfs);
      }
    }

    topo.push_back(i);
  };

  dfs(1, 0, dfs);

  std::reverse(topo.begin(), topo.end());

  std::vector<ll> dp(n + 1, 0);
  dp[1] = 1;

  for (auto u : topo) {

    for (auto v : adj[u]) {

      dp[v] = (dp[v] + dp[u]) % mod1;
    }
  }

  std::cout << dp[n] << "\n";
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