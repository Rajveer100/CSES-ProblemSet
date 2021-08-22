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

  std::vector<ll> vis(n + 1, 0), parent(n + 1, 0);
  std::pair<ll, ll> cycle = {-1, -1};

  auto dfs = [&](ll i, ll p, auto &&dfs) -> void {
    vis[i] = 1;
    parent[i] = p;

    for (auto j : adj[i]) {

      if (!vis[j]) {

        dfs(j, i, dfs);
      } else if (vis[j] == 1) {

        cycle = {j, i};
      }
    }

    vis[i] = 2;
  };

  for (int i = 1; i <= n; i++) {

    if (!vis[i]) {

      dfs(i, parent[i], dfs);
    }
  }

  if (cycle.first == -1) {

    std::cout << "IMPOSSIBLE\n";
    return;
  }

  std::vector<ll> path = {cycle.first};

  while (cycle.second != cycle.first) {

    path.push_back(cycle.second);
    cycle.second = parent[cycle.second];
  }

  path.push_back(cycle.first);

  std::reverse(path.begin(), path.end());

  std::cout << len(path) << "\n";

  for (auto v : path) {

    std::cout << v << " ";
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