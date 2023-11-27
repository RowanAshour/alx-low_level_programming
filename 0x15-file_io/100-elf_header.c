#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * get_file_type - Returns a string describing the ELF file type.
 * @e_type: The ELF file type.
 *
 * Return: A string describing the file type.
 */
const char *get_file_type(uint16_t e_type)
{
	switch (e_type)
	{
		case ET_REL: return "REL (Relocatable file)";
		case ET_EXEC: return "EXEC (Executable file)";
		case ET_DYN: return "DYN (Shared object file)";
		case ET_CORE: return "CORE (Core file)";
		default: return "UNKNOWN (Unknown type)";
	}
}

/**
 * main - Entry point for the ELF header program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		return 98;
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 98;
	}

	unsigned char magic[4];
	if (read(fd, magic, 4) != 4)
	{
		perror("Error reading file");
		return 98;
	}

	if (magic[0] != 0x7f || magic[1] != 'E' || magic[2] != 'L' || magic[3] != 'F')
	{
		fprintf(stderr, "Not an ELF file\n");
		return 98;
	}

	lseek(fd, 0, SEEK_SET);
	Elf64_Ehdr header;
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error reading ELF header");
		return 98;
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             ");
	printf(header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32\n" : "ELF64\n");

	printf("  Data:                              ");
	printf(header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian\n" : "2's complement, big endian\n");

	printf("  Version:                           ");
	printf("%d (current)\n", header.e_version);

	printf("  OS/ABI:                            ");
	printf(header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V\n" : "<unknown>\n");

	printf("  ABI Version:                       ");
	printf("%d\n", header.e_ident[EI_ABIVER]);

	printf("  Type:                              ");
	printf("%s\n", get_file_type(header.e_type));

	printf("  Entry point address:               ");
	printf("0x%lx\n", (unsigned long)header.e_entry);

	close(fd);
	return 0;
}

