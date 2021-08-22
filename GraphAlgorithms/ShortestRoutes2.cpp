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

std::vector<std::vector<ll>> adj, dist;

void floydWarshall(ll n) {

  for (int k = 1; k <= n; k++) {

    for (int i = 1; i <= n; i++) {

      for (int j = 1; j <= n; j++) {

        if (i == j) {

          dist[i][j] = 0;
        }

        if (dist[i][k] != inf && dist[k][j] != inf &&
            dist[i][k] + dist[k][j] < dist[i][j]) {

          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

void testCase() {

  ll n, m, q;

  std::cin >> n >> m >> q;

  adj.resize(n + 1);
  dist.resize(n + 1, std::vector<ll>(n + 1, inf));

  for (int i = 0; i <= m - 1; i++) {

    ll u, v, c;
    std::cin >> u >> v >> c;

    adj[u].push_back(v);
    adj[v].push_back(u);

    dist[u][v] = std::min(dist[u][v], c);
    dist[v][u] = std::min(dist[v][u], c);
  }

  floydWarshall(n);

  for (int i = 0; i <= q - 1; i++) {

    ll u, v;
    std::cin >> u >> v;

    if (dist[u][v] == inf) {

      dist[u][v] = -1;
      dist[v][u] = -1;
    }

    std::cout << std::min(dist[u][v], dist[v][u]) << "\n";
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