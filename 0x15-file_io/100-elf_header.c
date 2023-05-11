#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFFER_SIZE 64

void print_magic(unsigned char *e_ident) {
	 int i;

    printf("  Magic:   ");

    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

void print_class(unsigned char e_ident[EI_NIDENT]) {
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_data(unsigned char e_ident[EI_NIDENT]) {
    printf("  Data:                              ");
    switch (e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

void print_version(unsigned char e_ident[EI_NIDENT]) {
    printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
}

void print_osabi(unsigned char e_ident[EI_NIDENT]) {
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX ABI\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD ABI\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux ABI\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris ABI\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX ABI\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD ABI\n");
            break;
        case ELFOSABI_TRU64:
            printf("TRU64 UNIX ABI\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM architecture ABI\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone (embedded) application\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

void print_abiver(unsigned char e_ident[EI_NIDENT]) {
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

void print_type(Elf64_Half e_type) {
printf(" Type: ");
switch (e_type) {
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
printf("CORE (Core dump)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
}
}

void print_entry(Elf64_Addr e_entry) {
printf(" Entry point address: 0x%lx\n", e_entry);
}

int main(int argc, char **argv) {
int fd = open(argv[1], O_RDONLY);
Elf64_Ehdr header;
ssize_t bytes_read = read(fd, &header, sizeof(header));

if (argc < 2) {
fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
exit(EXIT_FAILURE);
}


if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
}


if (bytes_read != sizeof(header)) {
    fprintf(stderr, "Error: Failed to read ELF header\n");
    exit(EXIT_FAILURE);
}

close(fd);

printf("ELF Header:\n");

print_magic(header.e_ident);
print_class(header.e_ident);
print_data(header.e_ident);
print_version(header.e_ident);
print_osabi(header.e_ident);
print_abiver(header.e_ident);
print_type(header.e_type);
print_entry(header.e_entry);

return EXIT_SUCCESS;
}

