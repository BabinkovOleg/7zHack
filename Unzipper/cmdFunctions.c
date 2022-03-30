#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "cmdFunctions.h"

#define PATH_TO_PASS "C:\\Users\\Oleg\\Desktop\\C_projects\\Unzipper\\Unzipper\\"
#define PASS_FILE_NAME "Password.txt"
#define MAX_LENGTH_OF_COMMAND 350

void Command(char* cmd) {
	printf_s("Command is %s\n", cmd);
	system(cmd);
}

void WinRarExtract(char* command, char* key, char* password, char* path2File, char* fileName, char* passFilename, char* path2Extraction) {
	char cmd[MAX_LENGTH_OF_COMMAND];
	sprintf_s(cmd, MAX_LENGTH_OF_COMMAND, "cd C:\\Program Files\\WinRAR & WinRAR %s %s%s %s%s %s & if %%ErrorLevel%% == 0 (echo %s > %s%s)", command, key, password, path2File, fileName, path2Extraction, password, path2File, passFilename);
	Command(cmd);
}