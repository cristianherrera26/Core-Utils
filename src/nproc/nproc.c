/*
 * Copyright (c) 2026, cristianherrera26
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void usage(void);

int
main(int argc, char *argv[])
{
	int c, all = 0;
	long ncpu = 0;
	while ((c = getopt(argc, argv, "a")) != -1) {
		switch (c) {
		case 'a':
			all = 1;
			break;
		default:
			usage();
		}
	}

	if (argc != optind)
		usage();

	/* If the -a option has been specified use _SC_NPROCESSORS_CONF otherwise use */
	/* _SC_NPROCESSORS_ONLN, then check if ncpu is less than 0 and set ncpu equal to 1 */
	if ((ncpu = (all) ? sysconf(_SC_NPROCESSORS_CONF) : sysconf(_SC_NPROCESSORS_ONLN)) < 0)
		ncpu = 1;

	printf("%ld\n", ncpu);
	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: %s [-a]\n", getprogname());
	exit(EXIT_FAILURE);
}
