#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
    char sentence[1000]; // increased buffer size
    int number_of_letters = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);  // safer way to get full line

    clock_t start, end;
    start = clock();

    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] != ' ' && sentence[i] != '\n') {
            number_of_letters++;
        }
    }

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // convert to seconds
    printf("Execution Time: %f seconds\n", time_taken);
    printf("The number of letters in the given sentence are: %d\n", number_of_letters);

    return 0;
}
