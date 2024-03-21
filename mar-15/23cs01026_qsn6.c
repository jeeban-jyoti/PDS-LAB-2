#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenateStrings(char *str1, char *str2, int len1, int len2) {

    char *concatenated = (char *)malloc((len1 + len2 + 1) * sizeof(char));

    for(int i = 0; i < len1; i++){
        concatenated[i] = str1[i];
    }
    for(int i = 0; i < len2; i++){
        concatenated[i+ len1] = str2[i];
    }

    concatenated[len1 + len2] = '\0';

    return concatenated;
}

int main() {
    int len1, len2;

    printf("Enter the length of first string: ");
    scanf("%d", &len1);
    char *str1 = (char *)malloc((len1 + 1) * sizeof(char));
    if (str1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the string: ");
    scanf("%s", str1);

    printf("Enter the length of second string: ");
    scanf("%d", &len2);
    char *str2 = (char *)malloc((len2 + 1) * sizeof(char));
    if (str2 == NULL) {
        printf("Memory allocation failed.\n");
        free(str1);
        return 1;
    }
    printf("Enter the string: ");
    scanf("%s", str2);

    char *result = concatenateStrings(str1, str2, len1, len2);

    printf("%s\n", result);

    free(str1);
    free(str2);
    free(result);

    return 0;
}
