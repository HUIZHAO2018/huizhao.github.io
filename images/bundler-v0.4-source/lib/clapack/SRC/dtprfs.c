#include "f2c.h"
#include "blaswrap.h"

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b19 = -1.;

/* Subroutine */ int dtprfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, doublereal *ap, doublereal *b, integer *ldb, 
	doublereal *x, integer *ldx, doublereal *ferr, doublereal *berr, 
	doublereal *work, integer *iwork, integer *info)
{
    /* System generated locals */
    integer b_dim1, b_offset, x_dim1, x_offset, i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;

    /* Local variables */
    integer i__, j, k;
    doublereal s;
    integer kc;
    doublereal xk;
    integer nz;
    doublereal eps;
    integer kase;
    doublereal safe1, safe2;
    extern logical lsame_(char *, char *);
    integer isave[3];
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *), daxpy_(integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *), dtpmv_(char *, 
	    char *, char *, integer *, doublereal *, doublereal *, integer *);
    logical upper;
    extern /* Subroutine */ int dtpsv_(char *, char *, char *, integer *, 
	    doublereal *, doublereal *, integer *), 
	    dlacn2_(integer *, doublereal *, doublereal *, integer *, 
	    doublereal *, integer *, integer *);
    extern doublereal dlamch_(char *);
    doublereal safmin;
    extern /* Subroutine */ int xerbla_(char *, integer *);
    logical notran;
    char transt[1];
    logical nounit;
    doublereal lstres;


/*  -- LAPACK routine (version 3.1) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2006 */

/*     Modified to call DLACN2 in place of DLACON, 5 Feb 03, SJH. */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  DTPRFS provides error bounds and backward error estimates for the */
/*  solution to a system of linear equations with a triangular packed */
/*  coefficient matrix. */

/*  The solution matrix X must be computed by DTPTRS or some other */
/*  means before entering this routine.  DTPRFS does not do iterative */
/*  refinement because doing so cannot improve the backward error. */

/*  Arguments */
/*  ========= */

/*  UPLO    (input) CHARACTER*1 */
/*          = 'U':  A is upper triangular; */
/*          = 'L':  A is lower triangular. */

/*  TRANS   (input) CHARACTER*1 */
/*          Specifies the form of the system of equations: */
/*          = 'N':  A * X = B  (No transpose) */
/*          = 'T':  A**T * X = B  (Transpose) */
/*          = 'C':  A**H * X = B  (Conjugate transpose = Transpose) */

/*  DIAG    (input) CHARACTER*1 */
/*          = 'N':  A is non-unit triangular; */
/*          = 'U':  A is unit triangular. */

/*  N       (input) INTEGER */
/*          The order of the matrix A.  N >= 0. */

/*  NRHS    (input) INTEGER */
/*          The number of right hand sides, i.e., the number of columns */
/*          of the matrices B and X.  NRHS >= 0. */

/*  AP      (input) DOUBLE PRECISION array, dimension (N*(N+1)/2) */
/*          The upper or lower triangular matrix A, packed columnwise in */
/*          a linear array.  The j-th column of A is stored in the array */
/*          AP as follows: */
/*          if UPLO = 'U', AP(i + (j-1)*j/2) = A(i,j) for 1<=i<=j; */
/*          if UPLO = 'L', AP(i + (j-1)*(2*n-j)/2) = A(i,j) for j<=i<=n. */
/*          If DIAG = 'U', the diagonal elements of A are not referenced */
/*          and are assumed to be 1. */

/*  B       (input) DOUBLE PRECISION array, dimension (LDB,NRHS) */
/*          The right hand side matrix B. */

/*  LDB     (input) INTEGER */
/*          The leading dimension of the array B.  LDB >= max(1,N). */

/*  X       (input) DOUBLE PRECISION array, dimension (LDX,NRHS) */
/*          The solution matrix X. */

/*  LDX     (input) INTEGER */
/*          The leading dimension of the array X.  LDX >= max(1,N). */

/*  FERR    (output) DOUBLE PRECISION array, dimension (NRHS) */
/*          The estimated forward error bound for each solution vector */
/*          X(j) (the j-th column of the solution matrix X). */
/*          If XTRUE is the true solution corresponding to X(j), FERR(j) */
/*          is an estimated upper bound for the magnitude of the largest */
/*          element in (X(j) - XTRUE) divided by the magnitude of the */
/*          largest element in X(j).  The estimate is as reliable as */
/*          the estimate for RCOND, and is almost always a slight */
/*          overestimate of the true error. */

/*  BERR    (output) DOUBLE PRECISION array, dimension (NRHS) */
/*          The componentwise relative backward error of each solution */
/*          vector X(j) (i.e., the smallest relative change in */
/*          any element of A or B that makes X(j) an exact solution). */

/*  WORK    (workspace) DOUBLE PRECISION array, dimension (3*N) */

/*  IWORK   (workspace) INTEGER array, dimension (N) */

/*  INFO    (output) INTEGER */
/*          = 0:  successful exit */
/*          < 0:  if INFO = -i, the i-th argument had an illegal value */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. Local Arrays .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. Executable Statements .. */

