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
    std::cout<< i << "\t" << LinuxParser::User(i) << "\t" << LinuxParser::Ram(i) << "\t" << LinuxParser::UpTime(i) << "\t" << LinuxParser::Command(i)<< "\n";
  }
  */

//std::cout << system.UpTime() << "\n";
//std::cout << system.Cpu().Utilization() << "\n";
}