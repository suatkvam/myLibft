# Library name
NAME = libft.a

# Test executable name
TEST_NAME = test_libft

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Header file
HEADER = libft.h

# Source files - exactly matching your file list
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
       ft_toupper.c

# Object files
OBJS = $(SRCS:.c=.o)

# Test source file
TEST_SRC = test_libft.c

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

# Compile source files to object files
%.o: %.c $(HEADER)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Build and run tests
test: $(NAME) $(TEST_SRC)
	@echo "$(BLUE)Compiling test file...$(RESET)"
	@$(CC) $(CFLAGS) $(TEST_SRC) -L. -lft -o $(TEST_NAME)
	@echo "$(GREEN)✓ Test compiled successfully!$(RESET)"
	@echo "$(BLUE)Running tests...$(RESET)"
	@echo "$(YELLOW)==========================================$(RESET)"
	@./$(TEST_NAME)
	@echo "$(YELLOW)==========================================$(RESET)"

# Just compile the test without running
compile-test: $(NAME) $(TEST_SRC)
	@echo "$(BLUE)Compiling test file...$(RESET)"
	@$(CC) $(CFLAGS) $(TEST_SRC) -L. -lft -o $(TEST_NAME)
	@echo "$(GREEN)✓ Test compiled successfully!$(RESET)"
	@echo "$(YELLOW)Run './$(TEST_NAME)' to execute tests$(RESET)"

# Run tests (assumes test is already compiled)
run-test: $(TEST_NAME)
	@echo "$(BLUE)Running tests...$(RESET)"
	@echo "$(YELLOW)==========================================$(RESET)"
	@./$(TEST_NAME)
	@echo "$(YELLOW)==========================================$(RESET)"

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning library and test files...$(RESET)"
	@$(RM) $(NAME) $(TEST_NAME)
	@echo "$(GREEN)✓ All files cleaned!$(RESET)"

# Rebuild everything
re: fclean all

# Norm check (if you have norminette installed)
norm:
	@echo "$(BLUE)Checking norm...$(RESET)"
	@norminette $(SRCS) $(HEADER) | grep -v "OK" || echo "$(GREEN)✓ All files pass norminette!$(RESET)"

# Show help
help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo "  $(YELLOW)all$(RESET)          - Build the library (default)"
	@echo "  $(YELLOW)test$(RESET)         - Build library, compile test, and run tests"
	@echo "  $(YELLOW)compile-test$(RESET) - Build library and compile test (don't run)"
	@echo "  $(YELLOW)run-test$(RESET)     - Run tests (assumes test is compiled)"
	@echo "  $(YELLOW)clean$(RESET)        - Remove object files"
	@echo "  $(YELLOW)fclean$(RESET)       - Remove all generated files"
	@echo "  $(YELLOW)re$(RESET)           - Rebuild everything from scratch"
	@echo "  $(YELLOW)norm$(RESET)         - Check code norm with norminette"
	@echo "  $(YELLOW)help$(RESET)         - Show this help message"

# Debug info
debug:
	@echo "$(BLUE)Debug Information:$(RESET)"
	@echo "Library name: $(NAME)"
	@echo "Test name: $(TEST_NAME)"
	@echo "Compiler: $(CC)"
	@echo "Flags: $(CFLAGS)"
	@echo "Sources: $(words $(SRCS)) files"
	@echo "Objects: $(words $(OBJS)) files"

# Show source files
show-files:
	@echo "$(BLUE)Source files in this project:$(RESET)"
	@for file in $(SRCS); do echo "  $(YELLOW)$$file$(RESET)"; done

# Phony targets
.PHONY: all clean fclean re test compile-test run-test norm help debug show-files

# Silent mode - suppress command echoing
.SILENT: