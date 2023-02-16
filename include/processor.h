#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <vector>

using std::stoi;
using std::string;
using std::vector;

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
 vector<string> strCpuUtilization_;
 float cpuUtilization_ = 0.0;

int preIdle, preTotal;
int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
int Idle, NonIdle, Total;
int Totald, Idled;
};

#endif