:start
@echo off
cls
title Kalculator
color 71
echo Vvedite uravnenie:
set /p Exp=
set /a Result=%Exp%
cls
echo Vuchisleno
echo Vashe uravnenie: %Exp%
echo Resultat: %Result%
echo.
echo Nazhmite lubuu klavishu . . .
pause > nul
goto start