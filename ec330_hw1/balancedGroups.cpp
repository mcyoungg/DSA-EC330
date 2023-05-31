/*
reference:
https://www.geeksforgeeks.org/print-equal-sum-sets-of-array-partition-problem-using-dynamic-programming/
*/

#include "balancedGroups.h"
#include <iostream>
#include <vector>

using namespace std;

Assignment balancedGroups(std::vector<int> const &birthdays) {
    vector<int> v1;
    vector<int> v2;
    
    //find the sum of input
    int total = 0;
    for(int i = 0; i <= birthdays.size(); i++){
        total += birthdays[i];
        
    }
   
    // for optimization, we want to divide the values into 2 groups where
    // the sum of each group is nearly half of the original sum, and which will
    // minimize the subset difference

    //state: number of items under consideration (i)
    //state: sum (j)
    int hsum = total/2;
    bool tr[birthdays.size()+1][hsum+1];  // i x j

    //it is not possible to have a sum, when there are 0 elements to consider
    for(int j = 1; j <= hsum; j++){
        tr[0][j] = false;
    }

    //it is possible to have a zero sum, with all elements under consideration
    for(int i = 0; i <= birthdays.size(); i++){
        tr[i][0] = true;
    }

    //calculating the table to determine whether a certain sum can be formmed given a certain number of elements
    for(int i = 1; i <= birthdays.size(); i++){
        for(int j = 1; j <= hsum; j++){
            if(birthdays[i-1] > j){
            //exclude this element, it will not contribute to the sum of the first subset
                tr[i][j] = tr[i-1][j];
            }
            //include or exclude the element
            else{
                tr[i][j] = tr[i-1][j] || tr[i-1][j-birthdays[i-1]];
            }                    
        }
    }
    //finding difference and balanced groups
    int i = birthdays.size();
    int csum = hsum;
    int s1 = 0;
    int s2 = 0;

    while( i > 0 && csum >= 0){
        if(tr[i-1][csum]){
            i-=1;
            v2.push_back(birthdays[i]);
            s1 += birthdays[i];
        }
        else if(tr[i-1][csum - birthdays[i-1]]){
            i-=1;
            csum -= birthdays[i];
            v1.push_back(birthdays[i]);
            s2 += birthdays[i];
        }
    }
    int diff = abs(s1-s2);
    
	return Assignment(diff, v1, v2); // Don't forget to change this
}

