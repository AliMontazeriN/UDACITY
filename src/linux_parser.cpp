#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::stoi;
using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel, version;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
// DONE
float LinuxParser::MemoryUtilization() {
  float MemTotal;
  float MemFree;
  string key;
  string value;
  string line;

  std::ifstream stream(kProcDirectory+kMeminfoFilename);
  if(stream.is_open()){
    while(std::getline(stream, line))
    {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if(key == "MemTotal:") {MemTotal = stof(value);}
      if(key == "MemFree:") {MemFree = stof(value);}
    }
  }
  return (MemTotal - MemFree)/MemTotal;
  }

// TODO: Read and return the system uptime
// DONE
long LinuxParser::UpTime() {
  string systemUptime {"0"};
  string idleTime {"0"};
  string line;

  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if(stream.is_open())
  {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> systemUptime >> idleTime;
  }
  return (static_cast<long>(stoi(systemUptime)));
  }

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid[[maybe_unused]]) { return 0; }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { return 0; }

// TODO: Read and return CPU utilization
// DONE
vector<string> LinuxParser::CpuUtilization() {
  vector<string> cpuUtilization{};
  string line;
  string key;
  string value;

  std::ifstream stream(kProcDirectory + kStatFilename);
  if(stream.is_open())
  {
    while(std::getline(stream, line))
    {
      std::istringstream linestream(line);
      linestream >> key;
      if(key == "cpu")
      {
        for(int i = 0; i < 10 ; i++)
        {
          linestream >> value;
          cpuUtilization.push_back(value);
        }
      }
    }
  }
  return cpuUtilization; }

// TODO: Read and return the total number of processes
// DONE
int LinuxParser::TotalProcesses() {
  string line;
  string key;
  string value{"0"};

  std::ifstream stream(kProcDirectory + kStatFilename);
  if(stream.is_open()){
    while(std::getline(stream, line))
    {
      std::istringstream linestream(line);
      while(linestream >> key >> value)
      {
        if(key == "processes")
        {
          return stoi(value);
        }
      }
    }
  }
  return std::stoi(value);
  }

// TODO: Read and return the number of running processes
// DONE
int LinuxParser::RunningProcesses() {
  string line;
  string key;
  string value{"0"};

  std::ifstream stream(kProcDirectory + kStatFilename);
  if(stream.is_open()){
    while(std::getline(stream, line))
    {
      std::istringstream linestream(line);
      while(linestream >> key >> value)
      {
        if(key == "procs_running")
        {
          return std::stoi(value);
        }
      }
    }
  }
  return std::stoi(value);
  }

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid)
  {
  string line;

  std::ifstream stream(kProcDirectory + to_string(pid) + kCmdlineFilename);
  if(stream.is_open())
  {
    std::getline(stream, line);
  }
  return line;
  }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
// DONE
string LinuxParser::Ram(int pid)
{
  string line;
  string key;
  string valueKB;
  string valueMB;
  int valueInt;

  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  if(stream.is_open())
  {
    while(std::getline(stream, line))
    {
      std::istringstream linestream(line);
      linestream >> key >> valueKB;
      if(key == "VmSize:")
      {
        valueInt = stoi(valueKB);
        valueInt /= 1000;
        valueMB = to_string(valueInt);
        return valueMB;
      }
    }
  }
  return valueMB;
  }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
// DONE
string LinuxParser::Uid(int pid) {
  string line;
  string key;
  string value;

  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  if(stream.is_open())
  {
    while(std::getline(stream, line))
    {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if(key == "Uid:")
      {
        return value;
      }
    }
  }
  return value;
  }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
// DONE
string LinuxParser::User(int pid)
{
  string line;
  string key;
  string keyx;
  string value;

  std::ifstream stream(kPasswordPath);
  if(stream.is_open())
  {
    while(std::getline(stream, line))
    {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      linestream >> key >> keyx >> value;
      if(value == Uid(pid))
      {
        return key;
      }
    }
  }
  return key;
  }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
// DONE
long LinuxParser::UpTime(int pid) {
  string processUptime {"0"};
  long longProcessUpTime;
  string line;
  string value;

  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if(stream.is_open())
  {
    std::getline(stream, line);
    std::istringstream linestream(line);
    for(uint i=0; i<22; i++)
    {
      linestream >> value;
    }
    processUptime = value;
  }
  longProcessUpTime = static_cast<long>(stoi(processUptime));
  longProcessUpTime /= sysconf(_SC_CLK_TCK);
  return longProcessUpTime;
  }

// NEW: extracting the process cpu utilization info
vector<string> LinuxParser::ProcessCpuUtilization(int pid) {
  vector<string> processCpuUtilization{};
  string line;
  string value;

  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if(stream.is_open())
  {
    std::getline(stream, line);
    std::istringstream linestream(line);
      for(int i = 0; i < 22 ; i++)
      {
        linestream >> value;
        processCpuUtilization.push_back(value);
      }
  }
  return processCpuUtilization; }