/*     Test the input parameters. */

    /* Parameter adjustments */
    --ap;
    b_dim1 = *ldb;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    x_dim1 = *ldx;
    x_offset = 1 + x_dim1;
    x -= x_offset;
    --ferr;
    --berr;
    --work;
    --iwork;

    /* Function Body */
    *info = 0;
    upper = lsame_(uplo, "U");
    notran = lsame_(trans, "N");
    nounit = lsame_(diag, "N");

    if (! upper && ! lsame_(uplo, "L")) {
	*info = -1;
    } else if (! notran && ! lsame_(trans, "T") && ! 
	    lsame_(trans, "C")) {
	*info = -2;
    } else if (! nounit && ! lsame_(diag, "U")) {
	*info = -3;
    } else if (*n < 0) {
	*info = -4;
    } else if (*nrhs < 0) {
	*info = -5;
    } else if (*ldb < max(1,*n)) {
	*info = -8;
    } else if (*ldx < max(1,*n)) {
	*info = -10;
    }
    if (*info != 0) {
	i__1 = -(*info);
	xerbla_("DTPRFS", &i__1);
	return 0;
    }

/*     Quick return if possible */

    if (*n == 0 || *nrhs == 0) {
	i__1 = *nrhs;
	for (j = 1; j <= i__1; ++j) {
	    ferr[j] = 0.;
	    berr[j] = 0.;
/* L10: */
	}
	return 0;
    }

    if (notran) {
	*(unsigned char *)transt = 'T';
    } else {
	*(unsigned char *)transt = 'N';
    }

/*     NZ = maximum number of nonzero elements in each row of A, plus 1 */

    nz = *n + 1;
    eps = dlamch_("Epsilon");
    safmin = dlamch_("Safe minimum");
    safe1 = nz * safmin;
    safe2 = safe1 / eps;

/*     Do for each right hand side */

    i__1 = *nrhs;
    for (j = 1; j <= i__1; ++j) {

/*        Compute residual R = B - op(A) * X, */
/*        where op(A) = A or A', depending on TRANS. */

	dcopy_(n, &x[j * x_dim1 + 1], &c__1, &work[*n + 1], &c__1);
	dtpmv_(uplo, trans, diag, n, &ap[1], &work[*n + 1], &c__1);
	daxpy_(n, &c_b19, &b[j * b_dim1 + 1], &c__1, &work[*n + 1], &c__1);

/*        Compute componentwise relative backward error from formula */

/*        max(i) ( abs(R(i)) / ( abs(op(A))*abs(X) + abs(B) )(i) ) */

/*        where abs(Z) is the componentwise absolute value of the matrix */
/*        or vector Z.  If the i-th component of the denominator is less */
/*        than SAFE2, then SAFE1 is added to the i-th components of the */
/*        numerator and denominator before dividing. */

	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    work[i__] = (d__1 = b[i__ + j * b_dim1], abs(d__1));
/* L20: */
	}

	if (notran) {

/*           Compute abs(A)*abs(X) + abs(B). */

	    if (upper) {
		kc = 1;
		if (nounit) {
		    i__2 = *n;
		    for (k = 1; k <= i__2; ++k) {
			xk = (d__1 = x[k + j * x_dim1], abs(d__1));
			i__3 = k;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    work[i__] += (d__1 = ap[kc + i__ - 1], abs(d__1)) 
				    * xk;
/* L30: */
			}
			kc += k;
/* L40: */
		    }
		} else {
		    i__2 = *n;
		    for (k = 1; k <= i__2; ++k) {
			xk = (d__1 = x[k + j * x_dim1], abs(d__1));
			i__3 = k - 1;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    work[i__] += (d__1 = ap[kc + i__ - 1], abs(d__1)) 
				    * xk;
/* L50: */
			}
			work[k] += xk;
			kc += k;
/* L60: */
		    }
		}
	    } else {
		kc = 1;
		if (nounit) {
		    i__2 = *n;
		    for (k = 1; k <= i__2; ++k) {
			xk = (d__1 = x[k + j * x_dim1], abs(d__1));
			i__3 = *n;
			for (i__ = k; i__ <= i__3; ++i__) {
			    work[i__] += (d__1 = ap[kc + i__ - k], abs(d__1)) 
				    * xk;
/* L70: */
			}
			kc = kc + *n - k + 1;
/* L80: */
		    }
		} else {
		    i__2 = *n;
		    for (k = 1; k <= i__2; ++k) {
			xk = (d__1 = x[k + j * x_dim1], abs(d__1));
			i__3 = *n;
			for (i__ = k + 1; i__ <= i__3; ++i__) {
			    work[i__] += (d__1 = ap[kc + i__ - k], abs(d__1)) 
				    * xk;
/* L90: */
			}
			work[k] += xk;
			kc = kc + *n - k + 1;
/* L100: */
		    }
		}
	    }
	} else {

/*           Compute abs(A')*abs(X) + abs(B). */

	    if (upper) {
		kc = 1;
		if (nounit) {
		    i__2 = *n;
		    for (k = 1; k <= i__2; ++k) {
			s = 0.;
			i__3 = k;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    s += (d__1 = ap[kc + i__ - 1], abs(d__1)) * (d__2 
				    = x[i__ + j * x_dim1], abs(d__2));
/* L110: */
			}
			work[k] += s;
			kc += k;
/* L120: */
		    }
		} else {
		    i__2 = *n;
		    for (k = 1; k <= i__2; ++k) {
			s = (d__1 = x[k + j * x_dim1], abs(d__1));
			i__3 = k - 1;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    s += (d__1 = ap[kc + i__ - 1], abs(d__1)) * (d__2 
				    = x[i__ + j * x_dim1], abs(d__2));
/* L130: */
			}
			work[k] += s;
			kc += k;
/* L140: */
		    }
		}
	    } else {
		kc = 1;
		if (nounit) {
		    i__2 = *n;
		    for (k = 1; k <= i__2; ++k) {
			s = 0.;
			i__3 = *n;
			for (i__ = k; i__ <= i__3; ++i__) {
			    s += (d__1 = ap[kc + i__ - k], abs(d__1)) * (d__2 
				    = x[i__ + j * x_dim1], abs(d__2));
/* L150: */
			}
			work[k] += s;
			kc = kc + *n - k + 1;
/* L160: */
		    }
		} else {
		    i__2 = *n;
		    for (k = 1; k <= i__2; ++k) {
			s = (d__1 = x[k + j * x_dim1], abs(d__1));
			i__3 = *n;
			for (i__ = k + 1; i__ <= i__3; ++i__) {
			    s += (d__1 = ap[kc + i__ - k], abs(d__1)) * (d__2 
				    = x[i__ + j * x_dim1], abs(d__2));
/* L170: */
			}
			work[k] += s;
			kc = kc + *n - k + 1;
/* L180: */
		    }
		}
	    }
	}
	s = 0.;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (work[i__] > safe2) {
/* Computing MAX */
		d__2 = s, d__3 = (d__1 = work[*n + i__], abs(d__1)) / work[
			i__];
		s = max(d__2,d__3);
	    } else {
/* Computing MAX */
		d__2 = s, d__3 = ((d__1 = work[*n + i__], abs(d__1)) + safe1) 
			/ (work[i__] + safe1);
		s = max(d__2,d__3);
	    }
