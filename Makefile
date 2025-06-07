# # Library name
# NAME = libft.a

# # Test executable name
# TEST_NAME = test_libft

# # Compiler and flags
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# AR = ar rcs
# RM = rm -f

# # Header file
# HEADER = libft.h

# # Source files - exactly matching your file list
# SRCS = ft_atoi.c \
#        ft_bzero.c \
#        ft_calloc.c \
#        ft_isalnum.c \
#        ft_isalpha.c \
#        ft_isascii.c \
#        ft_isdigit.c \
#        ft_isprint.c \
#        ft_itoa.c \
#        ft_memchr.c \
#        ft_memcmp.c \
#        ft_memcpy.c \
#        ft_memmove.c \
#        ft_memset.c \
#        ft_split.c \
#        ft_strchr.c \
#        ft_strdup.c \
#        ft_strjoin.c \
#        ft_strlcat.c \
#        ft_strlcpy.c \
#        ft_strlen.c \
#        ft_strncmp.c \
#        ft_strnstr.c \
#        ft_strrchr.c \
#        ft_strtrim.c \
#        ft_substr.c \
#        ft_tolower.c \
#        ft_toupper.c

# # Object files
# OBJS = $(SRCS:.c=.o)

# # Test source file
# TEST_SRC = test_libft.c

# # Colors for output
# GREEN = \033[32m
# RED = \033[31m
# BLUE = \033[34m
# YELLOW = \033[33m
# RESET = \033[0m

# # Default target
# all: $(NAME)

# # Build the library
# $(NAME): $(OBJS)
# 	@echo "$(BLUE)Creating library $(NAME)...$(RESET)"
# 	@$(AR) $(NAME) $(OBJS)
# 	@echo "$(GREEN)✓ Library $(NAME) created successfully!$(RESET)"

# # Compile source files to object files
# %.o: %.c $(HEADER)
# 	@echo "$(YELLOW)Compiling $<...$(RESET)"
# 	@$(CC) $(CFLAGS) -c $< -o $@

# # Build and run tests
# test: $(NAME) $(TEST_SRC)
# 	@echo "$(BLUE)Compiling test file...$(RESET)"
# 	@$(CC) $(CFLAGS) $(TEST_SRC) -L. -lft -o $(TEST_NAME)
# 	@echo "$(GREEN)✓ Test compiled successfully!$(RESET)"
# 	@echo "$(BLUE)Running tests...$(RESET)"
# 	@echo "$(YELLOW)==========================================$(RESET)"
# 	@./$(TEST_NAME)
# 	@echo "$(YELLOW)==========================================$(RESET)"

# # Just compile the test without running
# compile-test: $(NAME) $(TEST_SRC)
# 	@echo "$(BLUE)Compiling test file...$(RESET)"
# 	@$(CC) $(CFLAGS) $(TEST_SRC) -L. -lft -o $(TEST_NAME)
# 	@echo "$(GREEN)✓ Test compiled successfully!$(RESET)"
# 	@echo "$(YELLOW)Run './$(TEST_NAME)' to execute tests$(RESET)"

# # Run tests (assumes test is already compiled)
# run-test: $(TEST_NAME)
# 	@echo "$(BLUE)Running tests...$(RESET)"
# 	@echo "$(YELLOW)==========================================$(RESET)"
# 	@./$(TEST_NAME)
# 	@echo "$(YELLOW)==========================================$(RESET)"

# # Clean object files
# clean:
# 	@echo "$(RED)Cleaning object files...$(RESET)"
# 	@$(RM) $(OBJS)
# 	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# # Clean everything
# fclean: clean
# 	@echo "$(RED)Cleaning library and test files...$(RESET)"
# 	@$(RM) $(NAME) $(TEST_NAME)
# 	@echo "$(GREEN)✓ All files cleaned!$(RESET)"

# # Rebuild everything
# re: fclean all

