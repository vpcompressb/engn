@echo off
setlocal

set INCLUDE=%VULKAN_SDK%\Include;%INCLUDE%
set LIB=%VULKAN_SDK%\Lib;%LIB%

clang -Wall -Wextra -O0 -march=znver2 -g -std=gnu90 -o game.o -c game.c
lld-link /subsystem:console /debug /entry:game_0 game.o vulkan-1.lib kernel32.lib ucrt.lib libucrt.lib user32.lib