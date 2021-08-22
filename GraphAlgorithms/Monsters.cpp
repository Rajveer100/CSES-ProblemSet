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

std::vector<std::pair<ll, ll>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
std::vector<char> dir = {'R', 'D', 'L', 'U'};
std::vector<std::vector<char>> grid;

std::vector<std::vector<ll>> vis, path;

std::pair<ll, ll> root = {-1, -1};
ll n, m;

std::queue<std::pair<ll, ll>> q;

void bfs() {

  q.push(root);
  vis[root.first][root.second] = 1;

  while (!q.empty()) {

    std::pair<ll, ll> cur = q.front();
    q.pop();

    for (int i = 0; i <= 3; i++) {

      ll x = cur.first + d[i].first, y = cur.second + d[i].second;

      if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1 && !vis[x][y] &&
          grid[x][y] == '.') {

        vis[x][y] = vis[cur.first][cur.second];
        path[x][y] = i;
        q.push({x, y});
      }
    }
  }
}

void init() {

  grid.resize(0);
  vis.resize(0);
  path.resize(0);

  grid.resize(n + 5, std::vector<char>(m + 5));
  vis.resize(n + 5, std::vector<ll>(m + 5, 0));
  path.resize(n + 5, std::vector<ll>(m + 5, -1));
}

void testCase() {

  std::cin >> n >> m;

  init();

  for (int i = 0; i <= n - 1; i++) {

    for (int j = 0; j <= m - 1; j++) {

      std::cin >> grid[i][j];

      if (grid[i][j] == 'A') {

        root = {i, j};
      } else if (grid[i][j] == 'M') {

        vis[i][j] = 2;
        q.push({i, j});
      }
    }
  }

  if (root.first == 0 || root.second == 0 || root.first == n - 1 ||
      root.second == m - 1) {

    std::cout << "YES\n";
    std::cout << "0\n";
    return;
  }

  bfs();

  std::pair<ll, ll> goal = {-1, -1};

  for (int i = 0; i <= n - 1; i++) {

    for (int j = 0; j <= m - 1; j++) {

      if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {

        if (path[i][j] != -1 && vis[i][j] != 2) {

          goal = {i, j};
        }
      }
    }
  }

  if (goal.first == -1) {

    std::cout << "NO\n";
    return;
  }

  std::string moves;

  ll cur = path[goal.first][goal.second];

  while (cur != -1) {

    moves += dir[cur];

    goal.first -= d[cur].first;
    goal.second -= d[cur].second;

    cur = path[goal.first][goal.second];
  }

  std::reverse(moves.begin(), moves.end());

  std::cout << "YES\n";

  std::cout << len(moves) << "\n";
  std::cout << moves << "\n";
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