#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000]; 
    //printf("請輸入一串英文句子或單字: ");
    fgets(sentence, sizeof(sentence), stdin);

    int len = strlen(sentence);
    if (len >= 1 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '.') {
        sentence[len - 1] = '\0';
    }

    char *word = strtok(sentence, " ");
    char *lastWord = NULL;
    int wordCount = 0;

    while (word != NULL) {
        lastWord = word;
        word = strtok(NULL, " ");
        wordCount++;
    }

    if (wordCount > 1) {
        printf("last word: %s\n", lastWord);
        printf("%d letter(s)\n", (int)strlen(lastWord));
    } else if (wordCount == 1) {
        printf("just one word: %s\n", lastWord);
        printf("%d letter(s)\n", (int)strlen(lastWord));
    } else {
        printf("NoWord!!!!!\n");
    }

    return 0;
}
