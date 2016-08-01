set VCTargetsPath=c:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V120

msbuild ..\ArcaneLog.sln /v:n /p:Configuration=arcanelog
msbuild ..\ArcaneLog.sln /v:n /p:Configuration=arcanelog_shared
msbuild ..\ArcaneLog.sln /v:n /p:Configuration=tests
