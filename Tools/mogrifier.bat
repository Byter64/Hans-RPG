@echo off
echo MOGRIFY CURRENT DIRECTORY:
@echo on
magick mogrify -format bmp *.png
@echo off
echo:
echo MOGRIFY SUBDIRECTORIES:
@echo on
FOR /D /R %%A IN (*) DO magick mogrify -format bmp "%%A\*.png"
@echo off
echo:
echo SCRIPT COMPLETE
pause