#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <elf.h>

/**
*print_error - prints error
*@message: error message
*
*
*
*
*/

void print_error(const char *message) {
fprintf(stderr, "Error: %s\n", message);
exit(98);
}

/**
*print_elf_header - prints elf header
*@Elf64_Ehdr:
*@header: pointer to header
*
*
*
*
*/

void print_elf_header(const Elf64_Ehdr *header) {
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", header->e_ident[i]);
}
printf("\n");
printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "unknown");
printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI:                            ");
switch (header->e_ident[EI_OSABI]) {
case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
default: printf("unknown\n"); break;
}
printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
printf("  Type:                              ");
switch (header->e_type) {
case ET_NONE: printf("NONE (No file type)\n"); break;
case ET_REL: printf("REL (Relocatable file)\n"); break;
case ET_EXEC: printf("EXEC (Executable file)\n"); break;
case ET_DYN: printf("DYN (Shared object file)\n"); break;
case ET_CORE: printf("CORE (Core file)\n"); break;
default: printf("unknown\n"); break;
}
printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
*main - main function
*@argc: arguments number
*@argv: arguments
*
*
*
*
*
*/

int main(int argc, char** argv) {
int fd = open(argv[1], O_RDONLY);
Elf64_Ehdr header;
ssize_t bytes_read = read(fd, &header, sizeof(header));

if (argc != 2) {
print_error("usage: elf_header elf_filename");
}


if (fd == -1) {
print_error(strerror(errno));
}



if (bytes_read != sizeof(header)) {
close(fd);
print_error(strerror(errno));
}

if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
close(fd);
print_error("not an ELF file");
}

print_elf_header(&header);

close(fd);
return 0;
}

