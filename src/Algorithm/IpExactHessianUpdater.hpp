// Copyright (C) 2005, 2006 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// Authors:  Andreas Waechter            IBM    2005-12-26

#ifndef __IPEXACTHESSIANUPDATER_HPP__
#define __IPEXACTHESSIANUPDATER_HPP__

#include "IpHessianUpdater.hpp"

namespace Ipopt
{

/** Implementation of the HessianUpdater for the use of exact second
 *  derivatives.
 */
class ExactHessianUpdater: public HessianUpdater
{
public:
   /**@name Constructors/Destructors */
   ///@{
   /** Default Constructor */
   ExactHessianUpdater()
   { }

   /** Destructor */
   virtual ~ExactHessianUpdater()
   { }
   ///@}

   /** overloaded from AlgorithmStrategyObject */
   virtual bool InitializeImpl(
      const OptionsList& options,
      const std::string& prefix
   );

   /** Update the Hessian based on the current information in IpData. */
   virtual void UpdateHessian();

private:
   /**@name Default Compiler Generated Methods
    * (Hidden to avoid implicit creation/calling).
    *
    * These methods are not implemented and
    * we do not want the compiler to implement
    * them for us, so we declare them private
    * and do not define them. This ensures that
    * they will not be implicitly created/called.
    */
   ///@{
   /** Copy Constructor */
   ExactHessianUpdater(
      const ExactHessianUpdater&
   );

   /** Default Assignment Operator */
   void operator=(
      const ExactHessianUpdater&
   );
   ///@}

};

} // namespace Ipopt

#endif
