#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_elf(unsigned char *in);
void print_elf_magic(unsigned char *in);
void print_elf_class(unsigned char *in);
void print_elf_data(unsigned char *in);
void print_elf_version(unsigned char *in);
void print_elf_osabi(unsigned char *in);
void print_elf_abi(unsigned char *in);
void print_elf_type(unsigned int e_type, unsigned char *in);
void print_elf_entry(unsigned long int en, unsigned char *in);
void close_elf(int elf);


void scan_elf(unsigned char *in)
{
    const unsigned char magic[] = {0x7f, 'E', 'L', 'F'};

    if (memcmp(in, magic, sizeof(magic)) != 0) {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        exit(98);
    }
}



void print_elf_magic(unsigned char *in)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", in[i]);
	}

	printf("\n");
}


void print_elf_class(unsigned char *in)
{
	printf("  Class:                             ");

	switch (in[EI_CLASS])
	{
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
		printf("<unknown: %x>\n", in[EI_CLASS]);
	}
}


void print_elf_data(unsigned char *in)
{
    const char *data_type = NULL;
    const unsigned char data_val = in[EI_DATA];

    if (data_val == ELFDATANONE)
        data_type = "none";
    else if (data_val == ELFDATA2LSB)
        data_type = "2's complement, little endian";
    else if (data_val == ELFDATA2MSB)
        data_type = "2's complement, big endian";
    else
        printf("<unknown: %x>\n", data_val);

    if (data_type)
        printf("  Data:                              %s\n", data_type);
}



void print_elf_version(unsigned char *in)
{
    printf("  Version:                           %d", in[EI_VERSION]);

    if (in[EI_VERSION] == EV_CURRENT)
        printf(" (current)\n");
    else
        printf("\n");
}



void print_elf_osabi(unsigned char *in)
{
    printf("  OS/ABI:                            ");

    if (in[EI_OSABI] == ELFOSABI_NONE) {
        printf("UNIX - System V\n");
    } else if (in[EI_OSABI] == ELFOSABI_HPUX) {
        printf("UNIX - HP-UX\n");
    } else if (in[EI_OSABI] == ELFOSABI_NETBSD) {
        printf("UNIX - NetBSD\n");
    } else if (in[EI_OSABI] == ELFOSABI_LINUX) {
        printf("UNIX - Linux\n");
    } else if (in[EI_OSABI] == ELFOSABI_SOLARIS) {
        printf("UNIX - Solaris\n");
    } else if (in[EI_OSABI] == ELFOSABI_IRIX) {
        printf("UNIX - IRIX\n");
    } else if (in[EI_OSABI] == ELFOSABI_FREEBSD) {
        printf("UNIX - FreeBSD\n");
    } else if (in[EI_OSABI] == ELFOSABI_TRU64) {
        printf("UNIX - TRU64\n");
    } else if (in[EI_OSABI] == ELFOSABI_ARM) {
        printf("ARM\n");
    } else if (in[EI_OSABI] == ELFOSABI_STANDALONE) {
        printf("Standalone App\n");
    } else {
        printf("<unknown: %x>\n", in[EI_OSABI]);
    }
}



void print_elf_abi(unsigned char *in)
{
	if (in[EI_ABIVERSION] == 0) {
		printf("  ABI Version:                       unspecified\n");
	} else {
		printf("  ABI Version:                       %d\n",
		       in[EI_ABIVERSION]);
	}
}



void print_elf_type(unsigned int et, unsigned char *in)
{
	const char *types[] = {
		"NONE (None)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};

	if (in[EI_DATA] == ELFDATA2MSB)
		et >>= 8;

	if (et >= ET_LOPROC && et <= ET_HIPROC) {
		printf("Processor specific: (%x)\n", et);
	} else if (et >= ET_LOOS && et <= ET_HIOS) {
		printf("OS-specific: (%x)\n", et);
	} else if (et < ET_NUM) {
		printf("Type: %s\n", types[et]);
	} else {
		printf("Unknown type (%x)\n", et);
	}
}



void print_elf_entry(unsigned long int en, unsigned char *in)
{
    printf("  Entry point address:               %#lx\n", en);

    if (in[EI_DATA] == ELFDATA2MSB) {
        uint32_t en32 = (en >> 24) | ((en >> 8) & 0xFF00) |
                           ((en << 8) & 0xFF0000) | (en << 24);
        printf("                                     %#x\n", en32);
    }
}



void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        perror("Error closing file descriptor");
        exit(EXIT_FAILURE);
    }

    printf("File descriptor %d closed successfully.\n", elf);
}



int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	scan_elf(header->e_ident);
	printf("ELF Header:\n");
	print_elf_magic(header->e_ident);
	print_elf_class(header->e_ident);
	print_elf_data(header->e_ident);
	print_elf_version(header->e_ident);
	print_elf_osabi(header->e_ident);
	print_elf_abi(header->e_ident);
	print_elf_type(header->e_type, header->e_ident);
	print_elf_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
