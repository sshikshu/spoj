#include <algorithm>
#include <iostream>
#include <array>
#include <set>
#include <stack>

using namespace std;

bool dfs(set<int> edges[], int n, int startFrom) {
  bool visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  stack<int> placesToVisit;
  placesToVisit.push(startFrom);
  int currentlyVisiting, doneVisiting = 0;
  while (!placesToVisit.empty()) {
    //cout << placesToVisit.top() << endl;
    currentlyVisiting = placesToVisit.top();
    placesToVisit.pop();
    visited[currentlyVisiting] = true;
    for (int node : edges[currentlyVisiting]) {
      edges[node].erase(currentlyVisiting);
      if (visited[node]) {
        return false;
      }
      placesToVisit.push(node);
    }
    ++doneVisiting;
  }
  return doneVisiting == n;
}

int main(int argc, char *argv[]) {
  int n, m, temp1, temp2;
  cin >> n >> m;
  set<int> edges[n];

  for (int i = 0; i < n; i++) {
    cin >> temp1 >> temp2;
    edges[temp1 - 1].emplace(temp2 - 1);
    edges[temp2 - 1].emplace(temp1 - 1);
  }

  /*for (set<int> edge : edges) {
    for_each(edge.begin(), edge.end(), [](int i) { cout << i << " "; });
    cout << endl;
  }*/
  if (n - 1 == m && dfs(edges, n, 0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
