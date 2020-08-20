@echo off
del ketqua.txt
for %%f in (0,1,2,3,4,5,6,7,8,9) do call c %1 %%f
ghidiem %1
echo DA CHAM XONG !!!