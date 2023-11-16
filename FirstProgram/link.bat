@ECHO OFF

REM COMPILE SOURCE CODE
cl /nologo /Zi /GR- /EHs /W3 /MDd /Fe:program.exe *.obj ws2_32.lib 