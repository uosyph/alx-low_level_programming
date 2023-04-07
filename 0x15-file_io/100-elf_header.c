#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *p_elf);
void print_magic(unsigned char *p_elf);
void print_class(unsigned char *p_elf);
void print_data(unsigned char *p_elf);
void print_version(unsigned char *p_elf);
void print_abi(unsigned char *p_elf);
void print_osabi(unsigned char *p_elf);
void print_type(unsigned int elf_type, unsigned char *p_elf);
void print_entry(unsigned long int elf_entry, unsigned char *p_elf);
void close_elf(int elf);

/**
 * check_elf - Checks if the file is an ELF file.
 * @p_elf: a pointer of an array containing the ELF magic numbers.
 * Return: void.
 */
void check_elf(unsigned char *p_elf)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (p_elf[i] != 127 &&
			p_elf[i] != 'E' &&
			p_elf[i] != 'L' &&
			p_elf[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @p_elf: a pointer of an array containing the ELF magic numbers.
 * Return: void.
 */
void print_magic(unsigned char *p_elf)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", p_elf[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class of an ELF header.
 * @p_elf: a pointer of an array containing the ELF class.
 * Return: void.
 */
void print_class(unsigned char *p_elf)
{
	printf("  Class:                             ");

	switch (p_elf[EI_CLASS])
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
		printf("<unknown: %x>\n", p_elf[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data of an ELF header.
 * @p_elf: a pointer to an array containing the ELF class.
 * Return: void.
 */
void print_data(unsigned char *p_elf)
{
	printf("  Data:                              ");

	switch (p_elf[EI_DATA])
	{
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
		printf("<unknown: %x>\n", p_elf[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version of an ELF header.
 * @p_elf: a pointer to an array containing the ELF version.
 * Return: void.
 */
void print_version(unsigned char *p_elf)
{
	printf("  Version:                           %d",
		   p_elf[EI_VERSION]);

	switch (p_elf[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints the OS (Operating System)
 * /ABI (Application Binary Interface) of an ELF header.
 * @p_elf: A pointer to an array containing the ELF version.
 * Return: void.
 */
void print_osabi(unsigned char *p_elf)
{
	printf("  OS/ABI:                            ");

	switch (p_elf[EI_OSABI])
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
		printf("<unknown: %x>\n", p_elf[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI (Application Binary Interface)
 * version of an ELF header.
 * @p_elf: A pointer to an array containing the ELF ABI version.
 * Return: void.
 */
void print_abi(unsigned char *p_elf)
{
	printf("  ABI Version:                       %d\n",
		   p_elf[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @elf_type: the ELF type.
 * @p_elf: a pointer of an array containing the ELF class.
 * Return: void.
 */
void print_type(unsigned int elf_type, unsigned char *p_elf)
{
	if (p_elf[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type:                              ");

	switch (elf_type)
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
		printf("<unknown: %x>\n", elf_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @elf_entry: the address of the ELF entry point.
 * @p_elf: a pointer of an array containing the ELF class.
 * Return: void.
 */
void print_entry(unsigned long int elf_entry, unsigned char *p_elf)
{
	printf("  Entry point address:               ");

	if (p_elf[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
				  ((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (p_elf[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: the file descriptor of the ELF file.
 * Return: if file can't be closed exit code (98).
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
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: the number of arguments supplied to the program.
 * @argv: an array of pointers to the arguments.
 * Return: 0 on success, 98 if failed or
 * file is not an ELF file.
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

	check_elf(header->p_elf);
	printf("ELF Header:\n");
	print_magic(header->p_elf);
	print_class(header->p_elf);
	print_data(header->p_elf);
	print_version(header->p_elf);
	print_osabi(header->p_elf);
	print_abi(header->p_elf);
	print_type(header->elf_type, header->p_elf);
	print_entry(header->elf_entry, header->p_elf);

	free(header);
	close_elf(o);

	return (0);
}
