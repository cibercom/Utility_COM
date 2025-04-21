strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" _
    & strComputer & "\root\cimv2")
Set colSettings = objWMIService.ExecQuery _
    ("Select * from Win32_OperatingSystem")
For Each objOperatingSystem in colSettings 
    Wscript.Echo "RAM disponible: " & _
        objOperatingSystem.FreePhysicalMemory
Next