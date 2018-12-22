@echo off

set PROGRAMFILES=Program Files (x86)
If %PROCESSOR_ARCHITECTURE%==x86 If Not Defined PROCESSOR_ARCHITEW6432 Set PROGRAMFILES=Program Files
set VS=C:\%PROGRAMFILES%\Microsoft Visual Studio 12.0\Common7\IDE
set pathToRep=D:\CPlusPlus\Projects

echo %path% | Find /I /c "%VS%" > nul
if %ERRORLEVEL%==0 goto jump
set path=%path%;%VS%
:jump

echo Rebuild %pathToRep%\Lessons Ravesli\Glava0\Glava0.sln
"%VS%\devenv.exe" "%pathToRep%\Lessons Ravesli\Glava0\Glava0.sln" /Rebuild

echo Rebuild %pathToRep%\Lessons Ravesli\Glava1\Glava1.sln
"%VS%\devenv.exe" "%pathToRep%\Lessons Ravesli\Glava1\Glava1.sln" /Rebuild

echo Rebuild %pathToRep%\Lessons Ravesli\Glava2\Glava2.sln
"%VS%\devenv.exe" "%pathToRep%\Lessons Ravesli\Glava2\Glava2.sln" /Rebuild

echo Rebuild %pathToRep%\Lessons Ravesli\Glava3\Glava3.sln
"%VS%\devenv.exe" "%pathToRep%\Lessons Ravesli\Glava3\Glava3.sln" /Rebuild