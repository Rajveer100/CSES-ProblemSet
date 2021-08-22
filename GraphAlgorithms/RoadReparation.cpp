//
//  main2.cpp
//  main2
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

constexpr bool test = false;
constexpr ll mod1 = 1e9 + 7;
constexpr ll mod2 = 998244353;
constexpr ll inf = 1e18 + 5;
constexpr ll lim = 1e5 + 5;

void testCase() {

  ll n, m;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<ll, ll>>> adj(n + 1);

  for (int i = 0; i <= m - 1; i++) {

    ll u, v, w;
    std::cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  auto getMST = [&]() {
    std::vector<ll> vis(n + 1), key(n + 1, inf);
    std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>,
                        std::greater<>>
        q;

    q.push({0, 1});
    key[1] = 0;

    std::vector<ll> parent(n + 1, -1);
    ll minCost = 0, edges = 0;

    while (!q.empty()) {

      auto [k, u] = q.top();
      q.pop();

      if (vis[u])
        continue;

      vis[u] = true;

      minCost += k;
      edges++;

      for (auto [v, w] : adj[u]) {

        if (!vis[v] && w < key[v]) {

          key[v] = w;

          q.push({key[v], v});
          parent[v] = u;
        }
      }
    }

    return (edges == n ? minCost : -1);
  };

  ll cost = getMST();

  if (cost == -1) {

    std::cout << "IMPOSSIBLE" << '\n';
    return;
  }

  std::cout << cost << '\n';
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
