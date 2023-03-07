@echo off
color 02
title X@Mud.Ren
::环境配置
set MUDLIB="%cd%"
set DRIVER="%cd%\bin\driver.exe"
set CONFIG="%cd%\config.cfg"
::运行游戏
:START
cd %MUDLIB%
%DRIVER% %CONFIG% "-f auto-test"
::goto START
pause