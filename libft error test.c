#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void test_strlen_null(void) {
    printf("[ft_strlen NULL] -> ");
    printf("%zu\n", ft_strlen(NULL));
}

void test_strdup_null(void) {
    printf("[ft_strdup NULL] -> ");
    char *res = ft_strdup(NULL);
    printf("%s\n", res);
}

void test_memcpy_null(void) {
    printf("[ft_memcpy NULL, NULL] -> ");
    ft_memcpy(NULL, NULL, 5);
}

void test_memmove_overlap(void) {
    char str[10] = "abcdef";
    printf("[ft_memmove overlap] before: %s\n", str);
    ft_memmove(str, str + 1, 4);
    printf("[ft_memmove overlap] after: %s\n", str);
}

void test_strjoin_null(void) {
    printf("[ft_strjoin NULL, NULL] -> ");
    char *res = ft_strjoin(NULL, NULL);
    printf("%s\n", res);
}

void test_split_null(void) {
    printf("[ft_split NULL] -> ");
    char **res = ft_split(NULL, ' ');
    printf("%p\n", res);
}

void test_itoa_minint(void) {
    printf("[ft_itoa INT_MIN] -> ");
    printf("%s\n", ft_itoa(-2147483648));
}

void test_strtrim_null(void) {
    printf("[ft_strtrim NULL] -> ");
    char *res = ft_strtrim(NULL, NULL);
    printf("%s\n", res);
}

void test_strncmp_null(void) {
    printf("[ft_strncmp NULL] -> ");
    printf("%d\n", ft_strncmp(NULL, NULL, 3));
}

void test_substr_null(void) {
    printf("[ft_substr NULL] -> ");
    char *res = ft_substr(NULL, 5, 10);
    printf("%s\n", res);
}

void test_strchr_null(void) {
    printf("[ft_strchr NULL] -> ");
    printf("%s\n", ft_strchr(NULL, 'c'));
}

void test_memchr_null(void) {
    printf("[ft_memchr NULL] -> ");
    ft_memchr(NULL, 'c', 5);
}

void test_calloc_zero(void) {
    printf("[ft_calloc(0, 0)] -> ");
    void *ptr = ft_calloc(0, 0);
    printf("%p\n", ptr);
    free(ptr);
}

void test_double_free(void) {
    char *mem = malloc(10);
    printf("[double free test] -> first free\n");
    free(mem);
    printf("[double free test] -> second free\n");
    free(mem); // This causes undefined behavior
}

int main(void) {
    // Her fonksiyon isteyerek SEGFAULT veya hata vermek üzere çağrılır
    // Bu testleri tek tek açarak çalıştır

    // test_strlen_null();
    // test_strdup_null();
    // test_memcpy_null();
    // test_memmove_overlap();
    // test_strjoin_null();
    // test_split_null();
    // test_itoa_minint();
    // test_strtrim_null();
    // test_strncmp_null();
    // test_substr_null();
    // test_strchr_null();
    // test_memchr_null();
    // test_calloc_zero();
    // test_double_free();

    return 0;
}
