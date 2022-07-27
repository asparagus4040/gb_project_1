@echo off
py KingHeader.py
make -j4
make clean
make cleanpng
pause