/* L190: */
	}
	berr[j] = s;

/*        Bound error from formula */

/*        norm(X - XTRUE) / norm(X) .le. FERR = */
/*        norm( abs(inv(op(A)))* */
/*           ( abs(R) + NZ*EPS*( abs(op(A))*abs(X)+abs(B) ))) / norm(X) */

/*        where */
/*          norm(Z) is the magnitude of the largest component of Z */
/*          inv(op(A)) is the inverse of op(A) */
/*          abs(Z) is the componentwise absolute value of the matrix or */
/*             vector Z */
/*          NZ is the maximum number of nonzeros in any row of A, plus 1 */
/*          EPS is machine epsilon */

/*        The i-th component of abs(R)+NZ*EPS*(abs(op(A))*abs(X)+abs(B)) */
/*        is incremented by SAFE1 if the i-th component of */
/*        abs(op(A))*abs(X) + abs(B) is less than SAFE2. */

/*        Use DLACN2 to estimate the infinity-norm of the matrix */
/*           inv(op(A)) * diag(W), */
/*        where W = abs(R) + NZ*EPS*( abs(op(A))*abs(X)+abs(B) ))) */

	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (work[i__] > safe2) {
		work[i__] = (d__1 = work[*n + i__], abs(d__1)) + nz * eps * 
			work[i__];
	    } else {
		work[i__] = (d__1 = work[*n + i__], abs(d__1)) + nz * eps * 
			work[i__] + safe1;
	    }
/* L200: */
	}

	kase = 0;
L210:
	dlacn2_(n, &work[(*n << 1) + 1], &work[*n + 1], &iwork[1], &ferr[j], &
		kase, isave);
	if (kase != 0) {
	    if (kase == 1) {

/*              Multiply by diag(W)*inv(op(A)'). */

		dtpsv_(uplo, transt, diag, n, &ap[1], &work[*n + 1], &c__1);
		i__2 = *n;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    work[*n + i__] = work[i__] * work[*n + i__];
/* L220: */
		}
	    } else {

/*              Multiply by inv(op(A))*diag(W). */

		i__2 = *n;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    work[*n + i__] = work[i__] * work[*n + i__];
/* L230: */
		}
		dtpsv_(uplo, trans, diag, n, &ap[1], &work[*n + 1], &c__1);
	    }
	    goto L210;
	}

/*        Normalize error. */

	lstres = 0.;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* Computing MAX */
	    d__2 = lstres, d__3 = (d__1 = x[i__ + j * x_dim1], abs(d__1));
	    lstres = max(d__2,d__3);
/* L240: */
	}
	if (lstres != 0.) {
	    ferr[j] /= lstres;
	}

/* L250: */
    }

    return 0;

/*     End of DTPRFS */

} /* dtprfs_ */
