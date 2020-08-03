#!/bin/bash


NDK_PATH="/Users/aaa/Downloads/android-ndk-r17c/toolchains"
SYSROOT="/Users/aaa/Downloads/android-ndk-r17c/sysroot"
INCLUDE="/Users/aaa/Downloads/android-ndk-r17c/sysroot/usr/include"

GCC="arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-gcc"

dir="."
for file in *.c;do
	echo $file;
done

# HEAD_LIB="--sysroot=/Users/aaa/Downloads/android-ndk-r17c/platforms/android-21/arch-arm -isystem /Users/aaa/Downloads/android-ndk-r17c/sysroot/usr/include -isystem /Users/aaa/Downloads/android-ndk-r17c/sysroot/usr/include/arm-linux-androideabi"

# $NDK_PATH/$GCC $HEAD_LIB -fPIC -shared *.c -o libfaac.so









