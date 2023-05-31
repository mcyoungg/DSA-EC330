#include <iostream>
#include <string>
#include <vector>
#include "sorta.h"

std::string sortByFreq(std::string s) {
	// ...
    //algorithm:
    //create array to store number of occurrences, occur[36]
    //create resultant vector, res
    //iterate through input
    //check input to see if character is a number (dec <= 48) or if alpha (dec >= 97)
    //implement corresponding hash function, and increment associated index

    //iterate through occurrnce array, O(n^2)
        //for each index checking the number of ocuurrences in increasing order (1-35)
        //reverse hash:
        //for digits, if ind < 10 append to res array
        //for indicies greater than 9, implement new hash function to map the indiex to the character, appebd it to res array

    // ...
    int const size = 36;
    int occur[size] = {};
    std::vector<int> keys = {};
    std::vector<int> sorted (s.length());
    std::string res = "";
    std::string pat = "0123456789abcdefghijklmnopqrstuvwxyz";


    int dec, ind = 0; 
    for(int i = 0; i < s.size(); i ++){
        dec = s[i] - 0;
        if(dec < 97){
            ind = dec - 48;
            occur[ind]++;
        }
        else{
            ind = dec - 87;
            occur[ind]++;
        }
    }

    //creating cumumlative sum array
    for(int i = 1; i < size; i ++){
        occur[i] = occur[i] + occur[i-1];
    }
 
    for(int i = s.length()-1; i >= 0; i --){

        dec = s[i] - 0;
        if(dec < 97){
            ind = dec - 48;
        }
        else{
            ind = dec - 87;
        }
        //std::cout << dec << " " << ind << std::endl;
        sorted[occur[ind]-1] = dec;
        //std::cout << ind << " " << sorted[occur[ind]] << " . ";
        occur[ind] = occur[ind] - 1;
    }


   //creating res array
    for(int i = 0; i < sorted.size(); i++){
        std::cout << sorted[i] << " ";
        res += char(sorted[i]);
        
   }

    return res; // you will need to change this
}



int main(){

    //std::cout << sortByFreq("0123456789abcdefghijklmnopqrstuvwxyz") << std::endl;
    std::cout << sortByFreq("ec330") << std::endl; //girsnneee

    return 0;
}