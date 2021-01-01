#include <iostream>
#include <android/log.h>
#include <cstdio>

#define TAG "AndroidBinaryTest"

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,  TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,  TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)

int main() {
  std::string name;
  std::cin >> name;
  // name = "World";
  std::cout << "Hello, " << name << "!\n";
  LOGI("Hello, %s!", name.c_str());
  return 0;
}
