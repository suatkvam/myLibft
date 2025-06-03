/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "libft.h"  // Include your libft header file

// ANSI color codes for better output
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Test counter
int tests_passed = 0;
int tests_failed = 0;

// Helper macro for testing
#define TEST(condition, test_name) \
    do { \
        if (condition) { \
            printf(GREEN "✓ " RESET "%s\n", test_name); \
            tests_passed++; \
        } else { \
            printf(RED "✗ " RESET "%s\n", test_name); \
            tests_failed++; \
        } \
    } while(0)

// Test isalpha function
void test_ft_isalpha(void)
{
    printf(BLUE "\n=== Testing ft_isalpha ===\n" RESET);
    TEST(ft_isalpha('a') && ft_isalpha('Z'), "ft_isalpha: letters");
    TEST(!ft_isalpha('1') && !ft_isalpha('@'), "ft_isalpha: non-letters");
    TEST(!ft_isalpha('\0') && !ft_isalpha(' '), "ft_isalpha: special chars");
}

// Test isdigit function
void test_ft_isdigit(void)
{
    printf(BLUE "\n=== Testing ft_isdigit ===\n" RESET);
    TEST(ft_isdigit('0') && ft_isdigit('9'), "ft_isdigit: digits");
    TEST(!ft_isdigit('a') && !ft_isdigit('Z'), "ft_isdigit: letters");
    TEST(!ft_isdigit('@') && !ft_isdigit(' '), "ft_isdigit: special chars");
}

// Test isalnum function
void test_ft_isalnum(void)
{
    printf(BLUE "\n=== Testing ft_isalnum ===\n" RESET);
    TEST(ft_isalnum('a') && ft_isalnum('Z') && ft_isalnum('5'), "ft_isalnum: alphanumeric");
    TEST(!ft_isalnum('@') && !ft_isalnum(' '), "ft_isalnum: special chars");
}

// Test isascii function
void test_ft_isascii(void)
{
    printf(BLUE "\n=== Testing ft_isascii ===\n" RESET);
    TEST(ft_isascii(0) && ft_isascii(127), "ft_isascii: boundary values");
    TEST(ft_isascii('a') && ft_isascii('1'), "ft_isascii: normal chars");
    TEST(!ft_isascii(128) && !ft_isascii(-1), "ft_isascii: out of range");
}

// Test isprint function
void test_ft_isprint(void)
{
    printf(BLUE "\n=== Testing ft_isprint ===\n" RESET);
    TEST(ft_isprint(' ') && ft_isprint('~'), "ft_isprint: boundary printable");
    TEST(ft_isprint('a') && ft_isprint('1'), "ft_isprint: normal chars");
    TEST(!ft_isprint('\t') && !ft_isprint('\n'), "ft_isprint: non-printable");
}

// Test strlen function
void test_ft_strlen(void)
{
    printf(BLUE "\n=== Testing ft_strlen ===\n" RESET);
    TEST(ft_strlen("Hello") == 5, "ft_strlen: normal string");
    TEST(ft_strlen("") == 0, "ft_strlen: empty string");
    TEST(ft_strlen("42") == 2, "ft_strlen: numbers");
    TEST(ft_strlen("Hello\0World") == 5, "ft_strlen: string with null");
}

// Test memset function
void test_ft_memset(void)
{
    printf(BLUE "\n=== Testing ft_memset ===\n" RESET);
    char buffer[10];
    ft_memset(buffer, 'A', 5);
    buffer[5] = '\0';
    TEST(strcmp(buffer, "AAAAA") == 0, "ft_memset: set chars");
    
    ft_memset(buffer, 0, 10);
    TEST(buffer[0] == 0 && buffer[9] == 0, "ft_memset: set zeros");
}

// Test bzero function
void test_ft_bzero(void)
{
    printf(BLUE "\n=== Testing ft_bzero ===\n" RESET);
    char buffer[10] = "123456789";
    ft_bzero(buffer, 5);
    TEST(buffer[0] == 0 && buffer[4] == 0 && buffer[5] == '6', "ft_bzero: partial zero");
    
    ft_bzero(buffer, 10);
    TEST(buffer[9] == 0, "ft_bzero: complete zero");
}

// Test memcpy function
void test_ft_memcpy(void)
{
    printf(BLUE "\n=== Testing ft_memcpy ===\n" RESET);
    char src[] = "Hello World";
    char dest[20];
    
    ft_memcpy(dest, src, strlen(src) + 1);
    TEST(strcmp(dest, "Hello World") == 0, "ft_memcpy: copy string");
    
    char nums[] = {1, 2, 3, 4, 5};
    char dest_nums[5];
    ft_memcpy(dest_nums, nums, 5);
    TEST(dest_nums[0] == 1 && dest_nums[4] == 5, "ft_memcpy: copy bytes");
}

// Test memmove function
void test_ft_memmove(void)
{
    printf(BLUE "\n=== Testing ft_memmove ===\n" RESET);
    char str[] = "Hello World";
    
    // Overlapping memory test
    ft_memmove(str + 2, str, 5);
    TEST(strncmp(str, "HeHello", 7) == 0, "ft_memmove: overlapping forward");
    
    char str2[] = "Hello World";
    ft_memmove(str2, str2 + 6, 5);
    TEST(strncmp(str2, "World", 5) == 0, "ft_memmove: overlapping backward");
}

