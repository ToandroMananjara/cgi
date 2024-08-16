#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *file;
	char adminUsername[50];
	char adminPassword[50];
	char *query_string = getenv("QUERY_STRING");
	char username[20];
	char password[20];

	// Ouvrir le fichier en mode lecture
	file = fopen("./data.txt", "r");
	if (file == NULL)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return 1;
	}
	// Lire deux chaînes de caractères séparées par un espace depuis le fichier
	fscanf(file, "%s %s", adminUsername, adminPassword);
	fclose(file);

	// Extraire les valeurs des paramètres "username" et "password"
	sscanf(query_string, "username=%[^&]&password=%s", username, password);
	int i = 0;
	char *equal = "=";
	while (strcmp(query_string, equal) == 0)
	{
		printf("none");
	}

	printf("Content-Type: text/html\n\n");
	printf("<!DOCTYPE html>\n");
	printf("<html lang=\"en\">\n");
	printf("<head>\n");
	printf("<meta charset=\"UTF-8\">\n");
	printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
	printf("<link rel=\"stylesheet\" href=\"./css/style.css\">\n");
	printf("<title>Login page</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	
	if (strcmp(adminUsername, username) == 0 && strcmp(adminPassword, password) == 0)
	{
		printf("Bienvenue vous etes connecté");
	}
	else
	{

		printf("<div id=\"root\">\n");
		printf("<div class=\"container\">\n");
		printf("<div class=\"form-container\">\n");
		printf("<div class=\"form\">\n");
		printf("<h1>Login</h1>\n");
		printf("<form action=\"index.cgi\" method=\"get\">\n");
		printf("<label for=\"username\">Username:</label><br>\n");
		printf("<input type=\"text\" name=\"username\" id=\"username\" class=\"input\" placeholder=\"Entrer username\" value=\"%s\" required><br>\n", username);
		printf("<label for=\"password\">Password:</label><br>\n");
		printf("<div class=\"password-container\">\n");
		printf("<input type=\"password\" name=\"password\" id=\"password\" class=\"input\" placeholder=\"Entrer password\" value=\"%s\" required><br>\n", password);
		printf("<div class=\"icon\">\n");
		printf("<i class=\"fa fa-eye\" aria-hidden=\"true\"></i>\n");
		printf("</div>\n");
		printf("</div>\n");
		printf("<input type=\"submit\" id=\"login\" value=\"log in\">\n");
		printf("</form>\n");
		printf("</div>\n");
		printf("</div>\n");
		printf("</div>\n");
		printf("</div>\n");

	}

	printf("</body>\n");
	printf("</html>\n");
	return 0;
}
