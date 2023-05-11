#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);



void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}



void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}

	printf("\n");
}


void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


void print_data(unsigned char *e_ident)
{
    const char *data_type = NULL;
    const unsigned char data_val = e_ident[EI_DATA];

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



void print_version(unsigned char *e_ident)
{
    printf("  Version:                           %d", e_ident[EI_VERSION]);

    if (e_ident[EI_VERSION] == EV_CURRENT)
        printf(" (current)\n");
    else
        printf("\n");
}



void print_osabi(unsigned char *e_ident)
{
     printf("  OS/ABI:                            ");

    if (e_ident[EI_OSABI] == ELFOSABI_NONE) {
        printf("UNIX - System V\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_HPUX) {
        printf("UNIX - HP-UX\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD) {
        printf("UNIX - NetBSD\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_LINUX) {
        printf("UNIX - Linux\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS) {
        printf("UNIX - Solaris\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_IRIX) {
        printf("UNIX - IRIX\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD) {
        printf("UNIX - FreeBSD\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_TRU64) {
        printf("UNIX - TRU64\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_ARM) {
        printf("ARM\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE) {
        printf("Standalone App\n");
    } else {
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}



void print_abi(unsigned char *e_ident)
{
	if (e_ident[EI_ABIVERSION] == 0) {
		printf("  ABI Version:                       unspecified\n");
	} else {
		printf("  ABI Version:                       %d\n",
		       e_ident[EI_ABIVERSION]);
	}
}



void print_type(unsigned int e_type, unsigned char *e_ident)
{
	const char *types[] = {
		"NONE (None)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};

	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	if (e_type >= ET_LOPROC && e_type <= ET_HIPROC) {
		printf("Processor specific: (%x)\n", e_type);
	} else if (e_type >= ET_LOOS && e_type <= ET_HIOS) {
		printf("OS-specific: (%x)\n", e_type);
	} else if (e_type < ET_NUM) {
		printf("Type: %s\n", types[e_type]);
	} else {
		printf("Unknown type (%x)\n", e_type);
	}
}



void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("  Entry point address:               %#lx\n", e_entry);

    if (e_ident[EI_DATA] == ELFDATA2MSB) {
        uint32_t entry32 = (e_entry >> 24) | ((e_entry >> 8) & 0xFF00) |
                           ((e_entry << 8) & 0xFF0000) | (e_entry << 24);
        printf("                                     %#x\n", entry32);
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

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