// Test strlcpy function
void test_ft_strlcpy(void)
{
    printf(BLUE "\n=== Testing ft_strlcpy ===\n" RESET);
    char dest[10];
    size_t result;
    
    result = ft_strlcpy(dest, "Hello", 10);
    TEST(strcmp(dest, "Hello") == 0 && result == 5, "ft_strlcpy: normal copy");
    
    result = ft_strlcpy(dest, "Hello World", 6);
    TEST(strcmp(dest, "Hello") == 0 && result == 11, "ft_strlcpy: truncated");
}

// Test strlcat function
void test_ft_strlcat(void)
{
    printf(BLUE "\n=== Testing ft_strlcat ===\n" RESET);
    char dest[20] = "Hello ";
    size_t result;
    
    result = ft_strlcat(dest, "World", 20);
    TEST(strcmp(dest, "Hello World") == 0 && result == 11, "ft_strlcat: normal concat");
    
    char dest2[10] = "Hello";
    result = ft_strlcat(dest2, " World!", 10);
    TEST(strcmp(dest2, "Hello Wo") == 0, "ft_strlcat: truncated concat");
}

// Test toupper function
void test_ft_toupper(void)
{
    printf(BLUE "\n=== Testing ft_toupper ===\n" RESET);
    TEST(ft_toupper('a') == 'A', "ft_toupper: lowercase to uppercase");
    TEST(ft_toupper('Z') == 'Z', "ft_toupper: already uppercase");
    TEST(ft_toupper('1') == '1', "ft_toupper: non-letter");
}

// Test tolower function
void test_ft_tolower(void)
{
    printf(BLUE "\n=== Testing ft_tolower ===\n" RESET);
    TEST(ft_tolower('A') == 'a', "ft_tolower: uppercase to lowercase");
    TEST(ft_tolower('z') == 'z', "ft_tolower: already lowercase");
    TEST(ft_tolower('1') == '1', "ft_tolower: non-letter");
}

// Test strchr function
void test_ft_strchr(void)
{
    printf(BLUE "\n=== Testing ft_strchr ===\n" RESET);
    char *str = "Hello World";
    TEST(ft_strchr(str, 'o') == str + 4, "ft_strchr: find char");
    TEST(ft_strchr(str, 'x') == NULL, "ft_strchr: char not found");
    TEST(ft_strchr(str, '\0') == str + strlen(str), "ft_strchr: find null terminator");
}

// Test strrchr function
void test_ft_strrchr(void)
{
    printf(BLUE "\n=== Testing ft_strrchr ===\n" RESET);
    char *str = "Hello World";
    TEST(ft_strrchr(str, 'o') == str + 7, "ft_strrchr: find last char");
    TEST(ft_strrchr(str, 'x') == NULL, "ft_strrchr: char not found");
    TEST(ft_strrchr(str, 'H') == str, "ft_strrchr: find first char");
}

// Test strncmp function
void test_ft_strncmp(void)
{
    printf(BLUE "\n=== Testing ft_strncmp ===\n" RESET);
    TEST(ft_strncmp("Hello", "Hello", 5) == 0, "ft_strncmp: equal strings");
    TEST(ft_strncmp("Hello", "Hell", 4) == 0, "ft_strncmp: partial match");
    TEST(ft_strncmp("Hello", "World", 5) != 0, "ft_strncmp: different strings");
    TEST(ft_strncmp("ABC", "ABD", 3) < 0, "ft_strncmp: first < second");
}

// Test memchr function
void test_ft_memchr(void)
{
    printf(BLUE "\n=== Testing ft_memchr ===\n" RESET);
    char *str = "Hello World";
    TEST(ft_memchr(str, 'o', 11) == str + 4, "ft_memchr: find byte");
    TEST(ft_memchr(str, 'x', 11) == NULL, "ft_memchr: byte not found");
    TEST(ft_memchr(str, '\0', 12) == str + 11, "ft_memchr: find null byte");
}

// Test memcmp function
void test_ft_memcmp(void)
{
    printf(BLUE "\n=== Testing ft_memcmp ===\n" RESET);
    TEST(ft_memcmp("Hello", "Hello", 5) == 0, "ft_memcmp: equal memory");
    TEST(ft_memcmp("Hello", "Hell", 4) == 0, "ft_memcmp: partial equal");
    TEST(ft_memcmp("ABC", "ABD", 3) < 0, "ft_memcmp: first < second");
}

// Test strnstr function
void test_ft_strnstr(void)
{
    printf(BLUE "\n=== Testing ft_strnstr ===\n" RESET);
    char *haystack = "Hello World";
    TEST(ft_strnstr(haystack, "World", 11) == haystack + 6, "ft_strnstr: find substring");
    TEST(ft_strnstr(haystack, "World", 8) == NULL, "ft_strnstr: not found in range");
    TEST(ft_strnstr(haystack, "", 5) == haystack, "ft_strnstr: empty needle");
}

