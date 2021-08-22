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

ll n, m;

std::vector<ll> bellmanFord(ll n, ll m) {

  dist[1] = 0;

  std::vector<ll> parent(n + 1, 0);

  for (int i = 0; i <= n - 2; i++) {

    for (int j = 0; j <= m - 1; j++) {

      ll u = adj[j].first.first, v = adj[j].first.second, w = adj[j].second;

      if (dist[u] != inf && dist[u] + w < dist[v]) {

        parent[v] = u;
        dist[v] = dist[u] + w;
      }
    }
  }

  std::vector<ll> negPath;

  ll start = -1;

  for (int j = 0; j <= m - 1; j++) {

    ll u = adj[j].first.first, v = adj[j].first.second, w = adj[j].second;

    if (dist[u] != inf && dist[u] + w < dist[v]) {

      start = v;
      break;
    }
  }

  if (start != -1) {

    for (int i = 0; i <= n - 1; i++) {

      start = parent[start];
    }

    negPath.push_back(start);

    ll cur = parent[start];

    while (cur != start) {

      negPath.push_back(cur);
      cur = parent[cur];
    }

    negPath.push_back(start);

    std::reverse(negPath.begin(), negPath.end());
  }

  return negPath;
}

void testCase() {

  std::cin >> n >> m;

  dist.resize(n + 1);

  for (int i = 0; i <= m - 1; i++) {

    ll u, v, d;
    std::cin >> u >> v >> d;

    adj.push_back({{u, v}, d});
  }

  std::vector<ll> path = bellmanFord(n, m);

  if (path.empty()) {

    std::cout << "NO\n";
  } else {

    std::cout << "YES\n";

    for (auto v : path) {

      std::cout << v << " ";
    }

    std::cout << "\n";
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