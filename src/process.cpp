#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::stoi;
using std::vector;

// NEW: setting pid
void Process::Pid(int pid) { pid_ = pid; }

// TODO: Return this process's ID
//DONE
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
// DONE
float Process::CpuUtilization() {
    processCpuUtilization_ = LinuxParser::ProcessCpuUtilization(Pid());
    utime_       = stoi(processCpuUtilization_[13]);
    stime_       = stoi(processCpuUtilization_[14]);
    cutime_      = stoi(processCpuUtilization_[15]);
    cstime_     = stoi(processCpuUtilization_[16]);
    starttime_   = stoi(processCpuUtilization_[21]);

    total_time_ = utime_ + stime_;
    total_time_ += cutime_ + cstime_;
    
    sysUptime_ = LinuxParser::UpTime();
    proElapsedTime_ = sysUptime_ - (starttime_ / sysconf(_SC_CLK_TCK));
    proCpuUsage_ = total_time_ / sysconf(_SC_CLK_TCK);
    proCpuUsage_ /= proElapsedTime_;

    return proCpuUsage_; }

// TODO: Return the command that generated this process
// DONE
string Process::Command() { return LinuxParser::Command(Pid()); }

// TODO: Return this process's memory utilization
// DONE
string Process::Ram() {
    ram_ = stoi(LinuxParser::Ram(Pid()));
    return LinuxParser::Ram(Pid()); }

// TODO: Return the user (name) that generated this process
// DONE
string Process::User() { return LinuxParser::Uid(Pid()); }

// TODO: Return the age of this process (in seconds)
// DONE
long int Process::UpTime() { return LinuxParser::UpTime(Pid()); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
// DONE
bool Process::operator<(Process const& a) const { return (a.ram_ < this->ram_  ? true : false); }