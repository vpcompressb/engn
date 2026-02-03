@echo off
setlocal

set INCLUDE=%VULKAN_SDK%\Include;%INCLUDE%
set LIB=%VULKAN_SDK%\Lib;%LIB%

clang -Wall -Wextra -O0 -march=znver2 -g -std=gnu90 -o engn.o -c engn.c
lld-link /subsystem:windows /debug /entry:engn engn.o vulkan-1.lib kernel32.lib user32.lib