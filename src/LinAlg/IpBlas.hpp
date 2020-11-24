// Copyright (C) 2004, 2006 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// Authors:  Carl Laird, Andreas Waechter     IBM    2004-08-13

#ifndef __IPBLAS_HPP__
#define __IPBLAS_HPP__

#include "IpUtils.hpp"

namespace Ipopt
{
/** Wrapper for BLAS function XDOT.
<<<<<<< HEAD
=======
 *
 * Compute dot product of vector x and vector y.
 */
IPOPTLIB_EXPORT Number IpBlasDot(
   Index         size,
   const Number* x,
   Index         incX,
   const Number* y,
   Index         incY
);

/** Wrapper for BLAS function DDOT.
>>>>>>> upstream/devel
 *
 * Compute dot product of vector x and vector y.
 *
 * @deprecated Use IpBlasDot() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT Number IpBlasDot(
=======
IPOPT_DEPRECATED
inline Number IpBlasDdot(
>>>>>>> upstream/devel
   Index         size,
   const Number* x,
   Index         incX,
   const Number* y,
   Index         incY
)
{
   return IpBlasDot(size, x, incX, y, incY);
}

/** Wrapper for BLAS function XNRM2.
 *
 * Compute 2-norm of vector x.
 */
IPOPTLIB_EXPORT Number IpBlasNrm2(
   Index         size,
   const Number* x,
   Index         incX
);

/** Wrapper for BLAS function XNRM2.
 *
 * Compute 2-norm of vector x.
 *
 * @deprecated Use IpBlasNrm2() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT Number IpBlasNrm2(
=======
IPOPT_DEPRECATED
inline Number IpBlasDnrm2(
   Index         size,
   const Number* x,
   Index         incX
)
{
   return IpBlasNrm2(size, x, incX);
}

/** Wrapper for BLAS function XASUM.
 *
 * Compute 1-norm of vector x.
 */
IPOPTLIB_EXPORT Number IpBlasAsum(
>>>>>>> upstream/devel
   Index         size,
   const Number* x,
   Index         incX
);

/** Wrapper for BLAS function XASUM.
 *
 * Compute 1-norm of vector x.
 *
 * @deprecated Use IpBlasAsum() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT Number IpBlasAsum(
=======
IPOPT_DEPRECATED
inline Number IpBlasDasum(
   Index         size,
   const Number* x,
   Index         incX
)
{
   return IpBlasAsum(size, x, incX);
}

/** Wrapper for BLAS function IXAMAX.
 *
 * Compute index for largest absolute element of vector x.
 */
IPOPTLIB_EXPORT int IpBlasIamax(
>>>>>>> upstream/devel
   Index         size,
   const Number* x,
   Index         incX
);

/** Wrapper for BLAS function IXAMAX.
 *
 * Compute index for largest absolute element of vector x.
 *
 * @deprecated Use IpBlasIamax() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT int IpBlasIamax(
=======
IPOPT_DEPRECATED
inline int IpBlasIdamax(
>>>>>>> upstream/devel
   Index         size,
   const Number* x,
   Index         incX
)
{
   return IpBlasIamax(size, x, incX);
}

/** Wrapper for BLAS subroutine XCOPY.
 *
 * Copying vector x into vector y.
 */
IPOPTLIB_EXPORT void IpBlasCopy(
   Index         size,
   const Number* x,
   Index         incX,
   Number*       y,
   Index         incY
);

/** Wrapper for BLAS subroutine XCOPY.
 *
 * Copying vector x into vector y.
 *
 * @deprecated Use IpBlasCopy() instead.
 */
IPOPT_DEPRECATED
inline void IpBlasDcopy(
   Index         size,
   const Number* x,
   Index         incX,
   Number*       y,
   Index         incY
)
{
   IpBlasCopy(size, x, incX, y, incY);
}

/** Wrapper for BLAS subroutine XAXPY.
 *
 * Adding the alpha multiple of vector x to vector y.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT void IpBlasCopy(
=======
IPOPTLIB_EXPORT void IpBlasAxpy(
>>>>>>> upstream/devel
   Index         size,
   Number        alpha,
   const Number* x,
   Index         incX,
   Number*       y,
   Index         incY
);

/** Wrapper for BLAS subroutine XAXPY.
 *
 * Adding the alpha multiple of vector x to vector y.
 *
 * @deprecated Use IpBlasAxpy() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT void IpBlasAxpy(
=======
IPOPT_DEPRECATED
inline void IpBlasDaxpy(
>>>>>>> upstream/devel
   Index         size,
   Number        alpha,
   const Number* x,
   Index         incX,
   Number*       y,
   Index         incY
)
{
   IpBlasAxpy(size, alpha, x, incX, y, incY);
}

/** Wrapper for BLAS subroutine XSCAL.
 *
 * Scaling vector x by scalar alpha.
 */
IPOPTLIB_EXPORT void IpBlasScal(
   Index   size,
   Number  alpha,
   Number* x,
   Index   incX
);

/** Wrapper for BLAS subroutine XSCAL.
 *
 * Scaling vector x by scalar alpha.
 *
 * @deprecated Use IpBlasScal() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT void IpBlasScal(
=======
IPOPT_DEPRECATED
inline void IpBlasDscal(
>>>>>>> upstream/devel
   Index   size,
   Number  alpha,
   Number* x,
   Index   incX
)
{
   IpBlasScal(size, alpha, x, incX);
}

/** Wrapper for BLAS subroutine XGEMV.
 *
 * Multiplying a matrix with a vector.
 */
IPOPTLIB_EXPORT void IpBlasGemv(
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
);

/** Wrapper for BLAS subroutine XGEMV.
 *
 * Multiplying a matrix with a vector.
 *
 * @deprecated Use IpBlasGemv() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT void IpBlasGemv(
=======
IPOPT_DEPRECATED
inline void IpBlasDgemv(
>>>>>>> upstream/devel
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
   IpBlasGemv(trans, nRows, nCols, alpha, A, ldA, x, incX, beta, y, incY);
}

/** Wrapper for BLAS subroutine XSYMV.
 *
 * Multiplying a symmetric matrix with a vector.
 */
IPOPTLIB_EXPORT void IpBlasSymv(
   Index         n,
   Number        alpha,
   const Number* A,
   Index         ldA,
   const Number* x,
   Index         incX,
   Number        beta,
   Number*       y,
   Index         incY
);

/** Wrapper for BLAS subroutine XSYMV.
 *
 * Multiplying a symmetric matrix with a vector.
 *
 * @deprecated Use IpBlasSymv() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT void IpBlasSymv(
=======
IPOPT_DEPRECATED
inline void IpBlasDsymv(
>>>>>>> upstream/devel
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
   IpBlasSymv(n, alpha, A, ldA, x, incX, beta, y, incY);
}

/** Wrapper for BLAS subroutine XGEMM.
 *
 * Multiplying two matrices.
 */
IPOPTLIB_EXPORT void IpBlasGemm(
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
);

/** Wrapper for BLAS subroutine XGEMM.
 *
 * Multiplying two matrices.
 *
 * @deprecated Use IpBlasGemm() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT void IpBlasGemm(
=======
IPOPT_DEPRECATED
inline void IpBlasDgemm(
>>>>>>> upstream/devel
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
   IpBlasGemm(transa, transb, m, n, k, alpha, A, ldA, B, ldB, beta, C, ldC);
}

/** Wrapper for BLAS subroutine XSYRK.
 *
 * Adding a high-rank update to a matrix.
 */
IPOPTLIB_EXPORT void IpBlasSyrk(
   bool          trans,
   Index         ndim,
   Index         nrank,
   Number        alpha,
   const Number* A,
   Index         ldA,
   Number        beta,
   Number*       C,
   Index         ldC
);

/** Wrapper for BLAS subroutine XSYRK.
 *
 * Adding a high-rank update to a matrix.
 *
 * @deprecated Use IpBlasSyrk() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT void IpBlasSyrk(
=======
IPOPT_DEPRECATED
inline void IpBlasDsyrk(
>>>>>>> upstream/devel
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
   IpBlasSyrk(trans, ndim, nrank, alpha, A, ldA, beta, C, ldC);
}

/** Wrapper for BLAS subroutine XTRSM.
 *
 * Backsolve for a lower triangular matrix.
 */
IPOPTLIB_EXPORT void IpBlasTrsm(
   bool          trans,
   Index         ndim,
   Index         nrhs,
   Number        alpha,
   const Number* A,
   Index         ldA,
   Number*       B,
   Index         ldB
);

/** Wrapper for BLAS subroutine XTRSM.
 *
 * Backsolve for a lower triangular matrix.
 *
 * @deprecated Use IpBlasTrsm() instead.
 */
<<<<<<< HEAD
IPOPTLIB_EXPORT void IpBlasTrsm(
=======
IPOPT_DEPRECATED
inline void IpBlasDtrsm(
>>>>>>> upstream/devel
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
   IpBlasTrsm(trans, ndim, nrhs, alpha, A, ldA, B, ldB);
}

} // namespace Ipopt

#endif
