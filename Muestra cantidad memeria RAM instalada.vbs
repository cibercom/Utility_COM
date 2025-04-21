strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" _
    & strComputer & "\root\cimv2")
Set colSettings = objWMIService.ExecQuery _
    ("Select * from Win32_ComputerSystem")
For Each objComputer in colSettings 
    Wscript.Echo "Nombre del equipo: " & objComputer.Name
    Wscript.Echo "Memoria física total: " & _
        objComputer.TotalPhysicalMemory
Next