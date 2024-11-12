# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Espressif/frameworks/esp-idf-v4.4.2/components/bootloader/subproject"
  "D:/Espressif/myproject/queue_test/build/bootloader"
  "D:/Espressif/myproject/queue_test/build/bootloader-prefix"
  "D:/Espressif/myproject/queue_test/build/bootloader-prefix/tmp"
  "D:/Espressif/myproject/queue_test/build/bootloader-prefix/src/bootloader-stamp"
  "D:/Espressif/myproject/queue_test/build/bootloader-prefix/src"
  "D:/Espressif/myproject/queue_test/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Espressif/myproject/queue_test/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
