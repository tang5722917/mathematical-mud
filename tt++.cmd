@echo off
color 02
title MYSTICISM tt client
::环境配置
::PATH为tt++在windows中的安装目录
::默认为 C:\Users\用户名\AppData\Roaming\WinTin++\bin\tt++.exe
set PATH="*\tt++.exe"
::CONFIG为tt++启动配置脚本目录
::即mysticism-mud中setup.tt所在目录
set CONFIG="\setup.tt"
::运行游戏
:START
%PATH% %CONFIG% %*
::goto START
pause