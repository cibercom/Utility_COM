strComputer = "."
On Error Resume Next
Set objWMIService = GetObject("winmgmts:\\" & strComputer & "\root\CIMV2") 
Set colItems = objWMIService.ExecQuery("SELECT * FROM Win32_ComputerSystem") 
For Each objItem in colItems 
 Msgbox "Numero de procesadores: " & objItem.NumberOfProcessors
Next
Set colItems = objWMIService.ExecQuery("SELECT * FROM Win32_Processor") 
For Each objItem in colItems 
 MsgBox "Tipo de procesador: " & objItem.Name
 MsgBox "Numero de procesadores logicos: " & objItem.NumberOfLogicalProcessors
 MsgBox "Cantidad de nucleos: " & objItem.NumberOfCores
Next