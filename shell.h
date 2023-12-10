#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

void display_prompt (void);
void nhlanhla_print (const char *note);
void read_format (char *format, size_t size);
void execute_command (const char *command);

#endif