# # Norm check (if you have norminette installed)
# norm:
# 	@echo "$(BLUE)Checking norm...$(RESET)"
# 	@norminette $(SRCS) $(HEADER) | grep -v "OK" || echo "$(GREEN)✓ All files pass norminette!$(RESET)"

# # Show help
# help:
# 	@echo "$(BLUE)Available targets:$(RESET)"
# 	@echo "  $(YELLOW)all$(RESET)          - Build the library (default)"
# 	@echo "  $(YELLOW)test$(RESET)         - Build library, compile test, and run tests"
# 	@echo "  $(YELLOW)compile-test$(RESET) - Build library and compile test (don't run)"
# 	@echo "  $(YELLOW)run-test$(RESET)     - Run tests (assumes test is compiled)"
# 	@echo "  $(YELLOW)clean$(RESET)        - Remove object files"
# 	@echo "  $(YELLOW)fclean$(RESET)       - Remove all generated files"
# 	@echo "  $(YELLOW)re$(RESET)           - Rebuild everything from scratch"
# 	@echo "  $(YELLOW)norm$(RESET)         - Check code norm with norminette"
# 	@echo "  $(YELLOW)help$(RESET)         - Show this help message"

# # Debug info
# debug:
# 	@echo "$(BLUE)Debug Information:$(RESET)"
# 	@echo "Library name: $(NAME)"
# 	@echo "Test name: $(TEST_NAME)"
# 	@echo "Compiler: $(CC)"
# 	@echo "Flags: $(CFLAGS)"
# 	@echo "Sources: $(words $(SRCS)) files"
# 	@echo "Objects: $(words $(OBJS)) files"

# # Show source files
# show-files:
# 	@echo "$(BLUE)Source files in this project:$(RESET)"
# 	@for file in $(SRCS); do echo "  $(YELLOW)$$file$(RESET)"; done

# # Phony targets
# .PHONY: all clean fclean re test compile-test run-test norm help debug show-files

# # Silent mode - suppress command echoing
# .SILENT:

## Library name
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Header file
HEADER = libft.h

# Source files for the library
SRCS = ft_atoi.c \
       ft_bzero.c \
       ft_calloc.c \
       ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_itoa.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memset.c \
       ft_split.c \
       ft_strchr.c \
       ft_strdup.c \
       ft_strjoin.c \
       ft_strlcat.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_strncmp.c \
       ft_strnstr.c \
       ft_strrchr.c \
       ft_strtrim.c \
       ft_substr.c \
       ft_tolower.c \
       ft_toupper.c \
       ft_strmapi.c  \
       ft_striteri.c

# Object files for the library
OBJS = $(SRCS:.c=.o)

# Test source files (each will become a separate executable)
TEST_SRCS = testFile/ft_atoitesti.c \
            testFile/ft_bzerotesti.c \
            testFile/ft_isalnumtesti.c \
            testFile/ft_isalphatest.c \
            testFile/ft_isasciitesti.c \
            testFile/ft_isdigittest.c \
            testFile/ft_isprinttesti.c \
            testFile/ft_itoatesti.c \
            testFile/ft_memchrtesti.c \
            testFile/ft_memcmptesti.c \
            testFile/ft_memcpytesti.c \
            testFile/ft_memmovetesti.c \
            testFile/ft_memsettesti.c \
            testFile/ft_splittesti.c \
            testFile/ft_strchrtesti.c \
            testFile/ft_strlcattesti.c \
            testFile/ft_strlcpytesti.c \
            testFile/ft_strlentestti.c \
            testFile/ft_strlointesti.c \
            testFile/ft_strncmptesti.c \
            testFile/ft_strnstrtesti.c \
            testFile/ft_strrchrtesti.c \
            testFile/ft_strtrimtesti.c \
            testFile/ft_substrtesti.c \
            testFile/ft_tolowertesti.c \
            testFile/ft_touppertesti.c \
            testFile/ft_strmapitesti.c \
            testFile/ft_striteritesti.c


