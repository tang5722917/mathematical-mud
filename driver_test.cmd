@echo off
color 02
title X@Mud.Ren
::��������
set MUDLIB="%cd%"
set DRIVER="%cd%\bin\driver.exe"
set CONFIG="%cd%\config.cfg"
::������Ϸ
:START
cd %MUDLIB%
%DRIVER% %CONFIG% "-f auto-test"
::goto START
pause