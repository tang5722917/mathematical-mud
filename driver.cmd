@echo off
color 02
title MYSTICISM
::��������
set MUDLIB="%cd%"
set DRIVER="%cd%\bin\driver.exe"
set CONFIG="%cd%\config.cfg"
::������Ϸ
:START
cd %MUDLIB%
%DRIVER% %CONFIG% %*
::goto START
pause