set VCTargetsPath=c:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V120

msbuild ..\ArcaneLog.sln /v:n /p:Configuration=log_lib
msbuild ..\ArcaneLog.sln /v:n /p:Configuration=tests
