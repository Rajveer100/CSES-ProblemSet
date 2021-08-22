//
//  main.cpp
//  main2
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
ll inf = 1e15 + 5;

std::vector<std::vector<ll>> adj(2e5 + 5);
std::vector<ll> vis(2e5 + 5), path(2e5 + 5);

void bfs() {

  std::queue<ll> q;
  q.push(1);

  while (!q.empty()) {

    ll u = q.front();
    q.pop();

    for (ll v : adj[u]) {

      if (!vis[v]) {

        q.push(v);
        vis[v] = true;
        path[v] = u;
      }
    }
  }
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

  bfs();

  if (!path[n]) {

    std::cout << "IMPOSSIBLE\n";
  } else {

    ll cur = n;
    std::vector<ll> p;

    while (cur != 1) {

      p.push_back(cur);
      cur = path[cur];
    }

    p.push_back(1);

    std::reverse(p.begin(), p.end());

    std::cout << len(p) << "\n";

    for (int i = 0; i <= len(p) - 1; i++) {

      std::cout << p[i] << " ";
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