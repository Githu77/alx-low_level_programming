#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int fd, i;
    ssize_t nread;
    char buf[BUF_SIZE];
    Elf64_Ehdr *ehdr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 98;
    }

    nread = read(fd, buf, BUF_SIZE);
    if (nread == -1) {
        perror("read");
        return 98;
    }

    ehdr = (Elf64_Ehdr *) buf;
    if (ehdr->e_ident[EI_MAG0] != ELFMAG0 || ehdr->e_ident[EI_MAG1] != ELFMAG1
        || ehdr->e_ident[EI_MAG2] != ELFMAG2 || ehdr->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "%s is not an ELF file\n", argv[1]);
        return 98;
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", ehdr->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

    printf("  Class:                             %s\n", ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "unknown");
    printf("  Version:                           %d (current)\n", ehdr->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", ehdr->e_ident[EI_OSABI] == 0 ? "UNIX - System V" : "unknown");
    printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", ehdr->e_type == ET_EXEC ? "EXEC (Executable file)" :
           (ehdr->e_type == ET_DYN ? "DYN (Shared object file)" :
           (ehdr->e_type == ET_REL ? "REL (Relocatable file)" : "unknown")));
    printf("  Entry point address:               0x%lx\n", (unsigned long) ehdr->e_entry);

    close(fd);

    return 0;
}

