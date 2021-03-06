/*
 * simtria - generate uniform simple triangulations
 *
 *
	Copyright (C) 2021 Benedikt Stufler

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


// needed to retrieve the number of cpu cores
#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#else
	#include <unistd.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include <pthread.h>
#include <inttypes.h>
#include <string.h>

#include <argp.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <mpfr.h>



/*
 * define data types and format strings for floats and large integers
 * keep in mind that the data type int may occupy only 32bit on 64bit machines
 *
 * DOUBLE: the data type used for storing probabilities
 * PREC: precision (in number of bits) used for intermediate floating point
 *       calculations
 * INT: the data type that needs to be able to store the NUMBER of vertices
 * INTD: the data type that needs to be able to store the sum of distances
 *	   from a single vertex to the rest
 */

#define DOUBLE long double
#define FDOUBLE 17.17Lf

#define INT unsigned long int
#define FINT lu

#define INTD unsigned long long
#define FINTD llu

#define PREC 1024

/* in order to use the format strings we need some macros 
 *
 * example code: 
 *
 * INTD largenum = 1099511627776;
 * printf("%" STR(FINTD) "\n", largenum);
 *
 */

// put quotes around argument
#define STR_(X) #X
// make sure argument is expanded
#define STR(X) STR_(X)




/*######### io-functions #######*/

/*
 * parses command line options using the argp library
 * sets default values (number of threads to use, random generator seed, ...)
 * performs some sanity checks on the arguments
 */
#include "io/cmdparse.h"


/*######### functions for simulating random objects #######*/

/*
 * provides some offspring distrubtions (for example power laws)
*/
#include "rand/offspringlaws.h"


/*
 * a multi-threaded algorithm to simulate the weighted balls in boxes model
 *
 */
#include "rand/ballsinboxes.h"


/*
 * functions for generating size-constrained Galton-Watson trees
 *
 */
#include "rand/sgwtree.h"


/*
 * simulate simple triangulations
 */
#include "rand/simtria.h"





int main(int argc, char *argv[]) {
	struct cmdarg comarg;	// holds command line options
	gsl_rng **rgens;	// array of random number generators
	int i;

	/* tests routines for header functions
		unit_test_graph();
	
		return 0;
	*/

	/* read command line options and perform some sanity checks*/
	if(getcmdargs(&comarg, argc, argv)) {
		fprintf(stderr, "Error reading command line options.\n");
		exit(-1);
	}

	/* initialize random number generators; one for each thread */
	rgens = (gsl_rng **) calloc(comarg.threads, sizeof(gsl_rng *));
	if(rgens == NULL) {
		// memory allocation error
		fprintf(stderr, "Memory allocation error in main function.\n");
		exit(-1);
	}
	for(i=0; i<comarg.threads; i++) {
		rgens[i] = gsl_rng_alloc(comarg.randgen);
		// each random generator gets initialized with a unique seed
		gsl_rng_set(rgens[i], comarg.seed + i);
	}


	/* simulate and output random triangulation */
	simtria(&comarg, rgens);
	

	/* clean up */
	for(i=0; i<comarg.threads; i++)
		gsl_rng_free(rgens[i]);
	free(rgens);
	

	return 0;
}


