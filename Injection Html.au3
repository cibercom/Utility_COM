; visitanos! http://pilaresdelcodigo.wordpress.com/
#NoTrayIcon
#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#include <IE.au3>

$Form1 = GUICreate("Injector! - Ejemplo de Inyeccion.", 308, 327, -1, -1)
GUISetBkColor(0x99B4D1)
$Group1 = GUICtrlCreateGroup("", 8, 8, 289, 313)
$Label1 = GUICtrlCreateLabel(".:[Injector!]:.", 32, 32, 247, 42)
GUICtrlSetFont(-1, 24, 800, 0, "Verdana")
GUICtrlSetColor(-1, 0xFFFFFF)
$Edit1 = GUICtrlCreateEdit("", 24, 136, 257, 137)
GUICtrlSetData(-1, "<!-- Tu Codigo HTML Aqui -->")
$Button1 = GUICtrlCreateButton("Realizar Prueba", 72, 280, 171, 25)
GUICtrlSetFont(-1, 12, 400, 0, "Verdana")
$Input1 = GUICtrlCreateInput("http://pilaresdelcodigo.wordpress.com/" , 24, 104, 257, 21)
$Label2 = GUICtrlCreateLabel("Sitio:", 24, 88, 33, 17)
GUICtrlSetFont(-1, 8, 800, 0, "MS Sans Serif")
GUICtrlSetColor(-1, 0xFFFFFF)
GUICtrlCreateGroup("", -99, -99, 1, 1)
GUISetState(@SW_SHOW)


While 1
	$nMsg = GUIGetMsg()
	Switch $nMsg
		Case $GUI_EVENT_CLOSE
			Exit

		Case $Button1
			$pagina = GUICtrlRead($Input1)
			$codigo = GUICtrlRead($Edit1)
			Local $oIE = _IECreate($pagina)
			Local $oBody = _IETagNameGetCollection($oIE, "body", 0)
			_IEDocInsertHTML($oBody, "" & $codigo, "afterbegin")

	EndSwitch
WEnd



#include <File.au3>

$PATH = FileOpenDialog("PATH",@ScriptDir,"All (*.*)")
If Not @error Then
    Dim $szDrive, $szDir, $szFName, $szExt
    $PATH = _PathSplit($PATH,$szDrive,$szDir,$szFName,$szExt)
    MsgBox(0,"",$PATH[4])
EndIf