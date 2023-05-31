#include "job.h"
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;
bool dfs(map<int, vector<int>> adjlist, int v, map<int,bool> color);

bool canFinish(int n, vector<pair<int, int>> &dependencies){ 
  //to have a valid topological sort, the graph must be acyclic
  map<int, vector<int>> adjlist = {};
 
  for (const auto& pair : dependencies){
      adjlist[pair.first].push_back(pair.second);   
  }

  vector<int> color(n, 0);
  stack<int> s;

  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      s.push(i);
      color[i] = 1;

      while (!s.empty()) {
        int v = s.top();
        bool notvisited = false;

        for (int neighbor : adjlist[v]) {
            if (color[neighbor] == 0) {
                s.push(neighbor);
                color[neighbor] = 1;
                notvisited = true;
                break;

            }
            else if (color[neighbor] == 1) { //cycle
                return false;
            }
        }
        if (!notvisited) {
            s.pop(); //color all neighbors
            color[v] = 2;
        }
      }
    }
  }

    return true;
}

void dfs(int node, unordered_map<int, vector<int>>& graph, set<int>& visited) {
    
    visited.insert(node);
  
    for(int neighbor: graph[node]){
        if(visited.find(neighbor) == visited.end()){
          dfs(neighbor, graph, visited);
        }

    }
}


bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i){
    unordered_map<int, vector<int>> adjlist = {};

    for (const auto& pair : dependencies){
      adjlist[pair.second].push_back(pair.first);   
    }
    set<int> visited;

    dfs(j, adjlist, visited);
    
    if(visited.size() > i){
        return false;
    }
    
    return true;
}
