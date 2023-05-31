
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> priorPerm(std::vector<int> P){

    //conditions to check if array is ascending, or empty
    bool is_ascend = true;
    for (int i = 0; i < P.size()-1; i++) {
        if (P[i] > P[i + 1]) {
            is_ascend = false;
            break; 
        }
    }
    if(is_ascend || P.empty()){
        return P;
    }
    //find where not descending, from right to lefft
    int div = 0;
    for(int i = P.size() - 2; i >= 0; i--){
        if(P[i] > P[i+1]){
            div = i;
            break;
        }
    }
    //find element that is the next closest smallest element than our div --> (ins) on the right side of div
    // we then swap the values of div and ins 
    // aftwer swaping, sort the elements in descending order after div
    int ins = 0;
    int maxs = -1; //bu ids cannot be negative
    for (int i = div+1; i < P.size(); i++) {
        if(P[i] < P[div] && P[i] > maxs){
            maxs = P[i];
            ins = i;
        }
    }
    swap(P[div], P[ins]);
    sort(P.begin() + (1 + div), P.end(), greater<int>());

return P;

}
