// Copyright (C) 2005, 2009 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// Authors:  Andreas Waechter              IBM    2005-12-25

#include "IpoptConfig.h"
#include "IpLapack.hpp"
#include "IpTypes.h"

#ifdef FUNNY_LAPACK_FINT
# define ipfint long
# define ipfintarray int
#else
# define ipfintarray ipfint
#endif

#ifdef IPOPT_SINGLE
#define IPOPT_LAPACK_FUNCP(name,NAME) IPOPT_LAPACK_FUNC(s ## name,S ## NAME)
#else
#define IPOPT_LAPACK_FUNCP(name,NAME) IPOPT_LAPACK_FUNC(d ## name,D ## NAME)
#endif

#ifdef IPOPT_HAS_LAPACK
// Prototypes for the LAPACK routines
#ifdef IPOPT_SINGLE
extern "C"
{
   /** LAPACK Fortran subroutine SPOTRS. */
   void IPOPT_LAPACK_FUNC(spotrs, SPOTRS)(
      char*        uplo,
      ipfint*      n,
      ipfint*      nrhs,
      const float* A,
      ipfint*      ldA,
      float*       B,
      ipfint*      ldB,
      ipfint*      info,
      int          uplo_len
   );

   /** LAPACK Fortran subroutine SPOTRF. */
   void IPOPT_LAPACK_FUNC(spotrf, SPOTRF)(
      char*   uplo,
      ipfint* n,
      float*  A,
      ipfint* ldA,
      ipfint* info,
      int     uplo_len
   );

   /** LAPACK Fortran subroutine SSYEV */
   void IPOPT_LAPACK_FUNC(ssyev, SSYEV)(
      char*   jobz,
      char*   uplo,
      ipfint* n,
      float*  A,
      ipfint* ldA,
      float*  W,
      float*  WORK,
      ipfint* LWORK,
      ipfint* info,
      int     jobz_len,
      int     uplo_len
   );

   /** LAPACK Fortran subroutine SGETRF. */
   void IPOPT_LAPACK_FUNC(sgetrf, SGETRF)(
      ipfint*      m,
      ipfint*      n,
      float*       A,
      ipfint*      ldA,
      ipfintarray* IPIV,
      ipfint*      info
   );

   /** LAPACK Fortran subroutine SGETRS. */
   void IPOPT_LAPACK_FUNC(sgetrs, SGETRS)(
      char*        trans,
      ipfint*      n,
      ipfint*      nrhs,
      const float* A,
      ipfint*      ldA,
      ipfintarray* IPIV,
      float*       B,
      ipfint*      ldB,
      ipfint*      info,
      int          trans_len
   );

   /** LAPACK Fortran subroutine SPPSV. */
   void IPOPT_LAPACK_FUNC(sppsv, SPPSV)(
      char*        uplo,
      ipfint*      n,
      ipfint*      nrhs,
      const float* A,
      float*       B,
      ipfint*      ldB,
      ipfint*      info
   );
}

