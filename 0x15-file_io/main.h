#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);

#endif
