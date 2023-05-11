#include "main.h"

/**
*check_elf - Checks for ELF.
*@e_ident: pointer to EFL magic numbers
*
*
*
*
*
*
*/
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

/**
*print_elf_magic - writes magic numbers
*@e_ident: pointer to magic numbers
*
*
*
*
*
*
*
*/

void print_elf_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
*print_elf_class - writes ELF's class
*@e_ident: pointer to class
*
*
*
*
*
*
*
*/

void print_elf_class(unsigned char *e_ident)
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

/**
*print_elf_data - writes the ELF's data
*@e_ident: pointer to data
*
*
*
*
*
*
*
*/

void print_elf_data(unsigned char *e_ident)
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
	printf("  Data:                              %s\n",		data_type);

}

/**
*print_elf_version - writes the ELF's version
*@e_ident: pointer to version data
*
*
*
*
*
*
*
*/
void print_elf_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
	printf(" (current)\n");
	else
	printf("\n");
}

/**
*print_elf_osabi - writes the ELF's ABI/OS data
*@e_ident: pointer to data
*
*
*
*
*
*
*
*/
void print_elf_osabi(unsigned char *e_ident)
{
	 printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
*print_elf_abi - writes the ELF's ABI versionata
*@e_ident: pointer to data
*
*
*
*
*
*
*
*/
void print_elf_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
*print_elf_type - writes the ELF's type
*@e_ident: pointer to data
*@e_type: ELF type
*
*
*
*
*
*
*/
void print_elf_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
*print_elf_entry - writes the ELF's entry
*@e_entry: address to ELF entry
*@e_ident: pointer to data
*
*
*
*
*
*
*
*/
void print_elf_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
*close_elf - closes ELF
*@elf: ELF description
*
*
*
*
*
*
*
*/
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
*main - main function
*@argc: number of arguments
*@argv: array of arguments
*Return: 0
*
*
*
*
*
*/
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
