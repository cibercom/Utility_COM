<!-- :: Batch section
 @echo off
 setlocal
 goto begin
 Example of "HTA Input Forms" in Batch files
 Antonio Perez Ayala, Aug/08/2015
 There are 4 "HTA-Input Form" routines implemented in this program:
 Button, RadioButton, CheckBox and Password; all of them use the same format:
    call :HTA-Input form result= [/V]  col row width height  option1 option2 ...
 "form" is one of the 4 routine names listed above.
 If the /V switch is included, the options will be listed vertically.
 The next 4 values specify the position and size of the input form in the screen
 in text (column and row) coordinates. This feature depends on get the position
 and font size of the command-line window in pixels, but I am still working on a
 method to get such values without using a third party .exe program. A temporary
 solution to this problem is to create a copy of the command-line icon, right-
 click on it, select "Properties" > "Layout", unset "Let the system locate the
 window" and set a fixed screen position, like 190,10; also, get the size of the
 font from "Font" tab. Then, hardcode these four values into this program (look
 for the "PATCH" related comments) and use the modified icon to run it.
 Each "option" is a word or a series of words enclosed in quotes.
 When the form is RadioButton, the pre-checked option may be indicated preceding
 it by /C: switch; in this case the quotes are mandatory. For example:
    call :HTA-Input RadioButton result= col row width height
                            "First opt" /C:"Second opt checked" "Third opt"
 If the form is Password, the first option may be a number that specify the
 maximum number of characters to read.
 When the subroutine ends, "result" variable will have the input value from the
 form, or be undefined if the input form was cancelled.
 Reference:
 http://www.quackit.com/html/tags/html_input_tag.cfm
 :begin
 cls
 echo/
 echo ========  EXAMPLE  OF  HTA  INPUT  FORMS  ========
 echo/
 echo/
 echo/
 set /P "=HTA-Input Button in vertical menu: " < NUL
 call :HTA-Input Button result= /V 36 4 15 8 " First option      " "Second option" " Third option    "
 echo Option selected = %result%
 echo/
 echo/
 echo/
 set /P "=HTA-Input Button: " < NUL
 call :HTA-Input Button result= 19 8 36 5 "First option" "Second option" "Third option"
 echo Option selected = %result%
 echo/
 echo/
 echo/
 set /P "=HTA-Input RadioButton in vertical menu: " < NUL
 call :HTA-Input RadioButton result= /V 41 12 18 10 "First option" /C:"Second option" "Third option"
 echo Option selected = %result%
 echo/
 echo/
 echo/
 set /P "=HTA-Input RadioButton: " < NUL
 call :HTA-Input RadioButton result= 24 16 46 7 "First option" "Second option" /C:"Third option"
 echo Option selected = %result%
 echo/
 echo/
 echo/
 set /P "=HTA-Input CheckBox in vertical menu: " < NUL
 call :HTA-Input CheckBox result= /V 38 20 18 10 "First option" "Second option" "Third option"
 echo Option(s) selected = "%result%"
 echo/
 echo/
 echo/
 set /P "=HTA-Input CheckBox: " < NUL
 call :HTA-Input CheckBox result= 21 24 46 7 "First option" "Second option" "Third option"
 echo Option(s) selected = "%result%"
 echo/
 echo/
 echo/
 set /P "=HTA-Input Password: " < NUL
 call :HTA-Input Password result= 21 28 17 8 8
 echo Password read = "%result%"
 goto :EOF
 ==================================================================================
 This is :HTA-Input Form subroutine; include from this point until EOF in your code
 Don't forget to also copy *the first line* in this file!
 Developed by Antonio Perez Ayala aka Aacini
 http://www.dostips.com/forum/viewtopic.php?f=3&t=6581&p=42362#p42362
 :HTA-Input form result= [/V]  col row width height  option1 option2 ...
 setlocal EnableDelayedExpansion
 set "form=%1" & shift
 set "res=%1" & shift
 if /I "%~1" equ "/V" (set "ver=<br>" & shift) else set "ver="
 set "pos=%1 %2 %3 %4"
 for /L %%i in (1,1,4) do shift
 echo %form% > HTML 
 set i=0
 goto %form%
 :Button
    set /A i+=1
    set /P "=<input type="button" onclick="closeHTA(%i%)" value="%~1">%ver% " >> HTML < NUL
    shift
 if "%~1" neq "" goto Button
 call :GetHTAreply
 endlocal & set "%res%=%HTAreply%"
 exit /B
 :RadioButton
    set "button=%~1"
    if not defined button goto endButton
    set /A i+=1
    set "checked="
    if /I "!button:~0,3!" equ "/C:" (
       set "button=!button:~4,-1!"
       set "checked=checked"
       set "pos=%pos% %i%"
    )
    set /P "=<label><input type="radio" name="RB" onclick="rb=%i%" value="%i%" %checked%>%button%</label>%ver% " >> HTML < NUL
    shift
 goto RadioButton
 :endButton
 set /P "=<br><br><button onclick="closeHTA(rb);">Submit</button>" >> HTML < NUL
 call :GetHTAreply
 endlocal & set "%res%=%HTAreply%"
 exit /B
 :CheckBox
    set /A i+=1
    set /P "=<input type="checkbox" name="CB" onclick="checkBox('%i%')" value="%i%">%~1&nbsp;%ver%" >> HTML < NUL
    shift
 if "%~1" neq "" goto CheckBox
 set /P "=<br><br><button onclick="closeHTA(cb);">Submit</button>" >> HTML < NUL
 call :GetHTAreply
 endlocal & set "%res%=%HTAreply%"
 exit /B
 :Password
 if "%~1" neq "" (set maxlength=maxlength="%~1") else set "maxlength="
 set /P "=<input type="password" id="PW" %maxlength%>" >> HTML < NUL
 set /P "=<br><br><button onclick="closeHTA(document.getElementById('PW').value)">Submit</button>" >> HTML < NUL
 call :GetHTAreply
 endlocal & set "%res%=%HTAreply%"
 exit /B
 :GetHTAreply
 set "HTAreply="
 for /F "delims=" %%a in ('(echo %pos% ^& type HTML ^) ^| mshta.exe "%~F0"') do set "HTAreply=%%a"
 del HTML
 exit /B
 -->
 <HTML>
 <HEAD>
 <HTA:APPLICATION INNERBORDER="no" SYSMENU="no" SCROLL="no" >
    <style type="text/css">
    body {
       color: white;
       background: black;
       font-family: "Lucida Console", monospace;
    }
    </style>
 </HEAD>
 <BODY>
 </BODY>
 <SCRIPT language="JavaScript">
 var fso     = new ActiveXObject("Scripting.FileSystemObject"),
     stdin   = fso.GetStandardStream(0),
     pos     = stdin.ReadLine().split(" "), rb = pos[4], cb = " ",
     cmdExe  = window.parent,
     // PATCH: Uncomment next lines when "window.parent" property correctly works in your browser
     // winLeft = cmdExe.screenLeft ? cmdExe.screenLeft : cmdExe.screenX,
     // winTop  = cmdExe.screenTop  ? cmdExe.screenTop  : cmdExe.screenY,
     // else, place here the fixed screen position you set for your cmd.exe window
     winLeft = 190, winTop = 10,
     // PATCH: Uncomment next lines *in IE only* when "window.parent" correctly works ("currentStyle" property is IE exclusive)
     // fontY   = parseInt(cmdExe.body.currentStyle.fontSize),
     // fontX   = Math.round(fontY*6/10);
     // else, place here the size of font used in cmd.exe window
     fontX = 11, fontY = 18;
 window.moveTo(winLeft+fontX*pos[0],winTop+fontY*pos[1]);
 window.resizeTo(fontX*pos[2],fontY*pos[3]);
 document.title = "HTA Input "+stdin.ReadLine();
 document.body.innerHTML = stdin.ReadLine();
 function checkBox(opt){
    if ( cb.indexOf(" "+opt+" ") >= 0 ) {
       cb = cb.replace(" "+opt+" "," ");
    } else { 
       cb += opt+" ";
    }
 }
 function closeHTA(reply){
    fso.GetStandardStream(1).WriteLine(reply);
    window.close();
 }
 </SCRIPT>
 </HTML>