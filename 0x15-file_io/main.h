#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <elf.h>


int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char **argv);
void print_error(char *message, char *filename, int fd_from, int fd_to);
void check_elf(unsigned char *e_ident);
void print_elf_magic(unsigned char *e_ident);
void print_elf_class(unsigned char *e_ident);
void print_elf_data(unsigned char *e_ident);
void print_elf_version(unsigned char *e_ident);
void print_elf_abi(unsigned char *e_ident);
void print_elf_osabi(unsigned char *e_ident);
void print_elf_type(unsigned int e_type, unsigned char *e_ident);
void print_elf_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

#endif
