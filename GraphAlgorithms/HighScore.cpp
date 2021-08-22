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
ll inf = 1e15 + 5;

std::vector<std::pair<std::pair<ll, ll>, ll>> adj;
std::vector<ll> dist;

std::vector<std::vector<ll>> adj2;
std::vector<bool> vis;
bool neg = false;

void dfs(ll i) {

  vis[i] = true;

  if (dist[i] == -inf) {

    neg = true;
  }

  for (ll j : adj2[i]) {

    if (!vis[j]) {

      dfs(j);
    }
  }
}

bool bellmanFord(ll n, ll m) {

  dist[1] = 0;

  for (int i = 0; i <= n - 2; i++) {

    for (int j = 0; j <= m - 1; j++) {

      ll u = adj[j].first.first, v = adj[j].first.second, w = adj[j].second;

      if (dist[u] != inf && dist[u] + w < dist[v]) {

        dist[v] = dist[u] + w;
      }
    }
  }

  adj2.resize(n + 1);

  for (int i = 0; i <= m - 1; i++) {

    ll u = adj[i].first.first, v = adj[i].first.second, w = adj[i].second;

    if (dist[u] != inf && dist[u] + w < dist[v]) {

      dist[v] = -inf;
    }
    adj2[v].push_back(u);
  }

  vis.resize(n + 1, false);
  dfs(n);

  if (neg) {

    return false;
  }

  return true;
}

void testCase() {

  ll n, m;

  std::cin >> n >> m;

  dist.resize(n + 1, inf);

  for (int i = 0; i <= m - 1; i++) {

    ll u, v, x;
    std::cin >> u >> v >> x;

    adj.push_back({{u, v}, -x});
  }

  if (!bellmanFord(n, m)) {

    std::cout << "-1\n";
  } else {

    std::cout << -dist[n] << "\n";
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