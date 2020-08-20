@echo off
copy ThueTho.In%2 ThueTho.INP
%1
Check %2
del ThueTho.OUT
