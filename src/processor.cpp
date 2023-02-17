#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
// DONE
float Processor::Utilization() {
    strCpuUtilization_ = LinuxParser::CpuUtilization();

    preIdle = Idle;
    preTotal = Total;

    user        = (strCpuUtilization_[0] != "" ? stoi(strCpuUtilization_[0]) : 0);
    nice        = (strCpuUtilization_[1] != "" ? stoi(strCpuUtilization_[1]) : 0);
    system      = (strCpuUtilization_[2] != "" ? stoi(strCpuUtilization_[2]) : 0);
    idle        = (strCpuUtilization_[3] != "" ? stoi(strCpuUtilization_[3]) : 0);
    iowait      = (strCpuUtilization_[4] != "" ? stoi(strCpuUtilization_[4]) : 0);
    irq         = (strCpuUtilization_[5] != "" ? stoi(strCpuUtilization_[5]) : 0);
    softirq     = (strCpuUtilization_[6] != "" ? stoi(strCpuUtilization_[6]) : 0);
    steal       = (strCpuUtilization_[7] != "" ? stoi(strCpuUtilization_[7]) : 0);
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