@echo off
color 02
title MYSTICISM tt client
::��������
::PATHΪtt++��windows�еİ�װĿ¼
::Ĭ��Ϊ C:\Users\�û���\AppData\Roaming\WinTin++\bin\tt++.exe
set PATH="*\tt++.exe"
::CONFIGΪtt++�������ýű�Ŀ¼
::��mysticism-mud��setup.tt����Ŀ¼
set CONFIG="\setup.tt"
::������Ϸ
:START
%PATH% %CONFIG% %*
::goto START
pause