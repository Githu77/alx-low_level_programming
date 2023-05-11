#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <elf.h>
#include <string.h>


int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char **argv);
void print_error(char *message, char *filename, int fd_from, int fd_to);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_ident[EI_NIDENT]);
void print_version(unsigned char e_ident[EI_NIDENT]);
void print_data(unsigned char e_ident[EI_NIDENT]);
void print_osabi(unsigned char e_ident[EI_NIDENT]);
void print_abiver(unsigned char e_ident[EI_NIDENT]);
void print_type(Elf64_Half e_type);
void print_entry(Elf64_Addr e_entry);
int main(int argc, char **argv);

#endif
