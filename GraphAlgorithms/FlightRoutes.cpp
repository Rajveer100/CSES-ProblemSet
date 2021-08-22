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

  ll n, m, k;

  std::cin >> n >> m >> k;

  std::vector<std::vector<std::pair<ll, ll>>> adj(n + 1);

  for (int i = 0; i <= m - 1; i++) {

    ll u, v, d;
    std::cin >> u >> v >> d;

    adj[u].push_back({v, d});
  }

  std::vector<std::vector<ll>> dist(n + 1, std::vector<ll>(k + 1, inf));

  std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>,
                      std::greater<std::pair<ll, ll>>>
      q;
  q.push({0, 1});

  dist[1][1] = 0;

  while (!q.empty()) {

    auto [x, u] = q.top();
    q.pop();

    if (dist[u][k] < x) {

      continue;
    }

    for (auto [v, d] : adj[u]) {

      if (x + d < dist[v][k]) {

        dist[v][k] = x + d;
        q.push({dist[v][k], v});

        std::sort(dist[v].begin() + 1, dist[v].end());
      }
    }
  }

  for (int i = 1; i <= k; i++) {

    std::cout << dist[n][i] << " \n"[i == n - 1];
  }
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
