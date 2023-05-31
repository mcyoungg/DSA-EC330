#include "countOOO.h"
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB

// In other words, A is the reference array to which we sort to, B is the array which we will modify
std::tuple<std::vector<std::string>, int> mergesort(std::vector<std::string> B, std::map<std::string, int> A, int count);

int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB) {

    std::map<std::string, int> A;
    int count = 0;
    for(int i = 0; i < rankedListA.size(); i++){
        A[rankedListA[i]] = i;
    }
    std::tuple<std::vector<std::string>, int> result = mergesort(rankedListB, A, count);
	return std::get<1>(result); 
}

std::tuple<std::vector<std::string>, int> mergesort(std::vector<std::string> B, std::map<std::string, int> A, int count){
    int mid = B.size()/2;
    if(B.size() > 1){
   
        std::vector<std::string> left (B.begin(), B.begin()+ mid);
        std::vector<std::string> right (B.begin() + mid, B.begin() + B.size());
        std::tuple<std::vector<std::string>, int> L = mergesort(left, A, count);
        std::tuple<std::vector<std::string>, int> R = mergesort(right, A, count);

        left = std::get<0>(L);
        right = std::get<0>(R);

        int i = 0;
        int j = 0;
        int k = 0;
        
        count += (std::get<1>(L) + std::get<1>(R));
        
        while(i < left.size() && j < right.size()){
            if(A[left[i]] < A[right[j]]){
                B[k] = left[i];
                i++;
            }
            else{
                B[k] = right[j];
                j++;
                count += (mid - i);
            }
            k++;
        }
        while(i < left.size()){
            B[k] = left[i];
            i++;
            k++;
        }
        while(j < right.size()){
            B[k] = right[j];
            j++;
            k++;
        }
    }
    return std::tuple<std::vector<std::string>, int> (B, count);
}
