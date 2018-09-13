xcopy /s /y IO_list_automation\learning 	_temp\learning
xcopy /s /y IO_list_automation\libxl.dll	_temp
xcopy /s /y IO_list_automation\_cfg.txt		_temp


xcopy /s /y _temp Release
xcopy /s /y _temp Debug

