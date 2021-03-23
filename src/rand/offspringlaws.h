/*
 * We provide some offspring distributions for our simulations
 */

/*
 * Provides a triangulation type offspring law
 *		xi[i] = const * (i+1) * (i+2) * (1/4)**i
 */
mpfr_t *xitria(INT n) {
	mpfr_t *xi;
	INT i;
	mpfr_t norm, mpi, con1, con2, base, ip1, ip2, fac1, fac2;

	// initialize (warning: mpfr sets to NaN, gmp sets to 0.0)
	mpfr_init2(norm, PREC);
	mpfr_init2(mpi, PREC);
	mpfr_init2(con1, PREC);
	mpfr_init2(con2, PREC);
	mpfr_init2(base, PREC);
	mpfr_init2(ip1, PREC);
	mpfr_init2(ip2, PREC);
	mpfr_init2(fac1, PREC);
	mpfr_init2(fac2, PREC);

	xi = (mpfr_t *) calloc(n, sizeof(mpfr_t));
	if(xi == NULL) {
		// memory allocation error
		fprintf(stderr, "Memory allocation error in function xitria\n");
		exit(-1);
	}
	for(i=0; i<n; i++)
		mpfr_init2(xi[i], PREC);

	/*
	for(i=0; i<n; i++) {
		xi[i] = (i+1) * (i+2) * (1/4)**i
	}
	*/
	mpfr_set_ld(con1, 1.0, MPFR_RNDN);
	mpfr_set_ld(con2, 2.0, MPFR_RNDN);
	mpfr_set_ld(base, 0.25, MPFR_RNDN);

	mpfr_set_ld(xi[0], 2.0, MPFR_RNDN);
	for(i=1; i<n; i++) {
		mpfr_set_ui(mpi, i, MPFR_RNDN);
		mpfr_add(ip1, mpi, con1, MPFR_RNDN);
		mpfr_add(ip2, mpi, con2, MPFR_RNDN);
		mpfr_mul(fac1, ip1, ip2, MPFR_RNDN); 
		mpfr_pow(fac2, base, mpi, MPFR_RNDN);
		mpfr_mul(xi[i], fac1, fac2, MPFR_RNDN); 
	}

	// normalize 
	/*
	for(i=0, norm=0.0; i<n; i++)
		norm += xi[i];
	for(i=0; i<n; i++)
		xi[i] /= norm;
	*/

	mpfr_set_ld(norm, 0.0, MPFR_RNDN);	
	for(i=0; i<n; i++)
		mpfr_add(norm, norm, xi[i], MPFR_RNDN);

	for(i=0; i<n; i++)
		mpfr_div(xi[i], xi[i], norm, MPFR_RNDN);

	//DEBUG
	/*
	DOUBLE tmp;
	for(i=0; i<n; i++) {
		tmp = mpfr_get_ld(xi[i], MPFR_RNDN);
		printf("p[%" STR(FINT) "] = %" STR(FDOUBLE) "\n", i, tmp);
	}
	*/
	

	// clean up
	mpfr_clear(norm);
	mpfr_clear(mpi);
	mpfr_clear(con1);
	mpfr_clear(con2);
	mpfr_clear(base);
	mpfr_clear(ip1);
	mpfr_clear(ip2);
	mpfr_clear(fac1);
	mpfr_clear(fac2);


	return xi;
}



