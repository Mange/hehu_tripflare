@echo off
if not defined build_dir goto :missing_variables

mkdir "%build_dir%\hehu_tripflare\scripts"

pushd %tools_dir%\binmake
@echo on
binmake.exe "%source_dir%\config.cpp" "%build_dir%\hehu_tripflare\config.bin"
@echo off
popd

@echo on
copy "%source_dir%\scripts\" "%build_dir%\hehu_tripflare\scripts"

"%tools_dir%\filebank\filebank.exe" -property prefix=hehu_tripflare "%build_dir%\hehu_tripflare"

@echo off
mkdir "%target_dir%\@hehu_tripflare\addons"

@echo on
copy "%build_dir%\hehu_tripflare.pbo" "%target_dir%\@hehu_tripflare\addons"
copy "%source_dir%\mod.cpp" "%target_dir%\@hehu_tripflare"
copy "%source_dir%\README.md" "%target_dir%\@hehu_tripflare\readme.txt"

pause
exit 0

:missing_variables
echo You need to set up your make.bat file and run that one instead!
pause
exit 1