echo ========= File du lieu %2
echo *** Input: %2 >> %1.txt
copy %2 XK.INP > nul
copy %2.DAP XK.DAP > nul
rem echo ========= Chay chuong trinh %1
tg TBEGIN
%1
if errorlevel 1 goto Err
tg TEND
tinhtg >> %1.txt
echo *** Ket qua test >> %1.txt
test >> %1.txt
if errorlevel 1 goto Err1
goto End
:Err1
echo Xem lai form output cua chuong trinh! >> %1.txt
goto End1
:Err
echo Runtime error! >> %1.txt
:End
rem del XK.OUT
:End1
rem del XK.INP