// Test atoi function
void test_ft_atoi(void)
{
    printf(BLUE "\n=== Testing ft_atoi ===\n" RESET);
    TEST(ft_atoi("42") == 42, "ft_atoi: positive number");
    TEST(ft_atoi("-42") == -42, "ft_atoi: negative number");
    TEST(ft_atoi("   123") == 123, "ft_atoi: with whitespace");
    TEST(ft_atoi("123abc") == 123, "ft_atoi: with trailing chars");
    TEST(ft_atoi("0") == 0, "ft_atoi: zero");
}

// Test calloc function
void test_ft_calloc(void)
{
    printf(BLUE "\n=== Testing ft_calloc ===\n" RESET);
    int *ptr = (int *)ft_calloc(5, sizeof(int));
    TEST(ptr != NULL, "ft_calloc: allocation success");
    TEST(ptr[0] == 0 && ptr[4] == 0, "ft_calloc: zero initialization");
    free(ptr);
    
    char *str = (char *)ft_calloc(10, sizeof(char));
    TEST(str != NULL && str[0] == 0 && str[9] == 0, "ft_calloc: char array");
    free(str);
}

// Test strdup function
void test_ft_strdup(void)
{
    printf(BLUE "\n=== Testing ft_strdup ===\n" RESET);
    char *original = "Hello World";
    char *duplicate = ft_strdup(original);
    
    TEST(duplicate != NULL, "ft_strdup: allocation success");
    TEST(strcmp(duplicate, original) == 0, "ft_strdup: correct copy");
    TEST(duplicate != original, "ft_strdup: different memory address");
    free(duplicate);
    
    char *empty_dup = ft_strdup("");
    TEST(empty_dup != NULL && strlen(empty_dup) == 0, "ft_strdup: empty string");
    free(empty_dup);
}

// Test substr function
void test_ft_substr(void)
{
    printf(BLUE "\n=== Testing ft_substr ===\n" RESET);
    char *str = "Hello World";
    char *sub = ft_substr(str, 6, 5);
    
    TEST(sub != NULL && strcmp(sub, "World") == 0, "ft_substr: normal substring");
    free(sub);
    
    sub = ft_substr(str, 0, 5);
    TEST(sub != NULL && strcmp(sub, "Hello") == 0, "ft_substr: from beginning");
    free(sub);
    
    sub = ft_substr(str, 20, 5);
    TEST(sub != NULL && strlen(sub) == 0, "ft_substr: out of bounds");
    free(sub);
}

// Test strjoin function
void test_ft_strjoin(void)
{
    printf(BLUE "\n=== Testing ft_strjoin ===\n" RESET);
    char *s1 = "Hello ";
    char *s2 = "World";
    char *joined = ft_strjoin(s1, s2);
    
    TEST(joined != NULL && strcmp(joined, "Hello World") == 0, "ft_strjoin: normal join");
    free(joined);
    
    joined = ft_strjoin("", "Hello");
    TEST(joined != NULL && strcmp(joined, "Hello") == 0, "ft_strjoin: empty first");
    free(joined);
    
    joined = ft_strjoin("Hello", "");
    TEST(joined != NULL && strcmp(joined, "Hello") == 0, "ft_strjoin: empty second");
    free(joined);
}

// Test strtrim function
void test_ft_strtrim(void)
{
    printf(BLUE "\n=== Testing ft_strtrim ===\n" RESET);
    char *trimmed = ft_strtrim("   Hello World   ", " ");
    TEST(trimmed != NULL && strcmp(trimmed, "Hello World") == 0, "ft_strtrim: spaces");
    free(trimmed);
    
    trimmed = ft_strtrim("abcHello Worldcba", "abc");
    TEST(trimmed != NULL && strcmp(trimmed, "Hello World") == 0, "ft_strtrim: custom chars");
    free(trimmed);
    
    trimmed = ft_strtrim("Hello", "xyz");
    TEST(trimmed != NULL && strcmp(trimmed, "Hello") == 0, "ft_strtrim: no trim needed");
    free(trimmed);
}

// Helper function for ft_split tests
int count_words(char **split)
{
    int count = 0;
    while (split[count])
        count++;
    return count;
}

void free_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

// Test split function
void test_ft_split(void)
{
    printf(BLUE "\n=== Testing ft_split ===\n" RESET);
    char **split = ft_split("Hello World 42", ' ');
    
    TEST(split != NULL && count_words(split) == 3, "ft_split: word count");
    TEST(strcmp(split[0], "Hello") == 0, "ft_split: first word");
    TEST(strcmp(split[1], "World") == 0, "ft_split: second word");
    TEST(strcmp(split[2], "42") == 0, "ft_split: third word");
    TEST(split[3] == NULL, "ft_split: null termination");
    free_split(split);
    
    split = ft_split("", ' ');
    TEST(split != NULL && split[0] == NULL, "ft_split: empty string");
    free_split(split);
    
    split = ft_split("   ", ' ');
    TEST(split != NULL && split[0] == NULL, "ft_split: only delimiters");
    free_split(split);
}

