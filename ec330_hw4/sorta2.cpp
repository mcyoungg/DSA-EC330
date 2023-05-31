#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "sorta.h"
using namespace std;

int freqfunc(char c, std::string s);
void counting_sort(vector<pair<int, int>>& v);

std::string sortByFreq(std::string s) {

    std::vector<std::pair<int, int>> map = {};
    std::string res = "";

    //creating map, key: frequency, value = decimal rep of each char in input string
    //int dec = 0;
    // for(int i = 0; i < s.length(); i++){
    //     dec = s[i] - 0;
    //     map.push_back(std::pair<int, int> (freqfunc(s[i], s), dec));
    // } 

    int count[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        count[s[i]]++;
    }

    // Add each character and its frequency to a vector
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            map.push_back(make_pair((char) i, count[i]));
        }
    }

    counting_sort(map);
    cout << "[  ";
    for(auto pr: map)
    {
      // Print the element
      cout << "{";
      cout << pr.first << " , " <<
              pr.second;
      cout << "}  ";
    }
 
    cout << "]\n";
    
    //creating resulting string
    for(int i = 0; i < map.size(); i++){
        res += char(map[i].second);
    }

    return res;
}

void counting_sort(vector<pair<int, int>>& v) {

    //sorting by second value, least significant
    int max_val2 = (max_element(std::begin(v), std::end(v), [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; })) -> second;
    vector<pair<int, int>> temp(v.size());
    vector<int> count(max_val2 + 1, 0);

    for (int i = 0; i < v.size(); i++) {
        count[v[i].second]++;
    }
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        temp[count[v[i].second] - 1] = v[i];
        count[v[i].second]--;
    }
    v = temp;
    
    //sorting by first value, most significant
    int max_val1 = (max_element(std::begin(v), std::end(v), [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; })) -> first;
    count.assign(max_val1 + 1, 0);

    for (int i = 0; i < v.size(); i++) {
        count[v[i].first]++;
    }
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        temp[count[v[i].first] - 1] = v[i];
        count[v[i].first]--;
    }
    v = temp;
}

// int freqfunc(char c, std::string s){
//     int count = 0;
//     for(int i = 0; i < s.length(); i++){
//         if(s[i] == c){
//             count++;
//         }
//     }
//     return count;
// }

int main(){

    //std::cout << sortByFreq("0123456789abcdefghijklmnopqrstuvwxyz") << std::endl;
    //std::cout << std::endl;
    std::cout << sortByFreq("ec330") << std::endl; //0ce33
    //std::cout << sortByFreq("buengec330") << std::endl;

    return 0;
}