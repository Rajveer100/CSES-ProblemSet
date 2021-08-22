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
  
  std::vector<std::vector<int>> dp(n + 1, std::vector<int> (2));
  auto dfs = [&](int u, int p, auto&& dfs) -> void {
    for (auto& v: adj[u]) {
      if (v != p) {
        dfs(v, u, dfs);
        dp[u][1] = std::max(dp[u][1] + std::max(dp[v][0], dp[v][1]),
                            dp[u][0] + dp[v][0] + 1);
        dp[u][0] += std::max(dp[v][0], dp[v][1]);
      }
    }
  };
  dfs(1, 0, dfs);
  
  std::cout << std::max(dp[1][0], dp[1][1]) << '\n';
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
