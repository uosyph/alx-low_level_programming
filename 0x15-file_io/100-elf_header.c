#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>

#define PAGE_SIZE 4096

#define PERR(msg)
	do
	{
		fprintf(stderr, "Error: %s: %s\n", (msg), strerror(errno));
		exit(98);
	} while (0)

#define ERR(msg, ...)
	do
	{
		fprintf(stderr, "Error: " msg "\n", ##__VA_ARGS__
		exit(98);
	} while (0)

/**
 * check_elf_magic - Checks if the given file has an ELF magic number.
 * @filename: the name of the file.
 * @magic: a pointer to the ELF magic number
 * Return: void.
 */
void check_elf_magic(const char *filename, const uint8_t *magic)
{
	if (memcmp(magic, ELFMAG, SELFMAG) != 0)
	{
		ERR("%s is not an ELF file", filename);
	}
}

/**
 * print_elf_magic - Prints the ELF magic number of the file.
 * @magic: a pointer to the ELF magic number
 * Return: void.
 */
void print_elf_magic(const uint8_t *magic)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", magic[i]);
	}
	printf("\n");
}

/**
 * print_elf_class - Prints the class (32-bit or 64-bit) of the ELF file.
 * @ident: a pointer to the ELF header identification bytes.
 * Return: void.
 */
void print_elf_class(const uint8_t *ident)
{
	printf("  Class:                             ");
	switch (ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}
}

/**
 * print_elf_data - Prints the data encoding (little endian or big endian) of the ELF file.
 * @ident: a pointer to the ELF header identification bytes.
 * Return: void.
 */
void print_elf_data(const uint8_t *ident)
{
	printf("  Data:                              ");
	switch (ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}
}

/**
 * print_elf_version - Prints the version of the ELF file.
 * @ident: a pointer to the ELF header identification bytes.
 * Return: void.
 */
void print_elf_version(const uint8_t *ident)
{
	printf("  Version:                           %d (current)\n", ident[EI_VERSION]);
}

/**
 * print_elf_osabi - Prints the operating system and ABI
 * (application binary interface) of the ELF file.
 * @ident: a pointer to the ELF header identification bytes.
 * Return: void.
 */
void print_elf_osabi(const uint8_t *ident)
{
	printf("  OS/ABI:                            ");
	switch (ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}
}

/**
 * print_elf_abiversion - Prints the ABI version of the ELF file.
 * @ident: a pointer to the ELF header identification bytes.
 * Return: void.
 */
void print_elf_abiversion(const uint8_t *ident)
{
	printf("  ABI Version:                       %d\n", ident[EI_ABIVERSION]);
}

/**
 * print_elf_type - Prints the type of the ELF file
 * (none, relocatable, executable, shared object, or core).
 * @type: the type of the ELF file.
 * Return: void.
 */
void print_elf_type(Elf64_Half type)
{
	printf("  Type:                              ");
	switch (type)
	{
	case ET_NONE:
		printf("None (Unknown type)\n");
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
		printf("Unknown\n");
		break;
	}
}

/**
 * print_elf_entry - Prints the entry point address of the ELF file.
 * @entry: the entry point address of the ELF file.
 * Return: void.
 */
void print_elf_entry(Elf64_Addr entry)
{
	printf("  Entry point address:               0x%lx\n", entry);
}

/**
 * print_elf_header - Prints all the important information from
 * the ELF header of the given file.
 * @filename: the name of the file.
 * @header: a pointer to the ELF header.
 * Return: void.
 */
void print_elf_header(const char *filename, const Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	print_elf_magic(header->e_ident);
	print_elf_class(header->e_ident);
	print_elf_data(header->e_ident);
	print_elf_version(header->e_ident);
	print_elf_osabi(header->e_ident);
	print_elf_abiversion(header->e_ident);
	print_elf_type(header->e_type);
	print_elf_entry(header->e_entry);
}

/**
 * print_usage - Prints the usage information for the program.
 * @program_name: the name of the program.
 * Return: void.
 */
void print_usage(const char *program_name)
{
	printf("Usage: %s elf_filename\n", program_name);
}

/**
 * main - The main function of the program that reads
 * an ELF file and prints its header information.
 * @argc: the number of command-line arguments.
 * @argv: an array of strings representing the command-line arguments.
 * Return: 0 if successful, non-zero if there was an error.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_usage(argv[0]);
		return 1;
	}

	scss
		Copy code int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		PERR("open");
	}

	struct stat sb;
	if (fstat(fd, &sb) == -1)
	{
		PERR("fstat");
	}

	if (!S_ISREG(sb.st_mode))
	{
		ERR("%s is not a regular file", argv[1]);
	}

	if (sb.st_size < sizeof(Elf64_Ehdr))
	{
		ERR("%s is not an ELF file", argv[1]);
	}

	uint8_t *file_data = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file_data == MAP_FAILED)
	{
		PERR("mmap");
	}

	Elf64_Ehdr *header = (Elf64_Ehdr *)file_data;

	check_elf_magic(argv[1], header->e_ident);
	print_elf_header(argv[1], header);

	if (munmap(file_data, sb.st_size) == -1)
	{
		PERR("munmap");
	}

	if (close(fd) == -1)
	{
		PERR("close");
	}

	return 0;
}