// Test itoa function
void test_ft_itoa(void)
{
    printf(BLUE "\n=== Testing ft_itoa ===\n" RESET);
    char *str = ft_itoa(42);
    TEST(str != NULL && strcmp(str, "42") == 0, "ft_itoa: positive number");
    free(str);
    
    str = ft_itoa(-42);
    TEST(str != NULL && strcmp(str, "-42") == 0, "ft_itoa: negative number");
    free(str);
    
    str = ft_itoa(0);
    TEST(str != NULL && strcmp(str, "0") == 0, "ft_itoa: zero");
    free(str);
    
    str = ft_itoa(-2147483648);
    TEST(str != NULL && strcmp(str, "-2147483648") == 0, "ft_itoa: INT_MIN");
    free(str);
}

// Helper function for strmapi test
char test_mapi_func(unsigned int i, char c)
{
    if (i % 2 == 0)
        return ft_toupper(c);
    return ft_tolower(c);
}

// Test strmapi function
void test_ft_strmapi(void)
{
    printf(BLUE "\n=== Testing ft_strmapi ===\n" RESET);
    char *result = ft_strmapi("hello", test_mapi_func);
    TEST(result != NULL && strcmp(result, "HeLlO") == 0, "ft_strmapi: alternating case");
    free(result);
    
    result = ft_strmapi("", test_mapi_func);
    TEST(result != NULL && strlen(result) == 0, "ft_strmapi: empty string");
    free(result);
}

// Test striteri function
void test_striteri_func(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = ft_toupper(*c);
    else
        *c = ft_tolower(*c);
}

void test_ft_striteri(void)
{
    printf(BLUE "\n=== Testing ft_striteri ===\n" RESET);
    char str[] = "hello";
    ft_striteri(str, test_striteri_func);
    TEST(strcmp(str, "HeLlO") == 0, "ft_striteri: alternating case");
    
    char empty[] = "";
    ft_striteri(empty, test_striteri_func);
    TEST(strlen(empty) == 0, "ft_striteri: empty string");
}

// Test putchar_fd function
void test_ft_putchar_fd(void)
{
    printf(BLUE "\n=== Testing ft_putchar_fd ===\n" RESET);
    printf("Expected output: A\nActual output: ");
    ft_putchar_fd('A', 1);
    printf("\n");
    // Visual test - check if 'A' is printed
    TEST(1, "ft_putchar_fd: visual test (check output above)");
}

// Test putstr_fd function
void test_ft_putstr_fd(void)
{
    printf(BLUE "\n=== Testing ft_putstr_fd ===\n" RESET);
    printf("Expected output: Hello World\nActual output: ");
    ft_putstr_fd("Hello World", 1);
    printf("\n");
    TEST(1, "ft_putstr_fd: visual test (check output above)");
}

// Test putendl_fd function
void test_ft_putendl_fd(void)
{
    printf(BLUE "\n=== Testing ft_putendl_fd ===\n" RESET);
    printf("Expected output: Hello World\\n\nActual output: ");
    ft_putendl_fd("Hello World", 1);
    TEST(1, "ft_putendl_fd: visual test (check output above)");
}

// Test putnbr_fd function
void test_ft_putnbr_fd(void)
{
    printf(BLUE "\n=== Testing ft_putnbr_fd ===\n" RESET);
    printf("Expected output: 42 -42 0 -2147483648\nActual output: ");
    ft_putnbr_fd(42, 1);
    ft_putchar_fd(' ', 1);
    ft_putnbr_fd(-42, 1);
    ft_putchar_fd(' ', 1);
    ft_putnbr_fd(0, 1);
    ft_putchar_fd(' ', 1);
    ft_putnbr_fd(-2147483648, 1);
    printf("\n");
    TEST(1, "ft_putnbr_fd: visual test (check output above)");
}