namespace Ipopt
{
void IpLapackPotrs(
   Index         ndim,
   Index         nrhs,
   const Number* a,
   Index         lda,
   Number*       b,
   Index         ldb
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, NRHS = nrhs, LDA = lda, LDB = ldb, INFO;
   char uplo = 'L';

   IPOPT_LAPACK_FUNC(spotrs, SPOTRS)(&uplo, &N, &NRHS, a, &LDA, b, &LDB, &INFO, 1);
   DBG_ASSERT(INFO == 0);
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine SPOTRS, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif
}

void IpLapackPotrf(
   Index   ndim,
   Number* a,
   Index   lda,
   Index&  info
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, LDA = lda, INFO;

   char UPLO = 'L';

   IPOPT_LAPACK_FUNC(spotrf, SPOTRF)(&UPLO, &N, a, &LDA, &INFO, 1);

   info = INFO;
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine SPOTRF, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif

}

void IpLapackSyev(
   bool    compute_eigenvectors,
   Index   ndim,
   Number* a,
   Index   lda,
   Number* w,
   Index&  info
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, LDA = lda, INFO;

   char JOBZ;
   if (compute_eigenvectors)
   {
      JOBZ = 'V';
   }
   else
   {
      JOBZ = 'N';
   }
   char UPLO = 'L';

   // First we find out how large LWORK should be
   ipfint LWORK = -1;
   Number WORK_PROBE;
   IPOPT_LAPACK_FUNC(ssyev, SSYEV)(&JOBZ, &UPLO, &N, a, &LDA, w,
                                  &WORK_PROBE, &LWORK, &INFO, 1, 1);
   DBG_ASSERT(INFO == 0);

   LWORK = (ipfint) WORK_PROBE;
   DBG_ASSERT(LWORK > 0);

   Number* WORK = new Number[LWORK];
   for (Index i = 0; i < LWORK; i++)
   {
      WORK[i] = i;
   }
   IPOPT_LAPACK_FUNC(ssyev, SSYEV)(&JOBZ, &UPLO, &N, a, &LDA, w,
                                  WORK, &LWORK, &INFO, 1, 1);

   DBG_ASSERT(INFO >= 0);
   info = INFO;

   delete [] WORK;
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine SSYEV, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif

}

void IpLapackGetrf(
   Index   ndim,
   Number* a,
   Index*  ipiv,
   Index   lda,
   Index&  info
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint M = ndim, N = ndim, LDA = lda, INFO;

   IPOPT_LAPACK_FUNC(sgetrf, SGETRF)(&M, &N, a, &LDA, ipiv, &INFO);

   info = INFO;
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine SGETRF, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif

}

void IpLapackGetrs(
   Index         ndim,
   Index         nrhs,
   const Number* a,
   Index         lda,
   Index*        ipiv,
   Number*       b,
   Index         ldb
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, NRHS = nrhs, LDA = lda, LDB = ldb, INFO;
   char trans = 'N';

   IPOPT_LAPACK_FUNC(sgetrs, SGETRS)(&trans, &N, &NRHS, a, &LDA, ipiv, b, &LDB,
                                    &INFO, 1);
   DBG_ASSERT(INFO == 0);
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine SGETRS, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif

}

void IpLapackPpsv(
   Index         ndim,
   Index         nrhs,
   const Number* a,
   Number*       b,
   Index         ldb,
   Index&        info
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, NRHS = nrhs, LDB = ldb, INFO;
   char uplo = 'U';

   IPOPT_LAPACK_FUNC(sppsv, SPPSV)(&uplo, &N, &NRHS, a, b, &LDB, &INFO);

   info = INFO;
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine SPPSV, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif
}

} // namespace Ipopt
#else
extern "C"
{
   /** LAPACK Fortran subroutine XPOTRS. */
   void IPOPT_LAPACK_FUNCP(potrs, POTRS)(
      char*           uplo,
      ipfint*         n,
      ipfint*         nrhs,
      const ipnumber* A,
      ipfint*         ldA,
      ipnumber*       B,
      ipfint*         ldB,
      ipfint*         info,
      int             uplo_len
   );

   /** LAPACK Fortran subroutine XPOTRF. */
   void IPOPT_LAPACK_FUNCP(potrf, POTRF)(
      char*     uplo,
      ipfint*   n,
      ipnumber* A,
      ipfint*   ldA,
      ipfint*   info,
      int       uplo_len
   );

   /** LAPACK Fortran subroutine XSYEV */
   void IPOPT_LAPACK_FUNCP(syev, SYEV)(
      char*     jobz,
      char*     uplo,
      ipfint*   n,
      ipnumber* A,
      ipfint*   ldA,
      ipnumber* W,
      ipnumber* WORK,
      ipfint*   LWORK,
      ipfint*   info,
      int       jobz_len,
      int       uplo_len
   );

   /** LAPACK Fortran subroutine XGETRF. */
   void IPOPT_LAPACK_FUNCP(getrf, GETRF)(
      ipfint*       m,
      ipfint*       n,
      ipnumber*     A,
      ipfint*       ldA,
      ipfintarray*  IPIV,
      ipfint*       info
   );

   /** LAPACK Fortran subroutine XGETRS. */
   void IPOPT_LAPACK_FUNCP(getrs, GETRS)(
      char*           trans,
      ipfint*         n,
      ipfint*         nrhs,
      const ipnumber* A,
      ipfint*         ldA,
      ipfintarray*    IPIV,
      ipnumber*       B,
      ipfint*         ldB,
      ipfint*         info,
      int             trans_len
   );

   /** LAPACK Fortran subroutine XPPSV. */
   void IPOPT_LAPACK_FUNCP(ppsv, PPSV)(
      char*           uplo,
      ipfint*         n,
      ipfint*         nrhs,
      const ipnumber* A,
      ipnumber*       B,
      ipfint*         ldB,
      ipfint*         info
   );
}

namespace Ipopt
{
void IpLapackPotrs(
   Index         ndim,
   Index         nrhs,
   const Number* a,
   Index         lda,
   Number*       b,
   Index         ldb
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, NRHS = nrhs, LDA = lda, LDB = ldb, INFO;
   char uplo = 'L';

   IPOPT_LAPACK_FUNCP(potrs, POTRS)(&uplo, &N, &NRHS, a, &LDA, b, &LDB, &INFO, 1);
   DBG_ASSERT(INFO == 0);
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine DPOTRS, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif
}

void IpLapackPotrf(
   Index   ndim,
   Number* a,
   Index   lda,
   Index&  info
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, LDA = lda, INFO;

   char UPLO = 'L';

   IPOPT_LAPACK_FUNCP(potrf, POTRF)(&UPLO, &N, a, &LDA, &INFO, 1);

   info = INFO;
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine DPOTRF, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif

}

void IpLapackSyev(
   bool    compute_eigenvectors,
   Index   ndim,
   Number* a,
   Index   lda,
   Number* w,
   Index&  info
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, LDA = lda, INFO;

   char JOBZ;
   if (compute_eigenvectors)
   {
      JOBZ = 'V';
   }
   else
   {
      JOBZ = 'N';
   }
   char UPLO = 'L';

   // First we find out how large LWORK should be
   ipfint LWORK = -1;
   Number WORK_PROBE;
<<<<<<< HEAD
   IPOPT_LAPACK_FUNC(dsyev, DSYEV)(&JOBZ, &UPLO, &N, a, &LDA, w,
=======
   IPOPT_LAPACK_FUNCP(syev, SYEV)(&JOBZ, &UPLO, &N, a, &LDA, w,
>>>>>>> upstream/devel
                                  &WORK_PROBE, &LWORK, &INFO, 1, 1);
   DBG_ASSERT(INFO == 0);

   LWORK = (ipfint) WORK_PROBE;
   DBG_ASSERT(LWORK > 0);

   Number* WORK = new Number[LWORK];
   for (Index i = 0; i < LWORK; i++)
   {
      WORK[i] = i;
   }
   IPOPT_LAPACK_FUNCP(syev, SYEV)(&JOBZ, &UPLO, &N, a, &LDA, w,
                                  WORK, &LWORK, &INFO, 1, 1);

   DBG_ASSERT(INFO >= 0);
   info = INFO;

   delete [] WORK;
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine DSYEV, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif

}

void IpLapackGetrf(
   Index   ndim,
   Number* a,
   Index*  ipiv,
   Index   lda,
   Index&  info
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint M = ndim, N = ndim, LDA = lda, INFO;

   IPOPT_LAPACK_FUNCP(getrf, GETRF)(&M, &N, a, &LDA, ipiv, &INFO);

   info = INFO;
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine DGETRF, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif

}

void IpLapackGetrs(
   Index         ndim,
   Index         nrhs,
   const Number* a,
   Index         lda,
   Index*        ipiv,
   Number*       b,
   Index         ldb
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, NRHS = nrhs, LDA = lda, LDB = ldb, INFO;
   char trans = 'N';

   IPOPT_LAPACK_FUNCP(getrs, GETRS)(&trans, &N, &NRHS, a, &LDA, ipiv, b, &LDB,
                                    &INFO, 1);

   DBG_ASSERT(INFO == 0);
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine DGETRS, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif

}

void IpLapackPpsv(
   Index         ndim,
   Index         nrhs,
   const Number* a,
   Number*       b,
   Index         ldb,
   Index&        info
)
{
#ifdef IPOPT_HAS_LAPACK
   ipfint N = ndim, NRHS = nrhs, LDB = ldb, INFO;
   char uplo = 'U';

   IPOPT_LAPACK_FUNCP(ppsv, PPSV)(&uplo, &N, &NRHS, a, b, &LDB, &INFO);

   info = INFO;
#else

   std::string msg =
      "Ipopt has been compiled without LAPACK routine DPPSV, but options are chosen that require this dependency.  Abort.";
   THROW_EXCEPTION(LAPACK_NOT_INCLUDED, msg);
#endif
}

} // namespace Ipopt
<<<<<<< HEAD
#endif
#endif
=======
#endif  /* ifdef IPOPT_HAS_LAPACK */
>>>>>>> upstream/devel
