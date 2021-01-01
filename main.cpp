#include <iostream>
#include <android/log.h>
#include <cstdio>

int main() {
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name << "!\n";
  __android_log_print(ANDROID_LOG_INFO,  "ABT", "Hello, %s!", name.c_str());
  return 0;
}
