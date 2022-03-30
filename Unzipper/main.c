#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "cmdFunctions.h"

#define MAX_LENGTH_OF_PASSWORD 9

#define PATH_TO_FOLDER "C:\\Users\\Oleg\\Desktop\\C_projects\\Unzipper\\Unzipper" //.exe file path
#define PATH_TO_FILE PATH_TO_FOLDER "\\"

#define FILE_NAME "secret.7z"
#define PASSWORD_FILE_NAME "Password.txt"
#define DICTIONARY_FILE_NAME "dictionary.txt"

#define WINRAR_COMMAND_EXTRACT_IN_FOLDER "x"

#define WINRAR_KEY_PASSWORD "-p"
#define WINRAR_KEY_DISABLE_ERROR_MESSAGES "-inul"
#define WINRAR_KEY_YES_TO_ALL_QUESTIONS "-y"

int main(void) {
	FILE* dictionary;
	errno_t err;
	err = fopen_s(&dictionary, PATH_TO_FILE DICTIONARY_FILE_NAME, "r");
	if (err != 0 || dictionary == 0) {
		printf_s("Can't open dictionary!\n");
		exit(1);
	}

	FILE* pass;
	
	char date[MAX_LENGTH_OF_PASSWORD];
	while (fgets(date, MAX_LENGTH_OF_PASSWORD, dictionary)) {
		if (date[0] == '\n') continue;
		WinRarExtract(WINRAR_COMMAND_EXTRACT_IN_FOLDER, WINRAR_KEY_YES_TO_ALL_QUESTIONS " " WINRAR_KEY_DISABLE_ERROR_MESSAGES " " WINRAR_KEY_PASSWORD, date, PATH_TO_FILE, FILE_NAME, PASSWORD_FILE_NAME, PATH_TO_FOLDER);
		
		err = fopen_s(&pass, PATH_TO_FILE PASSWORD_FILE_NAME, "r");
		if (err == 0) {
			char password[MAX_LENGTH_OF_PASSWORD];
			fgets(password, MAX_LENGTH_OF_PASSWORD, pass);
			fclose(pass);
			
			printf_s("Done! Check %s\nPassword is : %s\n", PATH_TO_FOLDER, password);
			
			system("pause");
			return 0;
		}
	}
	
	fclose(dictionary);

	printf_s("Used all dictionary words, extraction failed;(\n");
	
	system("pause");
	return 0;
}