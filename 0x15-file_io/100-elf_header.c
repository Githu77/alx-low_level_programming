#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <elf.h>

int main(int argc, char *argv[]) {

	int fd = open(argv[1], O_RDONLY);
	Elf64_Ehdr header;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }


    if (fd == -1) {
        fprintf(stderr, "Error: cannot open file '%s': %s\n", argv[1], strerror(errno));
        return 98;
    }


    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        fprintf(stderr, "Error: cannot read ELF header: %s\n", strerror(errno));
        close(fd);
        return 98;
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: '%s' is not an ELF file\n", argv[1]);
        close(fd);
        return 98;
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < SELFMAG; i++)
    {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD"); break;
        default: printf("UNIX - unknown");
    }
    printf("\n");
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header.e_type) {
        case ET_NONE: printf("NONE (No file type)"); break;
        case ET_REL: printf("REL (Relocatable file)"); break;
        case ET_EXEC: printf("EXEC (Executable file)"); break;
        case ET_DYN: printf("DYN (Shared object file)"); break;
        default: printf("unknown");
    }
    printf("\n");
    printf("  Entry point address:               0x%lx\n", header.e_entry);

    close(fd);
    return 0;
}

