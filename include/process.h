#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include<vector>

/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  void Pid(int pid);

  // TODO: Declare any necessary private members
 private:
    int pid_;
    int ram_;
    std::vector<std::string> processCpuUtilization_;
    int utime_;
    int stime_;
    int cutime_;
    int cstime_;
    int starttime_;
    int total_time_;
    int sysUptime_;
    int proElapsedTime_;
    float proCpuUsage_;
};

#endif