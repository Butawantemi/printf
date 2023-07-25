#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function with support for %c, %s, and %%
 * @format: The format string containing conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...);

int main() {
    _printf("Hello %s! This is a character: %c and this is percent sign: %%\n", "John", 'A');
    return 0;
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    char c;
    const char *str;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move to the next character after '%'

            // Check the conversion specifier
            switch (*format) {
                case 'c':
                    c = (char)va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                case 's':
                    str = va_arg(args, const char*);
                    while (*str) {
                        putchar(*str);
                        str++;
                        printed_chars++;
                    }
                    break;
                case '%':
                    putchar('%');
                    printed_chars++;
                    break;
                default:
                    // Unsupported conversion specifier, skip it
                    break;
            }
        } else {
            putchar(*format);
            printed_chars++;
        }

        format++; // Move to the next character in the format string
    }

    va_end(args);
    return printed_chars;
}

