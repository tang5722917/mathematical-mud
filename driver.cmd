@echo off
color 02
title MYSTICISM
::��������
set MUDLIB="%cd%"
set DRIVER="%cd%\bin\driver.exe"
set CONFIG="%cd%\config.cfg"
::ɾ����log�ļ�
cd %MUDLIB%\log
del error_handler
del log_error
del log
::������Ϸ
:START
cd %MUDLIB%
%DRIVER% %CONFIG% %*
::goto START
pause
