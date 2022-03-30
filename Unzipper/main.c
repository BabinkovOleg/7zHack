#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "cmdFunctions.h"

#define DICTIONARY_FILE_NAME "dictionary.txt"
#define GO_TO_FOLDER "cd C:\\Program Files\\WinRAR"
#define PATH_TO_FILE "C:\\Users\\Oleg\\Desktop\\C_projects\\Unzipper\\Unzipper\\"
#define PATH_TO_EXTRACTING "C:\\Users\\Oleg\\Desktop\\C_projects\\Unzipper\\Unzipper"
#define WINRAR_COMMAND_EXTRACT_IN_FOLDER "x"
#define WINRAR_KEY_PASSWORD "-p"
#define WINRAR_KEY_DISABLE_ERROR_MESSAGES "-inul"

int main(void) {
	FILE* dictionary;
	errno_t err;
	err = fopen_s(&dictionary, DICTIONARY_FILE_NAME, "r");
	if (err != 0 || dictionary == 0) {
		printf_s("Can't open dictionary!\n");
		exit(1);
	}
	
	char date[9];
	while (fgets(date, 9, dictionary)) {
		if (date[0] == '\n') continue;
		WinRarExtract(WINRAR_COMMAND_EXTRACT_IN_FOLDER, WINRAR_KEY_DISABLE_ERROR_MESSAGES " " WINRAR_KEY_PASSWORD, date, PATH_TO_FILE, "secret.7z", PATH_TO_EXTRACTING);
	}

	fclose(dictionary);

	printf_s("Used all dictionary words, check " PATH_TO_EXTRACTING "\n");
	system("pause");
	return 0;
}