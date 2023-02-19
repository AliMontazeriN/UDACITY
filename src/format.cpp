#include <string>

#include "format.h"

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function

// DONE
string Format::ElapsedTime(long seconds) {
    int HH, MM, SS = 0;
    HH = seconds / 3600;
    MM = (seconds % 3600) / 60;
    SS = seconds % 60;

    string elapsedTime{""};
    elapsedTime = "";
    
    string sec = to_string(SS);
    sec.insert(0, 2 - sec.length(), '0');

    string min = to_string(MM);
    min.insert(0, 2 - min.length(), '0');
    
    string hrs = to_string(HH);
    hrs.insert(0, 2 - hrs.length(), '0');

    elapsedTime = hrs + ":" + min + ":" + sec;
    return elapsedTime;
    }