@echo off
REM �����.bat����QtMoc.lua�ļ�����

REM ���õ�ǰ·��
set base_dir=%~dp0 
%base_dir:~0,2% 
cd %base_dir% 

REM ִ��
lua MocHelper.lua %1

REM ��ͣ
pause >> nul