# Test executables (derived from TEST_SRCS)
TEST_EXES = $(TEST_SRCS:.c=) # test_libft.c'yi kaldırdım, çünkü ayrı testler olacak

# Colors for output
GREEN = \033[32m
RED = \033[31m
BLUE = \033[34m
YELLOW = \033[33m
RESET = \033[0m

# Default target
all: $(NAME)

# Build the library
$(NAME): $(OBJS)
	@echo "$(BLUE)Creating library $(NAME)...$(RESET)"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ Library $(NAME) created successfully!$(RESET)"

# Compile source files to object files (for library)
%.o: %.c $(HEADER)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Build all test executables
test: $(NAME) $(TEST_EXES)
	@echo "$(BLUE)All tests compiled. To run, use 'make run-tests' or run individual executables (e.g., ./ft_atoitesti)$(RESET)"

# Rule to compile a single test executable
$(TEST_EXES): %: %.c $(NAME)
	@echo "$(BLUE)Compiling test executable $@...$(RESET)"
	@$(CC) $(CFLAGS) $< -L. -lft -o $@
	@echo "$(GREEN)✓ Test executable $@ compiled!$(RESET)"

# Run all test executables
run-tests: $(TEST_EXES)
	@echo "$(BLUE)Running all tests...$(RESET)"
	@echo "$(YELLOW)==========================================$(RESET)"
	@for test_exe in $(TEST_EXES); do \
		echo "$(BLUE)Running $$test_exe...$(RESET)"; \
		./$$test_exe; \
		echo ""; \
	done
	@echo "$(YELLOW)==========================================$(RESET)"

# Clean object files (including test object files, though they're not explicitly created anymore)
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS) $(TEST_SRCS:.c=.o) # Test objeleri için de temizleme
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning library and test executables...$(RESET)"
	@$(RM) $(NAME) $(TEST_EXES)
	@echo "$(GREEN)✓ All files cleaned!$(RESET)"

# Rebuild everything
re: fclean all

# Norm check (if you have norminette installed)
norm:
	@echo "$(BLUE)Checking norm...$(RESET)"
	@norminette $(SRCS) $(HEADER) $(TEST_SRCS) | grep -v "OK" || echo "$(GREEN)✓ All files pass norminette!$(RESET)"

# Show help
help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo "  $(YELLOW)all$(RESET)          - Build the library (default)"
	@echo "  $(YELLOW)test$(RESET)         - Build library and all test executables"
	@echo "  $(YELLOW)run-tests$(RESET)    - Run all compiled test executables"
	@echo "  $(YELLOW)clean$(RESET)        - Remove object files"
	@echo "  $(YELLOW)fclean$(RESET)       - Remove all generated files (library and test executables)"
	@echo "  $(YELLOW)re$(RESET)           - Rebuild everything from scratch"
	@echo "  $(YELLOW)norm$(RESET)         - Check code norm with norminette"
	@echo "  $(YELLOW)help$(RESET)         - Show this help message"

# Debug info
debug:
	@echo "$(BLUE)Debug Information:$(RESET)"
	@echo "Library name: $(NAME)"
	@echo "Compiler: $(CC)"
	@echo "Flags: $(CFLAGS)"
	@echo "Library Sources: $(words $(SRCS)) files"
	@echo "Library Objects: $(words $(OBJS)) files"
	@echo "Test Sources: $(words $(TEST_SRCS)) files"
	@echo "Test Executables: $(words $(TEST_EXES)) files"

# Show source files
show-files:
	@echo "$(BLUE)Library Source files:$(RESET)"
	@for file in $(SRCS); do echo "  $(YELLOW)$$file$(RESET)"; done
	@echo "$(BLUE)Test Source files:$(RESET)"
	@for file in $(TEST_SRCS); do echo "  $(YELLOW)$$file$(RESET)"; done

# Phony targets
.PHONY: all clean fclean re test run-tests norm help debug show-files

# Silent mode - suppress command echoing
.SILENT: