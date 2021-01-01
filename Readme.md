# Developing Native Android Binaries with VSCode

This is an example project for developing and debugging native binaries for Android with VSCode.

## Background

I started developing an Android Application that uses an existing tool written in C++.
The most straightforward way seemed to just include the compiled application in the APK and then interact with it via STDIO.
For my project I intend to add NNAPI support to the binary, which will require some serious debugging.
Unfortunately, I was not able to figure out how to do this from Android Studio nicely.
Debugging JNI works fine, but for a subprocess I would have to attach the debugger manually.
Also, not having to deal with the APK for now simplifies development.

## Setup

Requirements:
- NDK
- VSCode with `cpptools`, `vscode-lldb` and `cmake-tools`

Use `CMake: Select a Kit` to select the `Android` kit (`cmake-kits.json`).
Adjust the NDK paths and `ANDROID_` settings as necessary.
The `compilerPath` including the arguments is taken from `compile_commands.json` (it seems like a bug that the arguments are necessary).
Intellisense should work after compilation (configured in `c_cpp_properties.json`).

## Running

Since CMake builds with `F7`, we can use the build task for running the binary (see `tasks.json`).

## Debugging

We use LLDB for remote debugging.
First, we push the `lldb-server` to the device and forward a port.
```
adb push /home/dorian/Android/Sdk/ndk/22.0.7026061/toolchains/llvm/prebuilt/linux-x86_64/lib64/clang/11.0.5/lib/linux/aarch64/lldb-server /data/local/tmp
adb forward tcp:1234 tcp:1234
```
And start it with
```
adb shell "cd /data/local/tmp; ./lldb-server platform --server --listen '*:1234'"
```

Now we can just debug with `F5` (see `launch.json`).

I have not yet found a nice way to get interactive standard input.
But we can use a file on the device as input:
```
"settings set target.input-path /data/local/tmp/input.txt"
```

## Logging

We can link to any native Android library such as `log`.
Follow the log with
```
adb logcat -s ABT
```