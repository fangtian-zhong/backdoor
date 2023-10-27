#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char sneaky[] = "SOSNEAKY";

int authenticate(char* username, char* password)
{
	printf("hello authenticate");
	char stored_pw[9];
	stored_pw[8] = 0;
	FILE* pwfile;

	// evil back d00r
	if (strcmp(password, sneaky) == 0) return 1;

	pwfile = fopen(username, "r");
	
	if(pwfile){
	     fgets(stored_pw, 8, pwfile);
		 if (strcmp(password, stored_pw) == 0) return 1;
	}
	return 0;

}

int accepted()
{
	printf("Welcome to the admin console, trusted user!\n");
	return 0;
}

int rejected()
{
	printf("Go away!");
	exit(1);
}

int main(int argc, char** argv)
{
	char username[9];
	char password[9];
	int authed;

	username[8] = 0;
	password[8] = 0;

	printf("Username: \n");
	scanf("%8s", username);
	printf("%s\n", username);
	printf("Password: \n");
	scanf("%8s", password);
	printf("%s\n", password);

	authed = authenticate(username, password);
	if (authed) accepted();
	else rejected();
}