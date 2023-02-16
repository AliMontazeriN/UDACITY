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
    elapsedTime = to_string(HH) + ":" + to_string(MM) + ":" + to_string(SS);
    return elapsedTime;
    }