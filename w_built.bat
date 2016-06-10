set VCTargetsPath=c:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V120

msbuild ..\ChaosLog.sln /v:n /p:Configuration=chlog_lib
msbuild ..\ChaosLog.sln /v:n /p:Configuration=tests
