strComputer = "."
Set objWMIService = GetObject(_
    "winmgmts:\\" & strComputer & "\root\cimv2")
Set colItems = objWMIService.ExecQuery _
    ("Select * from Win32_PnPEntity " _
        & "WHERE ConfigManagerErrorCode <> 0")
For Each objItem in colItems
    Wscript.Echo "Nombre: " & objItem.Name
    Wscript.Echo "Descripción: " & objItem.Description
    Wscript.Echo "ID Identidad del dispositivo: " & objItem.DeviceID
    Wscript.Echo "Fabricante: " & objItem.Manufacturer
    Wscript.Echo "Class GUID: " & objItem.ClassGuid
    Wscript.Echo "PNP Device ID: " & objItem.PNPDeviceID
    Wscript.Echo "Servicio: " & objItem.Service
Next