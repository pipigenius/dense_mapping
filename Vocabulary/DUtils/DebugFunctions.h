/*
 * File: DebugFunctions.h
 * Author: Dorian Galvez-Lopez
 * Date: April 2012
 * Description: debug functions
 * License: see the LICENSE.txt file
 *
 */

#ifndef __D_DEBUG__
#define __D_DEBUG__

#include <string>
#include "Profiler.h"

namespace DUtils
{

/**
 * Measures the approx. memory consumption of the given command and prints it 
 * with a title
 * @param cmd command
 * @param s title
 */
#define MEMORY_S(cmd, s) \
  { unsigned long s_begin, s_end; \
    s_begin = DUtils::DebugFunctions::getMemoryUsage(); \
    cmd; \
    s_end = DUtils::DebugFunctions::getMemoryUsage(); \
    std::cout << s << " - memory used: " \
      << DUtils::DebugFunctions::formatBytes(s_end - s_begin) \
      << std::endl; \
  }

/**
 * Measures the approx. memory consumption of the given command and prints it
 * @param cmd command
 */
#define MEMORY(cmd) MEMORY_S(cmd, "")

/**
 * Measures the time and memory consumption of the given command and prints it
 * with a title
 * @param cmd command
 * @param s title
 */
#define WATCH_S(cmd, s) \
  { DUtils::Timestamp t_begin, t_end; \
    unsigned long s_begin, s_end; \
    s_begin = DUtils::DebugFunctions::getMemoryUsage(); \
    t_begin.setToCurrentTime(); \
    cmd; \
    t_end.setToCurrentTime(); \
    s_end = DUtils::DebugFunctions::getMemoryUsage(); \
    std::cout << s << " - elapsed time: " \
      << DUtils::Timestamp::Format(t_end - t_begin) \
      << ", memory used: " \
      << DUtils::DebugFunctions::formatBytes(s_end - s_begin) \
      << std::endl; \
  }

/**
 * Measures the time and memory consumption of the given command and prints it
 * @param cmd command
 */
#define WATCH(cmd) WATCH_S(cmd, "")

class DebugFunctions
{
public:

  /**
   * Returns the memory usage of the current process in bytes
   * @note Only *nix version provided. In windows, it returns 0
   */
  static unsigned long getMemoryUsage();

  /**
   * Returns a string representing a human-readable version of the given
   * bytes
   * @param bytes
   * @param factor conversion factor between kilo, mega, etc 
   *   (usually 1024 or 1000)
   * @return human-readable string
   */
  static std::string formatBytes(unsigned long bytes, 
    unsigned long factor = 1024);

};

} // namespace DUtils

#endif

