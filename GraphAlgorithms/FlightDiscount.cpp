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

std::vector<std::vector<std::pair<ll, ll>>> foradj, revAdj;
std::vector<bool> vis;

std::vector<ll> dist1, dist2;

void dijkstra(ll s, std::vector<std::vector<std::pair<ll, ll>>> adj,
              std::vector<ll> &dist) {

  std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>,
                      std::greater<>>
      q;
  q.push({0, s});

  dist[s] = 0;

  while (!q.empty()) {

    ll u = q.top().second;
    q.pop();

    if (vis[u]) {

      continue;
    }

    vis[u] = true;

    for (auto v : adj[u]) {

      if (!vis[v.first] && dist[u] + v.second < dist[v.first]) {

        dist[v.first] = dist[u] + v.second;
        q.push({dist[v.first], v.first});
      }
    }
  }
}

void testCase() {

  ll n, m;

  std::cin >> n >> m;

  foradj.resize(n + 1);
  revAdj.resize(n + 1);
  vis.resize(n + 1, false);

  dist1.resize(n + 1, inf);
  dist2.resize(n + 1, inf);

  for (int i = 0; i <= m - 1; i++) {

    ll u, v, c;
    std::cin >> u >> v >> c;

    foradj[u].push_back({v, c});
    revAdj[v].push_back({u, c});
  }

  dijkstra(1, foradj, dist1);

  vis.resize(0);
  vis.resize(n + 1, false);

  dijkstra(n, revAdj, dist2);

  ll minCost = inf;

  for (int i = 1; i <= n; i++) {

    for (auto j : foradj[i]) {

      if (dist1[i] != inf && dist2[j.first] != inf) {

        minCost = std::min(minCost, dist1[i] + j.second / 2 + dist2[j.first]);
      }
    }
  }

  std::cout << minCost << "\n";
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