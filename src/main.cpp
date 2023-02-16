#include "ncurses_display.h"
#include "system.h"

#include <iostream>
#include "linux_parser.h"
int main() {
  System system;
  NCursesDisplay::Display(system);

  /*
  for(auto i : LinuxParser::Pids())
  {
    //std::cout<< "!" << i << "!\t!" << LinuxParser::ProcessCpuUtilization(i)[13] << "!\t!" << LinuxParser::ProcessCpuUtilization(i)[14] << "!\t!" << LinuxParser::ProcessCpuUtilization(i)[15] << "!\t!" << LinuxParser::ProcessCpuUtilization(i)[16] << "!\t!" << LinuxParser::ProcessCpuUtilization(i)[21] << "!\t!" << "\n";
    //long z = LinuxParser::UpTime(i);
    //LinuxParser::Ram(i);
  }
  */

  //int z = LinuxParser::RunningProcesses();
  //int z = LinuxParser::TotalProcesses();

  /*
  std::cout << "!" << LinuxParser::CpuUtilization()[0] << "!\n";
  std::cout << "!" << LinuxParser::CpuUtilization()[1] << "!\n";
  std::cout << "!" << LinuxParser::CpuUtilization()[2] << "!\n";
  std::cout << "!" << LinuxParser::CpuUtilization()[3] << "!\n";
  std::cout << "!" << LinuxParser::CpuUtilization()[4] << "!\n";
  std::cout << "!" << LinuxParser::CpuUtilization()[5] << "!\n";
  std::cout << "!" << LinuxParser::CpuUtilization()[6] << "!\n";
  std::cout << "!" << LinuxParser::CpuUtilization()[7] << "!\n";
  */
 
  //vector<int> z =  LinuxParser::Pids();

  //string value{"0"};
  //std::cout << "!" << value << "!\t!" << std::stoi(value) << "!\n";



  // long z = LinuxParser::UpTime();
  //float z = LinuxParser::MemoryUtilization();
  //std::cout << system.UpTime() << "\n";
  //std::cout << system.Cpu().Utilization() << "\n";
}