#include "sortStudents.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortStudents(std::vector<int> days, std::vector<int> ids) {
	/* your implementation here */
    std::vector<int> ogdays = days;
    
    int ind = 0, day = 0;
    for(int id = 0; id < ids.size(); id++){

        if(ind == days.size()-1) break;
        
        while(day < days.size()){
            if(ids[id] == days[day]){
                if(day != ind){
                    std::swap(days[ind], days[day]);
                }
                ind++;
            }
            day++;
        }
        day = ind;
    }

    for(int d = 0; d < days.size(); d++){
        while(day < days.size()){
            if(ogdays[d] == days[day]){
                if(day != ind){
                    std::swap(days[ind], days[day]);
                }
                ind++;
            }
            day++;
        }
        day = ind;
    }
    return days;
}
