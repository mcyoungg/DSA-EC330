
#include <iostream>
#include <string>
#include <vector>

#include "sorta.h"
using namespace std;


void bubble_sort(vector<pair<int, int>>& v);

std::string sortByFreq(std::string s) {

    vector<std::pair<int, int>> map = {};
    string res = "";

    vector<int> occur (256);
    for(int i = 0; i < s.length(); i++){
        occur[s[i]]++;
    }

    //creating map, key: frequency, value = decimal rep of each char in input string
    for(int i = 0; i < 256; i++){
        if(occur[i] > 0){
            map.push_back(make_pair(occur[i], i));
        }
    } 
   
    bubble_sort(map);

    //creating resulting string
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].first; j++)
            res += char(map[i].second);
    }
    return res;
}

void bubble_sort(vector<pair<int, int>>& v) {
     for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].first > v[j].first || (v[i].first == v[j].first && v[i].second > v[j].second)) {
                swap(v[i], v[j]);
            }
        }
    }

}


// int main(){

//     //std::cout << sortByFreq("0123456789abcdefghijklmnopqrstuvwxyz") << std::endl;
//     //std::cout << std::endl;
//     std::cout << sortByFreq("ec330") << std::endl; //0ce33
//     //std::cout << sortByFreq("buengec330") << std::endl;

//     return 0;
// }