@echo off

rem cl.exe /nologo /Od /arch:AVX2 /std:c11 /Zi /Wall /c /Fo:"engn.obj" engn.c
glslang -S comp -V -o engn.spv engn.glsl
nasm.exe -g -f win64 -o engn.obj engn.s
link.exe /debug /subsystem:console /entry:"ENTRY" /nologo /out:engn.exe engn.obj kernel32.lib
