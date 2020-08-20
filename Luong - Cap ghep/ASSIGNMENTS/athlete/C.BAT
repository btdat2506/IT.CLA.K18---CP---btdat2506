@echo off
copy Athlete.In%2 Athlete.INP
%1
Check %2
del Athlete.OUT
