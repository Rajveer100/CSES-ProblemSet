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

  std::vector<std::vector<std::pair<ll, ll>>> adj(n + 1);

  for (int i = 0; i <= m - 1; i++) {

    ll u, v, w;
    std::cin >> u >> v >> w;

    adj[u].push_back({v, w});
  }

  std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(3));

  auto djikstra = [&]() {
    std::vector<ll> dist(n + 1, inf), vis(n + 1, 0);
    std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>,
                        std::greater<>>
        q;

    q.push({0, 1});
    dist[1] = 0;

    dp[1][0] = 1;

    while (!q.empty()) {

      ll u = q.top().second;
      q.pop();

      if (vis[u]) {

        continue;
      }

      vis[u] = true;

      for (auto [v, w] : adj[u]) {

        if (dist[u] + w < dist[v]) {

          dist[v] = dist[u] + w;
          q.push({dist[v], v});

          dp[v][0] = dp[u][0];

          dp[v][1] = dp[u][1] + 1;
          dp[v][2] = dp[u][2] + 1;
        } else if (dist[u] + w == dist[v]) {

          q.push({dist[v], v});

          dp[v][0] = (dp[v][0] + dp[u][0]) % mod1;

          dp[v][1] = std::min(dp[v][1], dp[u][1] + 1);
          dp[v][2] = std::max(dp[v][2], dp[u][2] + 1);
        }
      }
    }

    return dist[n];
  };

  ll minCost = djikstra();

  std::cout << minCost << ' ' << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2]
            << '\n';
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.precision(15);

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (int i = 0; i <= t - 1; i++) {

    //        std::cout << "Case #" << i + 1 << ": ";
    testCase();
  }
}
