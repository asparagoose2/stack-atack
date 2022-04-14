void print_secret() {
    printf("Secret revealed!\n");
}

void scan() {
    printf("%x",__builtin_return_address(1));
    printf('\n');
    char buffer[2] = {0};
    gets(buffer);
}

void main() {
    scan();
    printf("Bye!\n");
    return;
}