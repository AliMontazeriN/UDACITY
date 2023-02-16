#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
// DONE
float Processor::Utilization() {
    strCpuUtilization_ = LinuxParser::CpuUtilization();

    preIdle = Idle;
    preTotal = Total;

    user        = stoi(strCpuUtilization_[0]);
    nice        = stoi(strCpuUtilization_[1]);
    system      = stoi(strCpuUtilization_[2]);
    idle        = stoi(strCpuUtilization_[3]);
    iowait      = stoi(strCpuUtilization_[4]);
    irq         = stoi(strCpuUtilization_[5]);
    softirq     = stoi(strCpuUtilization_[6]);
    steal       = stoi(strCpuUtilization_[7]);
//    guest       = stoi(strCpuUtilization_[8]);
//    guest_nice = stoi(strCpuUtilization_[9]);

    Idle = idle + iowait;
    NonIdle = user + nice + system + irq + softirq + steal;
    Total = Idle + NonIdle;

    Totald = Total - preTotal;
    Idled = Idle - preIdle;

    cpuUtilization_ = Totald - Idled;
    cpuUtilization_ /= Totald;

    return cpuUtilization_; 
    }