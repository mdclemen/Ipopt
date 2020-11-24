// Copyright (C) 2004, 2006 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// Authors:  Carl Laird, Andreas Waechter     IBM    2004-08-13

#include "IpoptConfig.h"
#include "IpBlas.hpp"
#include "IpTypes.h"

/* we currently have no separate check for Blas, but assume that Blas comes with Lapack
 * thus, we use the nameing convention of Lapack for Blas, too
 */
#ifndef IPOPT_BLAS_FUNC
#define IPOPT_BLAS_FUNC(name,NAME) IPOPT_LAPACK_FUNC(name,NAME)
#endif

#ifdef IPOPT_SINGLE
#define IPOPT_BLAS_FUNCP(name,NAME) IPOPT_BLAS_FUNC(s ## name,S ## NAME)
#else
#define IPOPT_BLAS_FUNCP(name,NAME) IPOPT_BLAS_FUNC(d ## name,D ## NAME)
#endif

#include <cstring>

// Prototypes for the BLAS routines
extern "C"
{
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
   /** BLAS Fortran function SDOT */
   float IPOPT_BLAS_FUNC(sdot, SDOT)(
      ipfint*      n,
      const float* x,
      ipfint*      incX,
      const float* y,
      ipfint*      incY
   );

   /** BLAS Fortran function SNRM2 */
   float IPOPT_BLAS_FUNC(snrm2, SNRM2)(
      ipfint*      n,
      const float* x,
      ipfint*      incX
   );

   /** BLAS Fortran function SASUM */
   float IPOPT_BLAS_FUNC(sasum, SASUM)(
      ipfint*      n,
      const float* x,
      ipfint*      incX
   );

   /** BLAS Fortran function ISAMAX */
   ipfint IPOPT_BLAS_FUNC(isamax, ISAMAX)(
      ipfint*      n,
      const float* x,
      ipfint*      incX
   );

   /** BLAS Fortran subroutine SCOPY */
   void IPOPT_BLAS_FUNC(scopy, SCOPY)(
      ipfint*      n,
      const float* x,
      ipfint*      incX,
      float*       y,
      ipfint*      incY
   );

   /** BLAS Fortran subroutine SAXPY */
   void IPOPT_BLAS_FUNC(saxpy, SAXPY)(
      ipfint*      n,
      const float* alpha,
      const float* x,
      ipfint*      incX,
      float*       y,
      ipfint*      incY
   );

   /** BLAS Fortran subroutine SSCAL */
   void IPOPT_BLAS_FUNC(sscal, SSCAL)(
      ipfint*      n,
      const float* alpha,
      const float* x,
      ipfint*      incX
   );

   /** BLAS Fortran subroutine SGEMV */
   void IPOPT_BLAS_FUNC(sgemv, SGEMV)(
      char*        trans,
      ipfint*      m,
      ipfint*      n,
      const float* alpha,
      const float* a,
      ipfint*      lda,
      const float* x,
      ipfint*      incX,
      const float* beta,
      float*       y,
      ipfint*      incY,
      int          trans_len
   );

   /** BLAS Fortran subroutine SSYMV */
   void IPOPT_BLAS_FUNC(ssymv, SSYMV)(
      char*        uplo,
      ipfint*      n,
      const float* alpha,
      const float* a,
      ipfint*      lda,
      const float* x,
      ipfint*      incX,
      const float* beta,
      float*       y,
      ipfint*      incY,
      int          uplo_len
   );

   /** BLAS Fortran subroutine SGEMM */
   void IPOPT_BLAS_FUNC(sgemm, SGEMM)(
      char*        transa,
      char*        transb,
      ipfint*      m,
      ipfint*      n,
      ipfint*      k,
      const float* alpha,
      const float* a,
      ipfint*      lda,
      const float* b,
      ipfint*      ldb,
      const float* beta,
      float*       c,
      ipfint*      ldc,
      int          transa_len,
      int          transb_len
   );

   /** BLAS Fortran subroutine SSYRK */
   void IPOPT_BLAS_FUNC(ssyrk, SSYRK)(
      char*        uplo,
      char*        trans,
      ipfint*      n,
      ipfint*      k,
      const float* alpha,
      const float* a,
      ipfint*      lda,
      const float* beta,
      float*       c,
      ipfint*      ldc,
      int          uplo_len,
      int          trans_len
   );

   /** BLAS Fortran subroutine STRSM */
   void IPOPT_BLAS_FUNC(strsm, STRSM)(
      char*        side,
      char*        uplo,
      char*        transa,
      char*        diag,
      ipfint*      m,
      ipfint*      n,
      const float* alpha,
      const float* a,
      ipfint*      lda,
      const float* b,
      ipfint*      ldb,
      int          side_len,
      int          uplo_len,
      int          transa_len,
      int          diag_len
   );
#else
   /** BLAS Fortran function DDOT */
   double IPOPT_BLAS_FUNC(ddot, DDOT)(
      ipfint*       n,
      const double* x,
      ipfint*       incX,
      const double* y,
      ipfint*       incY
=======
   /** BLAS Fortran function XDOT */
   ipnumber IPOPT_BLAS_FUNCP(dot, DOT)(
      ipfint*         n,
      const ipnumber* x,
      ipfint*         incX,
      const ipnumber* y,
      ipfint*         incY
>>>>>>> upstream/devel
   );

   /** BLAS Fortran function XNRM2 */
   ipnumber IPOPT_BLAS_FUNCP(nrm2, NRM2)(
      ipfint*         n,
      const ipnumber* x,
      ipfint*         incX
   );

   /** BLAS Fortran function XASUM */
   ipnumber IPOPT_BLAS_FUNCP(asum, ASUM)(
      ipfint*         n,
      const ipnumber* x,
      ipfint*         incX
   );

#ifdef IPOPT_SINGLE
   /** BLAS Fortran function ISAMAX */
   ipfint IPOPT_BLAS_FUNC(isamax, ISAMAX)(
#else
   /** BLAS Fortran function IDAMAX */
   ipfint IPOPT_BLAS_FUNC(idamax, IDAMAX)(
#endif
      ipfint*         n,
      const ipnumber* x,
      ipfint*         incX
   );

   /** BLAS Fortran subroutine XCOPY */
   void IPOPT_BLAS_FUNCP(copy, COPY)(
      ipfint*         n,
      const ipnumber* x,
      ipfint*         incX,
      ipnumber*       y,
      ipfint*         incY
   );

   /** BLAS Fortran subroutine XAXPY */
   void IPOPT_BLAS_FUNCP(axpy, AXPY)(
      ipfint*         n,
      const ipnumber* alpha,
      const ipnumber* x,
      ipfint*         incX,
      ipnumber*       y,
      ipfint*         incY
   );

   /** BLAS Fortran subroutine XSCAL */
   void IPOPT_BLAS_FUNCP(scal, SCAL)(
      ipfint*         n,
      const ipnumber* alpha,
      const ipnumber* x,
      ipfint*         incX
   );

   /** BLAS Fortran subroutine XGEMV */
   void IPOPT_BLAS_FUNCP(gemv, GEMV)(
      char*           trans,
      ipfint*         m,
      ipfint*         n,
      const ipnumber* alpha,
      const ipnumber* a,
      ipfint*         lda,
      const ipnumber* x,
      ipfint*         incX,
      const ipnumber* beta,
      ipnumber*       y,
      ipfint*         incY,
      int             trans_len
   );

   /** BLAS Fortran subroutine XSYMV */
   void IPOPT_BLAS_FUNCP(symv, SYMV)(
      char*           uplo,
      ipfint*         n,
      const ipnumber* alpha,
      const ipnumber* a,
      ipfint*         lda,
      const ipnumber* x,
      ipfint*         incX,
      const ipnumber* beta,
      ipnumber*       y,
      ipfint*         incY,
      int             uplo_len
   );

   /** BLAS Fortran subroutine XGEMM */
   void IPOPT_BLAS_FUNCP(gemm, GEMM)(
      char*           transa,
      char*           transb,
      ipfint*         m,
      ipfint*         n,
      ipfint*         k,
      const ipnumber* alpha,
      const ipnumber* a,
      ipfint*         lda,
      const ipnumber* b,
      ipfint*         ldb,
      const ipnumber* beta,
      ipnumber*       c,
      ipfint*         ldc,
      int             transa_len,
      int             transb_len
   );

   /** BLAS Fortran subroutine XSYRK */
   void IPOPT_BLAS_FUNCP(syrk, SYRK)(
      char*           uplo,
      char*           trans,
      ipfint*         n,
      ipfint*         k,
      const ipnumber* alpha,
      const ipnumber* a,
      ipfint*         lda,
      const ipnumber* beta,
      ipnumber*       c,
      ipfint*         ldc,
      int             uplo_len,
      int             trans_len
   );

   /** BLAS Fortran subroutine XTRSM */
   void IPOPT_BLAS_FUNCP(trsm, TRSM)(
      char*           side,
      char*           uplo,
      char*           transa,
      char*           diag,
      ipfint*         m,
      ipfint*         n,
      const ipnumber* alpha,
      const ipnumber* a,
      ipfint*         lda,
      const ipnumber* b,
      ipfint*         ldb,
      int             side_len,
      int             uplo_len,
      int             transa_len,
      int             diag_len
   );

#endif
}
namespace Ipopt
{
Number IpBlasDot(
   Index         size,
   const Number* x,
   Index         incX,
   const Number* y,
   Index         incY
)
{
   if( incX > 0 && incY > 0 )
   {
      ipfint n = size, INCX = incX, INCY = incY;
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
      return IPOPT_BLAS_FUNC(sdot, SDOT)(&n, x, &INCX, y, &INCY);
#else
      return IPOPT_BLAS_FUNC(ddot, DDOT)(&n, x, &INCX, y, &INCY);
#endif
=======
      return IPOPT_BLAS_FUNCP(dot, DOT)(&n, x, &INCX, y, &INCY);
>>>>>>> upstream/devel
   }
   else
   {
      Number s = 0.0;

      for( ; size; --size, x += incX, y += incY )
      {
         s += *x * *y;
      }

      return s;
   }
}

Number IpBlasNrm2(
   Index         size,
   const Number* x,
   Index         incX
)
{
   ipfint n = size, INCX = incX;
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
   return IPOPT_BLAS_FUNC(snrm2, SNRM2)(&n, x, &INCX);
#else
   return IPOPT_BLAS_FUNC(dnrm2, DNRM2)(&n, x, &INCX);
#endif
=======
   return IPOPT_BLAS_FUNCP(nrm2, NRM2)(&n, x, &INCX);
>>>>>>> upstream/devel
}

Number IpBlasAsum(
   Index         size,
   const Number* x,
   Index         incX
)
{
   ipfint n = size, INCX = incX;
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
   return IPOPT_BLAS_FUNC(sasum, SASUM)(&n, x, &INCX);
#else
   return IPOPT_BLAS_FUNC(dasum, DASUM)(&n, x, &INCX);
#endif
=======
   return IPOPT_BLAS_FUNCP(asum, ASUM)(&n, x, &INCX);
>>>>>>> upstream/devel
}

/** interface to FORTRAN routine IXAMAX */
Index IpBlasIamax(
   Index         size,
   const Number* x,
   Index         incX
)
{
   ipfint n = size, INCX = incX;
#ifdef IPOPT_SINGLE
   return (Index) IPOPT_BLAS_FUNC(isamax, ISAMAX)(&n, x, &INCX);
#else
   return (Index) IPOPT_BLAS_FUNC(idamax, IDAMAX)(&n, x, &INCX);
#endif
}

/** interface to FORTRAN routine XCOPY */
void IpBlasCopy(
   Index         size,
   const Number* x,
   Index         incX,
   Number*       y,
   Index         incY
)
{
   if( incX > 0 )
   {
      ipfint N = size, INCX = incX, INCY = incY;
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
      IPOPT_BLAS_FUNC(scopy, SCOPY)(&N, x, &INCX, y, &INCY);
#else
      IPOPT_BLAS_FUNC(dcopy, DCOPY)(&N, x, &INCX, y, &INCY);
#endif
=======
      IPOPT_BLAS_FUNCP(copy, COPY)(&N, x, &INCX, y, &INCY);
>>>>>>> upstream/devel
   }
   else if( incY == 1 )
   {
      for( ; size; --size, ++y )
      {
         *y = *x;
      }
   }
   else
   {
      for( ; size; --size, y += incY )
      {
         *y = *x;
      }
   }
}

void IpBlasAxpy(
   Index         size,
   Number        alpha,
   const Number* x,
   Index         incX,
   Number*       y,
   Index         incY
)
{
   if( incX > 0 )
   {
      ipfint N = size, INCX = incX, INCY = incY;
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
      IPOPT_BLAS_FUNC(saxpy, SAXPY)(&N, &alpha, x, &INCX, y, &INCY);
#else
      IPOPT_BLAS_FUNC(daxpy, DAXPY)(&N, &alpha, x, &INCX, y, &INCY);
#endif
=======
      IPOPT_BLAS_FUNCP(axpy, AXPY)(&N, &alpha, x, &INCX, y, &INCY);
>>>>>>> upstream/devel
   }
   else if( incY == 1 )
   {
      for( ; size; --size, ++y )
      {
         *y += alpha * *x;
      }
   }
   else
   {
      for( ; size; --size, y += incY )
      {
         *y += alpha * *x;
      }
   }
}

void IpBlasScal(
   Index   size,
   Number  alpha,
   Number* x,
   Index   incX
)
{
   ipfint N = size, INCX = incX;
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
   IPOPT_BLAS_FUNC(sscal, SSCAL)(&N, &alpha, x, &INCX);
#else
   IPOPT_BLAS_FUNC(dscal, DSCAL)(&N, &alpha, x, &INCX);
#endif
=======
   IPOPT_BLAS_FUNCP(scal, SCAL)(&N, &alpha, x, &INCX);
>>>>>>> upstream/devel
}

void IpBlasGemv(
   bool          trans,
   Index         nRows,
   Index         nCols,
   Number        alpha,
   const Number* A,
   Index         ldA,
   const Number* x,
   Index         incX,
   Number        beta,
   Number*       y,
   Index         incY
)
{
   ipfint M = nCols, N = nRows, LDA = ldA, INCX = incX, INCY = incY;

   char TRANS;
   if( trans )
   {
      TRANS = 'T';
   }
   else
   {
      TRANS = 'N';
   }
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
   IPOPT_BLAS_FUNC(sgemv, SGEMV)(&TRANS, &M, &N, &alpha, A, &LDA, x, &INCX, &beta, y, &INCY, 1);
#else
   IPOPT_BLAS_FUNC(dgemv, DGEMV)(&TRANS, &M, &N, &alpha, A, &LDA, x, &INCX, &beta, y, &INCY, 1);
#endif
=======
   IPOPT_BLAS_FUNCP(gemv, GEMV)(&TRANS, &M, &N, &alpha, A, &LDA, x, &INCX, &beta, y, &INCY, 1);
>>>>>>> upstream/devel
}

void IpBlasSymv(
   Index         n,
   Number        alpha,
   const Number* A,
   Index         ldA,
   const Number* x,
   Index         incX,
   Number        beta,
   Number*       y,
   Index         incY
)
{
   ipfint N = n, LDA = ldA, INCX = incX, INCY = incY;

   char UPLO = 'L';
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
   IPOPT_BLAS_FUNC(ssymv, SSYMV)(&UPLO, &N, &alpha, A, &LDA, x, &INCX, &beta, y, &INCY, 1);
#else
   IPOPT_BLAS_FUNC(dsymv, DSYMV)(&UPLO, &N, &alpha, A, &LDA, x, &INCX, &beta, y, &INCY, 1);
#endif
=======
   IPOPT_BLAS_FUNCP(symv, SYMV)(&UPLO, &N, &alpha, A, &LDA, x, &INCX, &beta, y, &INCY, 1);
>>>>>>> upstream/devel
}

void IpBlasGemm(
   bool          transa,
   bool          transb,
   Index         m,
   Index         n,
   Index         k,
   Number        alpha,
   const Number* A,
   Index         ldA,
   const Number* B,
   Index         ldB,
   Number        beta,
   Number*       C,
   Index         ldC
)
{
   ipfint M = m, N = n, K = k, LDA = ldA, LDB = ldB, LDC = ldC;

   char TRANSA;
   if( transa )
   {
      TRANSA = 'T';
   }
   else
   {
      TRANSA = 'N';
   }
   char TRANSB;
   if( transb )
   {
      TRANSB = 'T';
   }
   else
   {
      TRANSB = 'N';
   }
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
   IPOPT_BLAS_FUNC(sgemm, SGEMM)(&TRANSA, &TRANSB, &M, &N, &K, &alpha, A, &LDA, B, &LDB, &beta, C, &LDC, 1, 1);
#else
   IPOPT_BLAS_FUNC(dgemm, DGEMM)(&TRANSA, &TRANSB, &M, &N, &K, &alpha, A, &LDA, B, &LDB, &beta, C, &LDC, 1, 1);
#endif
=======
   IPOPT_BLAS_FUNCP(gemm, GEMM)(&TRANSA, &TRANSB, &M, &N, &K, &alpha, A, &LDA, B, &LDB, &beta, C, &LDC, 1, 1);
>>>>>>> upstream/devel
}

void IpBlasSyrk(
   bool          trans,
   Index         ndim,
   Index         nrank,
   Number        alpha,
   const Number* A,
   Index         ldA,
   Number        beta,
   Number*       C,
   Index         ldC
)
{
   ipfint N = ndim, K = nrank, LDA = ldA, LDC = ldC;

   char UPLO = 'L';
   char TRANS;
   if( trans )
   {
      TRANS = 'T';
   }
   else
   {
      TRANS = 'N';
   }
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
   IPOPT_BLAS_FUNC(ssyrk, SSYRK)(&UPLO, &TRANS, &N, &K, &alpha, A, &LDA, &beta, C, &LDC, 1, 1);
#else
   IPOPT_BLAS_FUNC(dsyrk, DSYRK)(&UPLO, &TRANS, &N, &K, &alpha, A, &LDA, &beta, C, &LDC, 1, 1);
#endif
=======
   IPOPT_BLAS_FUNCP(syrk, SYRK)(&UPLO, &TRANS, &N, &K, &alpha, A, &LDA, &beta, C, &LDC, 1, 1);
>>>>>>> upstream/devel
}

void IpBlasTrsm(
   bool          trans,
   Index         ndim,
   Index         nrhs,
   Number        alpha,
   const Number* A,
   Index         ldA,
   Number*       B,
   Index         ldB
)
{
   ipfint M = ndim, N = nrhs, LDA = ldA, LDB = ldB;

   char SIDE = 'L';
   char UPLO = 'L';
   char TRANSA;
   if( trans )
   {
      TRANSA = 'T';
   }
   else
   {
      TRANSA = 'N';
   }
   char DIAG = 'N';
<<<<<<< HEAD
#ifdef IPOPT_SINGLE
   IPOPT_BLAS_FUNC(strsm, STRSM)(&SIDE, &UPLO, &TRANSA, &DIAG, &M, &N, &alpha, A, &LDA, B, &LDB, 1, 1, 1, 1);
#else
   IPOPT_BLAS_FUNC(dtrsm, DTRSM)(&SIDE, &UPLO, &TRANSA, &DIAG, &M, &N, &alpha, A, &LDA, B, &LDB, 1, 1, 1, 1);
#endif
=======
   IPOPT_BLAS_FUNCP(trsm, TRSM)(&SIDE, &UPLO, &TRANSA, &DIAG, &M, &N, &alpha, A, &LDA, B, &LDB, 1, 1, 1, 1);
>>>>>>> upstream/devel
}

} // namespace Ipopt
