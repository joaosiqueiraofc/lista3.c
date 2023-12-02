#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehPlacaValida(char *placa) {
    int tamanho = strlen(placa);
    if (tamanho != 8 && tamanho != 7) {
        return 0;
    }

    if (tamanho == 8) {
        for (int i = 0; i < 3; ++i) {
            if (!isalpha(placa[i])) {
                return 0;
            }
        }
        if (placa[3] != '-' || !isdigit(placa[4]) || !isdigit(placa[5]) || !isdigit(placa[6]) || !isdigit(placa[7])) {
            return 0;
        }
    }

    if (tamanho == 7) {
        for (int i = 0; i < 3; ++i) {
            if (!isalpha(placa[i])) {
                return 0;
            }
        }
        if (!isalpha(placa[3]) || !isdigit(placa[4]) || !isdigit(placa[5]) || !isdigit(placa[6])) {
            return 0;
        }
    }

    return 1;
}

int ehDiaValido(char *dia) {
    char *diasValidos[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    for (int i = 0; i < 7; ++i) {
        if (strcmp(dia, diasValidos[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char placa[10], dia[20];

    scanf("%s", placa);
    scanf("%s", dia);

    if (!ehPlacaValida(placa)) {
        printf("Placa invalida\n");
        return 0;
    }

    if (!ehDiaValido(dia)) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    int ultimoDigito = placa[strlen(placa) - 1] - '0';
    int indiceDia;

    if (strcmp(dia, "SEGUNDA-FEIRA") == 0) {
        indiceDia = 1;
    } else if (strcmp(dia, "TERCA-FEIRA") == 0) {
        indiceDia = 2;
    } else if (strcmp(dia, "QUARTA-FEIRA") == 0) {
        indiceDia = 3;
    } else if (strcmp(dia, "QUINTA-FEIRA") == 0) {
        indiceDia = 4;
    } else if (strcmp(dia, "SEXTA-FEIRA") == 0) {
        indiceDia = 5;
    } else if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0) {
        printf("%s pode circular no(a) %s\n", placa, dia);
        return 0;
    } else {
        printf("Dia da semana invalido\n");
        return 0;
    }

    if ((ultimoDigito == indiceDia || ultimoDigito == (indiceDia + 1) % 10) || (ultimoDigito == 9 && indiceDia == 0)) {
        printf("%s pode circular no(a) %s\n", placa, dia);
    } else {
        printf("%s nao pode circular no(a) %s\n", placa, dia);
    }

    return 0;
}
