#include "job.h"
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

bool is_bipartie_dfs(int node, unordered_map<int, vector<int>>& graph, vector<int>& color, set<int> visited) {

    visited.insert(node);
    for(int neighbor: graph[node]){
        if(visited.find(neighbor) == visited.end()){

            color[neighbor] = !color[node];

            if(!is_bipartie_dfs(neighbor, graph, color, visited)){
                return false;
            }
        }
        else if (color[node] == color[neighbor]){
            return false;
        }

    }

    return true;
    
}


int main() {

    unordered_map<int, vector<int>> adjlist = {{1, {2,4}}, {2, {1,5}}, {4, {1,5}}, {5, {2,4}}};
    int n = 7;
    vector<int> color(n);
    set<int> visited = {};
    cout << is_bipartie_dfs(1, adjlist, color, visited) <<endl;

    return 0;
}