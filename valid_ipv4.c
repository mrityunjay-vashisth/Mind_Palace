#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


bool validate_ipv4_addr(char *ip) {
	char *tmp = strdup(ip);
	for (int i = 0; i < 3; i++) {
		if (isalpha(tmp[i]))
			return false;
	}
	if (strlen(ip) > 3)
		return false;
	int digit = atoi(ip);
	if (digit >= 0 && digit < 256)
		return true;
	return false;
} 


int main(int argc, char const *argv[])
{
	char a[] = "He";
	char b[] = "192.162.3.4";

	char *token1;
	char *token2;

	token2 = strtok(b, ".");
	bool valid = true;
	while (token2!= NULL) {
		valid &= validate_ipv4_addr(token2);
		token2 = strtok(NULL, ".");
	}
	if(valid)
		printf("Valid\n");
	else
		printf("Invalid\n");
	return 0;
}