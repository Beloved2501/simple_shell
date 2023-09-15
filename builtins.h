#ifndef BUILTINS_H
#define BUILTINS_H

#include "general.h"
#include "text.h"
#include "memory.h"
#include "commands.h"

/* builtins.c */
int builtins(general_t *info, char **arguments);
int check_builtin(general_t *info, char **arguments);

/* env.c */
void bin_env(general_t *info, char **arguments);

/* echo.c */
void echo_printer(int index, char *text, char **arguments);
void bin_echo(general_t *info, char **arguments);

/* exit.c */
int number_controller(general_t *info, char *number);
void bin_exit(general_t *info, char **arguments);

#endif
