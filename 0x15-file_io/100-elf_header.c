#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(98);
}

int main(int argc, char **argv)
{
    int fd, i, read_bytes;
    Elf64_Ehdr header;

    if (argc != 2)
        print_error("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        print_error("Error: cannot open file");

    read_bytes = read(fd, &header, sizeof(header));
    if (read_bytes == -1)
        print_error("Error: cannot read ELF header");

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
        print_error("Error: not an ELF file");

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", header.e_ident[i], i == EI_NIDENT-1 ? '\n' : ' ');

    printf("  Class:                             %s\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        default: printf("<unknown: %d>\n", header.e_ident[EI_OSABI]); break;
    }

    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header.e_type)
    {
        case ET_NONE: printf("NONE (Unknown type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        default: printf("<unknown: %d>\n", header.e_type); break;
    }

    printf("  Entry point address:               %lx\n", (unsigned long)header.e_entry);

    return 0;
}

