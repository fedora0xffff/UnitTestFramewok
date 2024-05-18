/***************************************************************************//**
 * This is a simple library for unit testing. 
 *
 * This library provides:
 * - several template fucntions for container output,
 * - template asserts which provide useful info and throw std::runtime_error 
 * in case of assert failure,
 * - the tester class aimed to run tests, count failures, handle exceptions,
 * - helper macros for short asserts and test running
 *
 *  support: fedora0xffff
 ******************************************************************************/

#pragma once

#include <sstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <type_traits>

namespace unittest {
  
  /// @brief functions for pretty container output 
  template <typename T>
  std::ostream& operator<<(std::ostream& os, const std::vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
      if (!first) {
        os << ", ";
      }
      first = false;
      os << x;
    }
    return os << "}";
  }

  template <typename T>
  std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
      if (!first) {
        os << ", ";
      }
      first = false;
      os << x;
    }
    return os << "}";
  }

  template <typename K, typename V>
  std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
      if (!first) {
        os << ", ";
      }
      first = false;
      os << kv.first << ": " << kv.second;
    }
    return os << "}";
  }

  template <typename F, typename S>
  std::ostream& operator<<(std::ostream& os, const std::pair<F, S>& p) {
    os << '{' << p.first << ", " << p.second << '}';
    return os;
  }

  //traits for iterable check
  template<typename, typename = void>
  constexpr bool is_iterable = false;
 
  template<typename T>
  constexpr bool is_iterable<
      T,
      std::void_t<decltype(std::declval<T>().begin()),
                  decltype(std::declval<T>().end())
      >
  > = true;

  template <typename Collection, std::enable_if_t<is_iterable<Collection>, bool> = true>
  std::string Join(const Collection& col, char delim = ' ') {
    std::ostringstream os;
    bool first = true;
    for (auto&& elem: col) {
      if (first) {
        os << elem;
        first = false;
      } else {
        os << delim << elem;
      }
    }
    return os.str();
  }

  /// @brief template asserts
  template <class T, class U>
  void AssertEqual(const T& t, const U& u, const std::string& hint = {}) {
    if (!(t == u)) {
      std::ostringstream os;
      os << "Assertion failed: " << t << " != " << u;
      if (!hint.empty()) {
        os << " hint: " << hint;
      }
      throw std::runtime_error(os.str());
    }
  }

  inline void Assert(bool b, const std::string& hint) {
    AssertEqual(b, true, hint);
  }

  /// @brief TestRunner class handles test cases, count failures and checks in exceptions
  class TestRunner {
  public:

    template <class TestFunc>
    void RunTest(TestFunc func, const std::string& test_name) {
      try {
        func();
        std::cerr << test_name << " OK" << std::endl;
      } 
      catch (std::exception& e) {
        ++fail_count;
        std::cerr << test_name << " fail: " << e.what() << std::endl;
      } 
      catch (...) {
        ++fail_count;
        std::cerr << "Unknown exception caught" << std::endl;
      }
    }

    ~TestRunner();

  private:
    int fail_count = 0;
  };


  /// @brief helper macros
  #define AS_KV(x) #x << " = " << x

  #define ASSERT(x) {         \ 
      std::ostringstream os;              \
      os << #x << " is false, "           \
      << __FILE__ << ":" << __LINE__;     \
      AssertEqual(x, y, os.str());        \
  }

  #define ASSERT_EQUAL(x, y) {         \ 
      std::ostringstream os;              \
      os << #x << "!=" << #y << ", "      \
      << __FILE__ << ":" << __LINE__;     \
      AssertEqual(x, y, os.str());        \
  }

  #define RUN_TEST(tr, func) \
              tr.RunTest(func, #func)


} //namespace unittest