// Main function to run all tests
int main(void)
{
    printf(YELLOW "=== LIBFT COMPREHENSIVE TEST SUITE ===\n" RESET);
    printf("Testing all standard libft functions...\n");
    
    // Run all tests
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_strlen();
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_toupper();
    test_ft_tolower();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strncmp();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_strnstr();
    test_ft_atoi();
    test_ft_calloc();
    test_ft_strdup();
    test_ft_substr();
    test_ft_strjoin();
    test_ft_strtrim();
    test_ft_split();
    test_ft_itoa();
    test_edge_cases();
    
    // Print summary
    printf(BLUE "\n=== TEST SUMMARY ===\n" RESET);
    printf(GREEN "Tests passed: %d\n" RESET, tests_passed);
    printf(RED "Tests failed: %d\n" RESET, tests_failed);
    printf("Total tests: %d\n", tests_passed + tests_failed);
    
    if (tests_failed == 0)
        printf(GREEN "🎉 All tests passed! Your libft implementation is working correctly!\n" RESET);
    else
        printf(YELLOW "⚠️  Some tests failed. Please check your implementation.\n" RESET);
    
    return (tests_failed == 0 ? 0 : 1);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:00:00 by test              #+#    #+#             */
/*   Updated: 2025/06/03 19:15:39 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "libft.h"  // Include your libft header file

// ANSI color codes for better output
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Test counter
int tests_passed = 0;
int tests_failed = 0;

// Helper macro for testing
#define TEST(condition, test_name) \
    do { \
        if (condition) { \
            printf(GREEN "✓ " RESET "%s\n", test_name); \
            tests_passed++; \
        } else { \
            printf(RED "✗ " RESET "%s\n", test_name); \
            tests_failed++; \
        } \
    } while(0)

// Test isalpha function
void test_ft_isalpha(void)
{
    printf(BLUE "\n=== Testing ft_isalpha ===\n" RESET);
    TEST(ft_isalpha('a') && ft_isalpha('Z'), "ft_isalpha: letters");
    TEST(!ft_isalpha('1') && !ft_isalpha('@'), "ft_isalpha: non-letters");
    TEST(!ft_isalpha('\0') && !ft_isalpha(' '), "ft_isalpha: special chars");
}

// Test isdigit function
void test_ft_isdigit(void)
{
    printf(BLUE "\n=== Testing ft_isdigit ===\n" RESET);
    TEST(ft_isdigit('0') && ft_isdigit('9'), "ft_isdigit: digits");
    TEST(!ft_isdigit('a') && !ft_isdigit('Z'), "ft_isdigit: letters");
    TEST(!ft_isdigit('@') && !ft_isdigit(' '), "ft_isdigit: special chars");
}

// Test isalnum function
void test_ft_isalnum(void)
{
    printf(BLUE "\n=== Testing ft_isalnum ===\n" RESET);
    TEST(ft_isalnum('a') && ft_isalnum('Z') && ft_isalnum('5'), "ft_isalnum: alphanumeric");
    TEST(!ft_isalnum('@') && !ft_isalnum(' '), "ft_isalnum: special chars");
}

// Test isascii function
void test_ft_isascii(void)
{
    printf(BLUE "\n=== Testing ft_isascii ===\n" RESET);
    TEST(ft_isascii(0) && ft_isascii(127), "ft_isascii: boundary values");
    TEST(ft_isascii('a') && ft_isascii('1'), "ft_isascii: normal chars");
    TEST(!ft_isascii(128) && !ft_isascii(-1), "ft_isascii: out of range");
}

// Test isprint function
void test_ft_isprint(void)
{
    printf(BLUE "\n=== Testing ft_isprint ===\n" RESET);
    TEST(ft_isprint(' ') && ft_isprint('~'), "ft_isprint: boundary printable");
    TEST(ft_isprint('a') && ft_isprint('1'), "ft_isprint: normal chars");
    TEST(!ft_isprint('\t') && !ft_isprint('\n'), "ft_isprint: non-printable");
}

// Test strlen function
void test_ft_strlen(void)
{
    printf(BLUE "\n=== Testing ft_strlen ===\n" RESET);
    TEST(ft_strlen("Hello") == 5, "ft_strlen: normal string");
    TEST(ft_strlen("") == 0, "ft_strlen: empty string");
    TEST(ft_strlen("42") == 2, "ft_strlen: numbers");
    TEST(ft_strlen("Hello\0World") == 5, "ft_strlen: string with null");
}

// Test memset function
void test_ft_memset(void)
{
    printf(BLUE "\n=== Testing ft_memset ===\n" RESET);
    char buffer[10];
    ft_memset(buffer, 'A', 5);
    buffer[5] = '\0';
    TEST(strcmp(buffer, "AAAAA") == 0, "ft_memset: set chars");
    
    ft_memset(buffer, 0, 10);
    TEST(buffer[0] == 0 && buffer[9] == 0, "ft_memset: set zeros");
}

// Test bzero function
void test_ft_bzero(void)
{
    printf(BLUE "\n=== Testing ft_bzero ===\n" RESET);
    char buffer[10] = "123456789";
    ft_bzero(buffer, 5);
    TEST(buffer[0] == 0 && buffer[4] == 0 && buffer[5] == '6', "ft_bzero: partial zero");
    
    ft_bzero(buffer, 10);
    TEST(buffer[9] == 0, "ft_bzero: complete zero");
}

// Test memcpy function
void test_ft_memcpy(void)
{
    printf(BLUE "\n=== Testing ft_memcpy ===\n" RESET);
    char src[] = "Hello World";
    char dest[20];
    
    ft_memcpy(dest, src, strlen(src) + 1);
    TEST(strcmp(dest, "Hello World") == 0, "ft_memcpy: copy string");
    
    char nums[] = {1, 2, 3, 4, 5};
    char dest_nums[5];
    ft_memcpy(dest_nums, nums, 5);
    TEST(dest_nums[0] == 1 && dest_nums[4] == 5, "ft_memcpy: copy bytes");
}

// Test memmove function
void test_ft_memmove(void)
{
    printf(BLUE "\n=== Testing ft_memmove ===\n" RESET);
    char str[] = "Hello World";
    
    // Overlapping memory test
    ft_memmove(str + 2, str, 5);
    TEST(strncmp(str, "HeHello", 7) == 0, "ft_memmove: overlapping forward");
    
    char str2[] = "Hello World";
    ft_memmove(str2, str2 + 6, 5);
    TEST(strncmp(str2, "World", 5) == 0, "ft_memmove: overlapping backward");
}

// Test strlcpy function
void test_ft_strlcpy(void)
{
    printf(BLUE "\n=== Testing ft_strlcpy ===\n" RESET);
    char dest[10];
    size_t result;
    
    result = ft_strlcpy(dest, "Hello", 10);
    TEST(strcmp(dest, "Hello") == 0 && result == 5, "ft_strlcpy: normal copy");
    
    result = ft_strlcpy(dest, "Hello World", 6);
    TEST(strcmp(dest, "Hello") == 0 && result == 11, "ft_strlcpy: truncated");
}

// Test strlcat function
void test_ft_strlcat(void)
{
    printf(BLUE "\n=== Testing ft_strlcat ===\n" RESET);
    char dest[20] = "Hello ";
    size_t result;
    
    result = ft_strlcat(dest, "World", 20);
    TEST(strcmp(dest, "Hello World") == 0 && result == 11, "ft_strlcat: normal concat");
    
    char dest2[10] = "Hello";
    result = ft_strlcat(dest2, " World!", 10);
    TEST(strcmp(dest2, "Hello Wo") == 0, "ft_strlcat: truncated concat");
}

// Test toupper function
void test_ft_toupper(void)
{
    printf(BLUE "\n=== Testing ft_toupper ===\n" RESET);
    TEST(ft_toupper('a') == 'A', "ft_toupper: lowercase to uppercase");
    TEST(ft_toupper('Z') == 'Z', "ft_toupper: already uppercase");
    TEST(ft_toupper('1') == '1', "ft_toupper: non-letter");
}

// Test tolower function
void test_ft_tolower(void)
{
    printf(BLUE "\n=== Testing ft_tolower ===\n" RESET);
    TEST(ft_tolower('A') == 'a', "ft_tolower: uppercase to lowercase");
    TEST(ft_tolower('z') == 'z', "ft_tolower: already lowercase");
    TEST(ft_tolower('1') == '1', "ft_tolower: non-letter");
}

// Test strchr function
void test_ft_strchr(void)
{
    printf(BLUE "\n=== Testing ft_strchr ===\n" RESET);
    char *str = "Hello World";
    TEST(ft_strchr(str, 'o') == str + 4, "ft_strchr: find char");
    TEST(ft_strchr(str, 'x') == NULL, "ft_strchr: char not found");
    TEST(ft_strchr(str, '\0') == str + strlen(str), "ft_strchr: find null terminator");
}

// Test strrchr function
void test_ft_strrchr(void)
{
    printf(BLUE "\n=== Testing ft_strrchr ===\n" RESET);
    char *str = "Hello World";
    TEST(ft_strrchr(str, 'o') == str + 7, "ft_strrchr: find last char");
    TEST(ft_strrchr(str, 'x') == NULL, "ft_strrchr: char not found");
    TEST(ft_strrchr(str, 'H') == str, "ft_strrchr: find first char");
}

// Test strncmp function
void test_ft_strncmp(void)
{
    printf(BLUE "\n=== Testing ft_strncmp ===\n" RESET);
    TEST(ft_strncmp("Hello", "Hello", 5) == 0, "ft_strncmp: equal strings");
    TEST(ft_strncmp("Hello", "Hell", 4) == 0, "ft_strncmp: partial match");
    TEST(ft_strncmp("Hello", "World", 5) != 0, "ft_strncmp: different strings");
    TEST(ft_strncmp("ABC", "ABD", 3) < 0, "ft_strncmp: first < second");
}

// Test memchr function
void test_ft_memchr(void)
{
    printf(BLUE "\n=== Testing ft_memchr ===\n" RESET);
    char *str = "Hello World";
    TEST(ft_memchr(str, 'o', 11) == str + 4, "ft_memchr: find byte");
    TEST(ft_memchr(str, 'x', 11) == NULL, "ft_memchr: byte not found");
    TEST(ft_memchr(str, '\0', 12) == str + 11, "ft_memchr: find null byte");
}

// Test memcmp function
void test_ft_memcmp(void)
{
    printf(BLUE "\n=== Testing ft_memcmp ===\n" RESET);
    TEST(ft_memcmp("Hello", "Hello", 5) == 0, "ft_memcmp: equal memory");
    TEST(ft_memcmp("Hello", "Hell", 4) == 0, "ft_memcmp: partial equal");
    TEST(ft_memcmp("ABC", "ABD", 3) < 0, "ft_memcmp: first < second");
}

// Test strnstr function
void test_ft_strnstr(void)
{
    printf(BLUE "\n=== Testing ft_strnstr ===\n" RESET);
    char *haystack = "Hello World";
    TEST(ft_strnstr(haystack, "World", 11) == haystack + 6, "ft_strnstr: find substring");
    TEST(ft_strnstr(haystack, "World", 8) == NULL, "ft_strnstr: not found in range");
    TEST(ft_strnstr(haystack, "", 5) == haystack, "ft_strnstr: empty needle");
}

// Test atoi function
void test_ft_atoi(void)
{
    printf(BLUE "\n=== Testing ft_atoi ===\n" RESET);
    TEST(ft_atoi("42") == 42, "ft_atoi: positive number");
    TEST(ft_atoi("-42") == -42, "ft_atoi: negative number");
    TEST(ft_atoi("   123") == 123, "ft_atoi: with whitespace");
    TEST(ft_atoi("123abc") == 123, "ft_atoi: with trailing chars");
    TEST(ft_atoi("0") == 0, "ft_atoi: zero");
}

// Test calloc function
void test_ft_calloc(void)
{
    printf(BLUE "\n=== Testing ft_calloc ===\n" RESET);
    int *ptr = (int *)ft_calloc(5, sizeof(int));
    TEST(ptr != NULL, "ft_calloc: allocation success");
    TEST(ptr[0] == 0 && ptr[4] == 0, "ft_calloc: zero initialization");
    free(ptr);
    
    char *str = (char *)ft_calloc(10, sizeof(char));
    TEST(str != NULL && str[0] == 0 && str[9] == 0, "ft_calloc: char array");
    free(str);
}

// Test strdup function
void test_ft_strdup(void)
{
    printf(BLUE "\n=== Testing ft_strdup ===\n" RESET);
    char *original = "Hello World";
    char *duplicate = ft_strdup(original);
    
    TEST(duplicate != NULL, "ft_strdup: allocation success");
    TEST(strcmp(duplicate, original) == 0, "ft_strdup: correct copy");
    TEST(duplicate != original, "ft_strdup: different memory address");
    free(duplicate);
    
    char *empty_dup = ft_strdup("");
    TEST(empty_dup != NULL && strlen(empty_dup) == 0, "ft_strdup: empty string");
    free(empty_dup);
}

// Test substr function
void test_ft_substr(void)
{
    printf(BLUE "\n=== Testing ft_substr ===\n" RESET);
    char *str = "Hello World";
    char *sub = ft_substr(str, 6, 5);
    
    TEST(sub != NULL && strcmp(sub, "World") == 0, "ft_substr: normal substring");
    free(sub);
    
    sub = ft_substr(str, 0, 5);
    TEST(sub != NULL && strcmp(sub, "Hello") == 0, "ft_substr: from beginning");
    free(sub);
    
    sub = ft_substr(str, 20, 5);
    TEST(sub != NULL && strlen(sub) == 0, "ft_substr: out of bounds");
    free(sub);
}

// Test strjoin function
void test_ft_strjoin(void)
{
    printf(BLUE "\n=== Testing ft_strjoin ===\n" RESET);
    char *s1 = "Hello ";
    char *s2 = "World";
    char *joined = ft_strjoin(s1, s2);
    
    TEST(joined != NULL && strcmp(joined, "Hello World") == 0, "ft_strjoin: normal join");
    free(joined);
    
    joined = ft_strjoin("", "Hello");
    TEST(joined != NULL && strcmp(joined, "Hello") == 0, "ft_strjoin: empty first");
    free(joined);
    
    joined = ft_strjoin("Hello", "");
    TEST(joined != NULL && strcmp(joined, "Hello") == 0, "ft_strjoin: empty second");
    free(joined);
}

// Test strtrim function
void test_ft_strtrim(void)
{
    printf(BLUE "\n=== Testing ft_strtrim ===\n" RESET);
    char *trimmed = ft_strtrim("   Hello World   ", " ");
    TEST(trimmed != NULL && strcmp(trimmed, "Hello World") == 0, "ft_strtrim: spaces");
    free(trimmed);
    
    trimmed = ft_strtrim("abcHello Worldcba", "abc");
    TEST(trimmed != NULL && strcmp(trimmed, "Hello World") == 0, "ft_strtrim: custom chars");
    free(trimmed);
    
    trimmed = ft_strtrim("Hello", "xyz");
    TEST(trimmed != NULL && strcmp(trimmed, "Hello") == 0, "ft_strtrim: no trim needed");
    free(trimmed);
}

// Helper function for ft_split tests
int count_words(char **split)
{
    int count = 0;
    while (split[count])
        count++;
    return count;
}

void free_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

// Test split function
void test_ft_split(void)
{
    printf(BLUE "\n=== Testing ft_split ===\n" RESET);
    char **split = ft_split("Hello World 42", ' ');
    
    TEST(split != NULL && count_words(split) == 3, "ft_split: word count");
    TEST(strcmp(split[0], "Hello") == 0, "ft_split: first word");
    TEST(strcmp(split[1], "World") == 0, "ft_split: second word");
    TEST(strcmp(split[2], "42") == 0, "ft_split: third word");
    TEST(split[3] == NULL, "ft_split: null termination");
    free_split(split);
    
    split = ft_split("", ' ');
    TEST(split != NULL && split[0] == NULL, "ft_split: empty string");
    free_split(split);
    
    split = ft_split("   ", ' ');
    TEST(split != NULL && split[0] == NULL, "ft_split: only delimiters");
    free_split(split);
}

// Test itoa function
void test_ft_itoa(void)
{
    printf(BLUE "\n=== Testing ft_itoa ===\n" RESET);
    char *str = ft_itoa(42);
    TEST(str != NULL && strcmp(str, "42") == 0, "ft_itoa: positive number");
    free(str);
    
    str = ft_itoa(-42);
    TEST(str != NULL && strcmp(str, "-42") == 0, "ft_itoa: negative number");
    free(str);
    
    str = ft_itoa(0);
    TEST(str != NULL && strcmp(str, "0") == 0, "ft_itoa: zero");
    free(str);
    
    str = ft_itoa(-2147483648);
    TEST(str != NULL && strcmp(str, "-2147483648") == 0, "ft_itoa: INT_MIN");
    free(str);
}

// Helper function for strmapi test
char test_mapi_func(unsigned int i, char c)
{
    if (i % 2 == 0)
        return ft_toupper(c);
    return ft_tolower(c);
}

// Test strmapi function
void test_ft_strmapi(void)
{
    printf(BLUE "\n=== Testing ft_strmapi ===\n" RESET);
    char *result = ft_strmapi("hello", test_mapi_func);
    TEST(result != NULL && strcmp(result, "HeLlO") == 0, "ft_strmapi: alternating case");
    free(result);
    
    result = ft_strmapi("", test_mapi_func);
    TEST(result != NULL && strlen(result) == 0, "ft_strmapi: empty string");
    free(result);
}

// Test striteri function
void test_striteri_func(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = ft_toupper(*c);
    else
        *c = ft_tolower(*c);
}

void test_ft_striteri(void)
{
    printf(BLUE "\n=== Testing ft_striteri ===\n" RESET);
    char str[] = "hello";
    ft_striteri(str, test_striteri_func);
    TEST(strcmp(str, "HeLlO") == 0, "ft_striteri: alternating case");
    
    char empty[] = "";
    ft_striteri(empty, test_striteri_func);
    TEST(strlen(empty) == 0, "ft_striteri: empty string");
}

// Test putchar_fd function
void test_ft_putchar_fd(void)
{
    printf(BLUE "\n=== Testing ft_putchar_fd ===\n" RESET);
    printf("Expected output: A\nActual output: ");
    ft_putchar_fd('A', 1);
    printf("\n");
    // Visual test - check if 'A' is printed
    TEST(1, "ft_putchar_fd: visual test (check output above)");
}

// Test putstr_fd function
void test_ft_putstr_fd(void)
{
    printf(BLUE "\n=== Testing ft_putstr_fd ===\n" RESET);
    printf("Expected output: Hello World\nActual output: ");
    ft_putstr_fd("Hello World", 1);
    printf("\n");
    TEST(1, "ft_putstr_fd: visual test (check output above)");
}

// Test putendl_fd function
void test_ft_putendl_fd(void)
{
    printf(BLUE "\n=== Testing ft_putendl_fd ===\n" RESET);
    printf("Expected output: Hello World\\n\nActual output: ");
    ft_putendl_fd("Hello World", 1);
    TEST(1, "ft_putendl_fd: visual test (check output above)");
}

// Test putnbr_fd function
void test_ft_putnbr_fd(void)
{
    printf(BLUE "\n=== Testing ft_putnbr_fd ===\n" RESET);
    printf("Expected output: 42 -42 0 -2147483648\nActual output: ");
    ft_putnbr_fd(42, 1);
    ft_putchar_fd(' ', 1);
    ft_putnbr_fd(-42, 1);
    ft_putchar_fd(' ', 1);
    ft_putnbr_fd(0, 1);
    ft_putchar_fd(' ', 1);
    ft_putnbr_fd(-2147483648, 1);
    printf("\n");
    TEST(1, "ft_putnbr_fd: visual test (check output above)");
}

// Main function to run all tests
int main(void)
{
    printf(YELLOW "=== LIBFT COMPREHENSIVE TEST SUITE ===\n" RESET);
    printf("Testing all standard libft functions...\n");
    
    // Run all tests
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_strlen();
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_toupper();
    test_ft_tolower();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strncmp();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_strnstr();
    test_ft_atoi();
    test_ft_calloc();
    test_ft_strdup();
    test_ft_substr();
    test_ft_strjoin();
    test_ft_strtrim();
    test_ft_split();
    test_ft_itoa();
    test_ft_strmapi();
    test_ft_striteri();
    test_ft_putchar_fd();
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();
    
    // Print summary
    printf(BLUE "\n=== TEST SUMMARY ===\n" RESET);
    printf(GREEN "Tests passed: %d\n" RESET, tests_passed);
    printf(RED "Tests failed: %d\n" RESET, tests_failed);
    printf("Total tests: %d\n", tests_passed + tests_failed);
    
    if (tests_failed == 0)
        printf(GREEN "🎉 All tests passed! Your libft implementation is working correctly!\n" RESET);
    else
        printf(YELLOW "⚠️  Some tests failed. Please check your implementation.\n" RESET);
    
    return (tests_failed == 0 ? 0 : 1);
}