#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define CODE_LENGTH 4
#define MAX_ATTEMPTS 10

int is_valid_input(char *input) {
    if (strlen(input) != CODE_LENGTH)
        return 0;
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (input[i] < '0' || input[i] > '8')
            return 0;
    }
    return 1;
}

void generate_code(char *code) {
    int used[9] = {0};
    int i = 0;
    while (i < CODE_LENGTH) {
        int r = rand() % 9;
        if (!used[r]) {
            code[i++] = r + '0';
            used[r] = 1;
        }
    }
    code[CODE_LENGTH] = '\0';
}

int compare_codes(char *guess, char *code, int *well, int *misplaced) {
    *well = 0;
    *misplaced = 0;
    int code_count[10] = {0};
    int guess_count[10] = {0};

    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] == code[i])
            (*well)++;
        else {
            code_count[code[i] - '0']++;
            guess_count[guess[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {
        *misplaced += (code_count[i] < guess_count[i]) ? code_count[i] : guess_count[i];
    }

    return (*well == CODE_LENGTH);
}

int read_input(char *buffer, int size) {
    int i = 0;
    char c;
    while (i < size - 1) {
        ssize_t ret = read(0, &c, 1);
        if (ret <= 0)
            return 0;  // EOF or error
        if (c == '\n')
            break;
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return 1;
}

int main(int argc, char **argv) {
    char code[CODE_LENGTH + 1];
    char guess[CODE_LENGTH + 1];
    int attempts = MAX_ATTEMPTS;
    int well, misplaced;
    int round = 0;

    srand(time(NULL));

    if (argc == 3 && strcmp(argv[1], "-c") == 0 && strlen(argv[2]) == CODE_LENGTH) {
        strncpy(code, argv[2], CODE_LENGTH);
        code[CODE_LENGTH] = '\0';
    } else {
        generate_code(code);
    }

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    while (round < attempts) {
        printf("---\nRound %d\n>", round);
        fflush(stdout);
        if (!read_input(guess, sizeof(guess))) {
            write(1, "\n", 1);
            break;
        }

        if (!is_valid_input(guess)) {
            printf("Wrong input!\n");
            continue;
        }

        if (compare_codes(guess, code, &well, &misplaced)) {
            printf("Congratz! You did it!\n");
            return 0;
        }

        printf("Well placed pieces: %d\n", well);
        printf("Misplaced pieces: %d\n", misplaced);
        round++;
    }

    return 0;
}
