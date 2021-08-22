//
//  main2.cpp
//  main2
//
//  Created by Rajveer Singh on 21/01/22.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <string>
#include <time.h>
#include <chrono>
#include <array>
#include <random>
#include <ctime>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <unordered_map>
#include <numeric>
#include <cstring>
#include <cassert>

//MARK:- PRACTICE

#define len(a) (int) a.size()

constexpr bool test = false;
constexpr long long mod1 = 1e9 + 7;
constexpr long long mod2 = 998244353;
constexpr long long inf = 9e18 + 5;
constexpr int lim = 1e6 + 5;

void testCase() {
  int n;
  std::cin >> n;
  
  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i <= n - 2; i++) {
    int u, v;
    std::cin >> u >> v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  int maxDist = 0;
  auto dfs = [&](int u, int p, int dist, int& s, auto&& dfs) -> void {
    for (auto& v: adj[u]) {
      if (v != p) {
        dfs(v, u, dist + 1, s, dfs);
      }
    }
    if (dist >= maxDist) {
      maxDist = dist;
      s = u;
    }
  };
  
  int a = -1, b = -1;
  
  dfs(1, 0, 0, a, dfs);
  dfs(a, 0, 0, b, dfs);
  
  std::vector<std::vector<int>> dist(n + 1, std::vector<int> (2));
  auto dfsDist = [&](int u, int p, int from, int d, auto&& dfsDist) -> void {
    dist[u][from] = d;
    for (auto& v: adj[u]) {
      if (v != p) {
        dfsDist(v, u, from, d + 1, dfsDist);
      }
    }
  };
  dfsDist(a, 0, 0, 0, dfsDist);
  dfsDist(b, 0, 1, 0, dfsDist);
  
  for (int i = 1; i <= n; i++) {
    std::cout << std::max(dist[i][0], dist[i][1]) << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(15);
  
  int t = 1;
  
  if (test) {
    std::cin >> t;
  }
  
  for (int i = 0; i <= t - 1; i++) {
    //    std::cout << "Case #" << i + 1 << ": ";
    testCase();
  }
}

