#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "cmdFunctions.h"

void Command(char* cmd) {
	printf_s("Command is %s\n", cmd);
	system(cmd);
}

void WinRarExtract(char* command, char* key, char* password, char* path2File, char* fileName, char* path2Extraction) {
	char cmd[300];
	sprintf_s(cmd, 300, "cd C:\\Program Files\\WinRAR & WinRAR %s %s%s %s%s %s", command, key, password, path2File, fileName, path2Extraction);
	Command(cmd);
}