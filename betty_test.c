#include "shell.h"
/**
 * betty_test - A function to test the Betty style checker
 *
 * return: void
 */
void betty_test(void)
{
char *str = "passe betty checker\n";
write(2, str, sizeof(str) - 1);
}

