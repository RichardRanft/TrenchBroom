@echo off

call Release-Package.bat NoDocs

if errorlevel 1 goto errorDone

move "..\Release\TrenchBroom_Win32_*.zip" "%DROPBOX%\TrenchBroom\"

goto done

:errorDone

:done

