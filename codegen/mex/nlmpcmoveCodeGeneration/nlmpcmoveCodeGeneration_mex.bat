@echo off
call setEnv.bat
"C:\Program Files\Polyspace\R2020b\toolbox\shared\coder\ninja\win64\ninja.exe" -t compdb cc cxx cudac > compile_commands.json
"C:\Program Files\Polyspace\R2020b\toolbox\shared\coder\ninja\win64\ninja.exe" -v %*
