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

std::vector<std::pair<ll, ll>> d = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
std::vector<char> dir = {'L', 'D', 'R', 'U'};

std::vector<std::vector<char>> map(1005, std::vector<char>(1005));
std::vector<std::vector<ll>> path(1005, std::vector<ll>(1005, -1));

ll n, m;

void bfs(ll i, ll j) {

  std::queue<std::pair<ll, ll>> q;

  q.push({i, j});

  while (!q.empty()) {

    ll x = q.front().first, y = q.front().second;
    q.pop();

    for (int k = 0; k <= 3; k++) {

      ll nx = x + d[k].first, ny = y + d[k].second;

      if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1) {

        if (map[nx][ny] != '#') {

          map[nx][ny] = '#';
          q.push({nx, ny});
          path[nx][ny] = k;
        }
      }
    }
  }
}

void testCase() {

  std::cin >> n >> m;

  ll x = -1, y = -1, dx = -1, dy = -1;

  for (int i = 0; i <= n - 1; i++) {

    for (int j = 0; j <= m - 1; j++) {

      char c;
      std::cin >> c;

      map[i][j] = c;

      if (map[i][j] == 'A') {

        x = i;
        y = j;
      } else if (map[i][j] == 'B') {

        dx = i;
        dy = j;
      }
    }
  }

  map[x][y] = '#';

  bfs(x, y);

  if (path[dx][dy] == -1) {

    std::cout << "NO\n";
    return;
  }

  std::string s;

  while (dx != x || dy != y) {

    ll pp = path[dx][dy];

    s.push_back(dir[pp]);

    dx -= d[pp].first;
    dy -= d[pp].second;
  }

  std::reverse(s.begin(), s.end());

  std::cout << "YES\n";

  std::cout << len(s) << "\n";

  for (int i = 0; i <= len(s) - 1; i++) {

    std::cout << s[i];
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