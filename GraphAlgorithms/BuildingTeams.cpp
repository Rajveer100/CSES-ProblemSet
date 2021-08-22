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
ll inf = 1e15 + 5;

std::vector<std::vector<ll>> adj(2e5 + 5);
std::vector<ll> colour(2e5 + 5);

bool bi = true;

void dfs(ll i) {

  for (ll j : adj[i]) {

    if (!colour[j]) {

      colour[j] = (colour[i] == 1 ? 2 : 1);
      dfs(j);
    } else if (colour[i] == colour[j]) {

      bi = false;
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

  for (int i = 1; i <= n; i++) {

    if (!colour[i]) {

      colour[i] = 1;
      dfs(i);
    }
  }

  dfs(1);

  if (!bi) {

    std::cout << "IMPOSSIBLE\n";
    return;
  }

  for (int i = 1; i <= n; i++) {

    std::cout << colour[i] << " ";
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