/** @file   dynlibs_manager_delegate_interface.h
    @author Philip Abbet (philip.abbet@idiap.ch)

    Declaration of the 'IDynlibsManagerDelegate' interface
*/

#ifndef _MASH_IDYNLIBSMANAGERDELEGATE_H_
#define _MASH_IDYNLIBSMANAGERDELEGATE_H_

#include <mash-utils/declarations.h>


namespace Mash
{
    //--------------------------------------------------------------------------
    /// @brief  Interface of the delegate object used by the 'dynamic libraries
    ///         manager' to interact with the sandbox
    //--------------------------------------------------------------------------
    class MASH_SYMBOL IDynlibsManagerDelegate
    {
        //_____ Construction / Destruction __________
    public:
        //----------------------------------------------------------------------
        /// @brief  Constructor
        //----------------------------------------------------------------------
        IDynlibsManagerDelegate() {}

        //----------------------------------------------------------------------
        /// @brief  Destructor
        //----------------------------------------------------------------------
        virtual ~IDynlibsManagerDelegate() {}


        //_____ Methods to implement __________
    public:
        //----------------------------------------------------------------------
        /// @brief  Enable the usage of the sandbox warden from now on
        //----------------------------------------------------------------------
        virtual void enableWarden() = 0;

        //----------------------------------------------------------------------
        /// @brief  Disable the usage of the sandbox warden from now on
        //----------------------------------------------------------------------
        virtual void disableWarden() = 0;
    };
}

#endif
