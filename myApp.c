#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define bool unsigned char
#define true 1
#define false 0

int compare(char* a, char* b)
{
    while(*a) {
        if(*a == '\n' || *b == '\n') {
            a++;
            b++;
            continue;
        }
        usleep(10000);
        if((*a) != (*b)) {
            return 0;
        }
        a++;
        b++;
    }
    return 1;
}

void a() {
            printf("Enter password: ");
}
void test1() {
    bool flag = false;
    bool flag2 = false;
    bool flag3 = false;
    // char buffer[6] = {0};
    FILE *fp = 0;
    char *line = 0;
    size_t len = 0;
    ssize_t read = 0;
    a();
}

int password_check(char* password)
{
    // read password from file
    bool flag = 0;
    char buffer[6] = {0};
    printf("Enter password: ");
    printf("Hint: password is-%s\n", password);
    gets(buffer);
    if (compare(password,buffer))
    {
        flag = 1;
    }
    return flag;

}



char* get_password(user_id)
{
    FILE *fp = fopen("./passwords.txt", "r" );
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char* password = 0;
    password = (char*)malloc(sizeof(char)*7);
    while(feof(fp) == 0)
    {
        // printf("Retrieved line of length %zu:\n", read);
        // printf("%s\n", line);
        // char *token = strtok(line, " ");
        int id;
        fscanf(fp, "%d", &id);
        fscanf(fp, "%s", password);
        if (id == user_id)
        {
            return password;
        }
    }
    return NULL;
}


int login() {
    int user_id;

    printf("Enter user id: ");
    scanf("%d", &user_id);
    fflush(stdin);
    getchar();
    char* password = get_password(user_id);
    if(!password) {
        printf("user not found\n");
        return 0;
    }
    printf("got password: %s\n", password);
    // gets(buffer);
    if (password_check(password))
    {
        printf("Login successful!\n");
        return 1;
    }
    else
    {
        printf("Login failed!\n");
        return 0;
    }
}

void print_all_pass() {
    FILE *fp = fopen("./passwords.txt", "r" );
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    // print line by line 
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    printf("List of all passwords:\n");
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }
    fclose(fp);
    printf("\n");
    printf("***End of list***\n");
}

void run() {
    char buffer[2] = {0};
    while(1) {
        printf("\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        int choice;
        gets(buffer);
        choice = atoi(buffer);
        // scanf("%d", &choice);
        fflush(stdin);
        // getchar();
        switch(choice) {
            case 1:
                printf("Login\n");
                break;
            case 2:
                return;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}

int main(int argc, char *argv[])
{
    int user_id = 0;
    printf("Enter user id: ");
    scanf("%d", &user_id);
    fflush(stdin);
    getchar();
    char* password = get_password(user_id);
    if(!password) {
        printf("user not found\n");
        return 0;
    }
    
    int is_logged_in = 0;
    is_logged_in = password_check(password);
    if (is_logged_in) {
        printf("Logged in!\n");
        run();
    }
    else {
        printf("Not logged in!\n");
    }
    
    return 0;
}