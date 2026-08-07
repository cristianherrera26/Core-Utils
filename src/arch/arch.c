#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

static void usage(void);

int
main(int argc, char *argv[])
{
	int c;
	const char *print = NULL;
	while ((c = getopt(argc, argv, "km")) != -1) {
		switch (c) {
		case 'k':
			print = MACHINE_ARCH;
			break;
		case 'm':	/* -m (machine): MACHINE is the default */
			break;
		default:
			usage();
		}
	}

	argc -= optind;
	argv += optind;

	if (print == NULL)
		print = MACHINE;

	if (argc > 1)
		usage();

	if (argc == 0) {
		puts(print);
	} else {
		if (strcmp(argv[0], print))
			return 1;
	}

	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: %s [-km] [archname]\n", getprogname());
	exit(1);
}
