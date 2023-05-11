#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUFFER_SIZE 1024

void display_error(const char *filename, const char *message)
{
fprintf(stderr, "%s: %s\n", filename, message);
exit(98);
}

void display_elf_header(const Elf64_Ehdr *header)
{
int i;
printf("ELF Header:\n");
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", header->e_ident[i]);
}
printf("\n");
printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "unknown");
printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI:                            ");
switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
default:
printf("unknown\n");
}
printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
printf("  Type:                              ");
switch (header->e_type)
{
case ET_NONE:
printf("NONE (Unknown type)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("unknown\n");
}
printf("  Entry point address:               0x%x\n", (unsigned int) header->e_entry);
}

int main(int argc, char **argv)
{
int fd = open(argv[1], O_RDONLY);
Elf64_Ehdr header;

if (argc != 2)
{
display_error(argv[0], "Usage: elf_header elf_filename");
}


if (fd == -1)
{
display_error(argv[1], "Cannot open file");
}


if (read(fd, &header, sizeof(header)) != sizeof(header))
{
display_error(argv[1], "Cannot read ELF header");
}

if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
{
display_error(argv[1], "Not an ELF file");
}

display_elf_header(&header);

close(fd);
return 0;
}

