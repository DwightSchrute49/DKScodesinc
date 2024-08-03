
#include <stdio.h>
#include <stdlib.h>

void reverse(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
	int i;
    for ( i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}

void concat(char *s1, char *s2) {
    int len1 = 0;
    while (s1[len1] != '\0') {
        len1++;
    }

    int len2 = 0;
    while (s2[len2] != '\0') {
        s1[len1 + len2] = s2[len2];
        len2++;
    }
    s1[len1 + len2] = '\0';
}

int compare(char *s1, char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

char *substring(char *s, int start, int n) {
    char *sub = (char *)malloc((n + 1) * sizeof(char));
    int i;
    for (i = 0; i < n && s[start + i] != '\0'; i++) {
        sub[i] = s[start + i];
    }
    sub[i] = '\0';
    return sub;
}

int isPalindrome(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (s[start] != s[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

int main() {
    char *s1, *s2;
    int choice;

    s1 = (char *)malloc(100 * sizeof(char));
    s2 = (char *)malloc(100 * sizeof(char));

    printf("Enter string s1: ");
    scanf("%s", s1);
    printf("Enter string s2: ");
    scanf("%s", s2);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Reverse s1\n");
        printf("2. Reverse s2\n");
        printf("3. Concatenate s2 at the end of s1\n");
        printf("4. Concatenate s1 at the end of s2\n");
        printf("5. Compare s1 and s2\n");
        printf("6. Check palindrome\n");
        printf("7. Get substring\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reverse(s1);
                printf("Reversed s1: %s\n", s1);
                break;
            case 2:
                reverse(s2);
                printf("Reversed s2: %s\n", s2);
                break;
            case 3:
                concat(s1, s2);
                printf("Concatenated s2 at the end of s1: %s\n", s1);
                break;
            case 4:
                concat(s2, s1);
                printf("Concatenated s1 at the end of s2: %s\n", s2);
                break;
            case 5:
                printf("Comparison result: %d\n", compare(s1, s2));
                break;
            case 6:
                if (isPalindrome(s1))
                    printf("s1 is a palindrome\n");
                else
                    printf("s1 is not a palindrome\n");

                if (isPalindrome(s2))
                    printf("s2 is a palindrome\n");
                else
                    printf("s2 is not a palindrome\n");
                break;
            case 7:
                printf("Enter start index and length for substring: ");
                int start, len;
                scanf("%d %d", &start, &len);
                if (start < 0 || start >= str.len(s1) || len < 0) {
                    printf("Invalid start index or length\n");
                } else {
                    char *sub = substring(s1, start, len);
                    printf("Substring: %s\n", sub);
                    free(sub);
                }
                break;
            case 8:
                free(s1);
                free(s2);
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}

