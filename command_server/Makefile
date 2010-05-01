
options = /nologo /warn:4 /debug:+ /debug:full /optimize- /codepage:utf8 /define:DEBUG  /t:exe

srcs = command_server/Main.cs command_server/AssemblyInfo.cs

refs = "/r:System.dll" "/r:lib/NDesk.DBus.dll"

default: command_server

command_server: command_server.exe

command_server.exe:
	gmcs /noconfig /out:$@ $(refs) $(options) $(srcs)
