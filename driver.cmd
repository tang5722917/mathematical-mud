@echo off
color 02
title MYSTICISM
::环境配置
set MUDLIB="%cd%"
set DRIVER="%cd%\bin\driver.exe"
set CONFIG="%cd%\config.cfg"
::删除旧log文件
cd %MUDLIB%\log
del error_handler
del log_error
del log
::运行游戏
:START
cd %MUDLIB%
%DRIVER% %CONFIG% %*
::goto START
pause
