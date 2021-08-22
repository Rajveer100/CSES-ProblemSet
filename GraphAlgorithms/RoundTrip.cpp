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
ll inf = 1e18 + 5;

std::vector<std::vector<ll>> adj(2e5 + 5);
std::vector<ll> vis(2e5 + 5), path(2e5 + 5);

std::pair<ll, ll> cycle = {-1, -1};

void dfs(ll i, ll p) {

  vis[i] = 1;
  path[i] = p;

  for (ll j : adj[i]) {

    if (!vis[j]) {

      dfs(j, i);
    } else if (j != p && vis[j] == 1) {

      cycle = {j, i};
    }
  }

  vis[i] = 2;
}

void testCase() {

  ll n, m;

  std::cin >> n >> m;

  for (int i = 0; i <= m - 1; i++) {

    ll u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {

    if (!vis[i]) {

      dfs(i, 0);
    }
  }

  if (cycle.first == -1) {

    std::cout << "IMPOSSIBLE\n";
    return;
  }

  std::vector<ll> get;

  get.push_back(cycle.first);

  while (cycle.second != cycle.first) {

    get.push_back(cycle.second);
    cycle.second = path[cycle.second];
  }

  get.push_back(cycle.first);

  std::cout << len(get) << "\n";

  for (ll v : get) {

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