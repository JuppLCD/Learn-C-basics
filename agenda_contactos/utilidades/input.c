# include "../utilidades.h"

int obtener_opcion_valida(int primera_opcion, int ultima_opcion) {
    int op = -1;

    do {
        printf("Opcion (%i-%i): ", primera_opcion, ultima_opcion); scanf(" %i", &op);
        limpiar_buffer();

        if (!(primera_opcion <= op && op <= ultima_opcion)) {
            puts("\nOpcion no valida!!\n");
        }
    } while (!(primera_opcion <= op && op <= ultima_opcion));

    return op;
}

char *obtener_texto(char descripcion[]) {

    char buffer[255];
    memset(buffer, 0, sizeof(buffer));

    printf("%s", descripcion);

    fgets(buffer, sizeof(buffer), stdin);

    if (strlen(buffer) > 0 && buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }
    else {
        limpiar_buffer();
    }

    unsigned int len_input = strlen(buffer) + 1;

    char *texto = (char*)malloc(sizeof(char) * len_input);

    strcpy(texto, buffer);

    return texto;
}

void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void pausar_terminal(void) {
    puts("Presiona ENTER para continuar.....");
    getchar();
}

// Fn pensada para comentar el clear y ver advertencias en la terminal.
void limpiar_terminal(void) {
    system("clear");
}