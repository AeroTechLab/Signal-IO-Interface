////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//  Copyright (c) 2016-2020 Leonardo Consoni <leonardojc@protonmail.com>          //
//                                                                                //
//  This file is part of Signal I/O Interface.                                    //
//                                                                                //
//  Signal I/O Interface is free software: you can redistribute it and/or modify  //
//  it under the terms of the GNU Lesser General Public License as published      //
//  by the Free Software Foundation, either version 3 of the License, or          //
//  (at your option) any later version.                                           //
//                                                                                //
//  Signal I/O Interface is distributed in the hope that it will be useful,       //
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                //
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
//  GNU Lesser General Public License for more details.                           //
//                                                                                //
//  You should have received a copy of the GNU Lesser General Public License      //
//  along with Signal I/O Interface. If not, see <http://www.gnu.org/licenses/>.  //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////


/// @file signal_io.h
/// @brief Signal aquisition/generation functions
///
/// Physical/virtual signal aquisition and generation interface to be implemented by hardware specific plugins

#ifndef SIGNAL_IO_H
#define SIGNAL_IO_H

#include <math.h>
#ifndef M_PI
#define M_PI 3.14159    ///< Defines mathematical Pi value if standard math.h one is not available
#endif

#include "plugin_loader/loader_macros.h"

#define SIGNAL_IO_DEVICE_INVALID_ID -1        ///< Device identifier to be returned on device creation errors

/// Signal input/output interface declaration macro
#define SIGNAL_IO_INTERFACE( Namespace, INIT_FUNCTION ) \
        INIT_FUNCTION( long int, Namespace, InitDevice, const char* ) \
        INIT_FUNCTION( void, Namespace, EndDevice, long int ) \
        INIT_FUNCTION( void, Namespace, Reset, long int ) \
        INIT_FUNCTION( bool, Namespace, HasError, long int ) \
        INIT_FUNCTION( size_t, Namespace, GetMaxInputSamplesNumber, long int ) \
        INIT_FUNCTION( size_t, Namespace, Read, long int, unsigned int, double* ) \
        INIT_FUNCTION( bool, Namespace, CheckInputChannel, long int, unsigned int ) \
        INIT_FUNCTION( bool, Namespace, Write, long int, unsigned int, double ) \
        INIT_FUNCTION( bool, Namespace, AcquireOutputChannel, long int, unsigned int ) \
        INIT_FUNCTION( void, Namespace, ReleaseOutputChannel, long int, unsigned int ) 

        
#endif // SIGNAL_IO_H 
        
/// @class SIGNAL_IO_INTERFACE
/// @brief File/string/stream data input/output methods to be implemented by plugins
///    
/// @memberof SIGNAL_IO_INTERFACE
/// @fn long int InitDevice( const char* deviceConfig )                                                                            
/// @brief Creates plugin specific signal input/output device data structure
/// @param[in] deviceConfig implementation specific device configuration string
/// @return generic identifier to newly created device (SIGNAL_IO_TASK_INVALID_ID on errors)
///   
/// @memberof SIGNAL_IO_INTERFACE
/// @fn void EndDevice( long int deviceID )
/// @brief Discards given signal input/output device data structure    
/// @param[in] deviceID input/output device identifier
///   
/// @memberof SIGNAL_IO_INTERFACE
/// @fn bool HasError( long int deviceID )                                                                                
/// @brief Verifies occurence of errors on given device
/// @param[in] deviceID input/output device identifier 
/// @return true on detected error, false otherwise 
///   
/// @memberof SIGNAL_IO_INTERFACE        
/// @fn void Reset( long int deviceID )
/// @brief Resets data and errors for given device
/// @param[in] deviceID input/output device identifier
///   
/// @memberof SIGNAL_IO_INTERFACE
/// @fn size_t GetMaxInputSamplesNumber( long int deviceID )
/// @brief Gets number of samples aquired for every given device input channel on each Read() call
/// @param[in] deviceID input device identifier
/// @return max read samples number (0 on errors)
///   
/// @memberof SIGNAL_IO_INTERFACE
/// @fn bool CheckInputChannel( long int deviceID, unsigned int channel )
/// @brief Check reading availability for specified input channel of given device
/// @param[in] deviceID input device identifier
/// @param[in] channel input device channel index
/// @return true on channel availability for reading, false otherwise
///   
/// @memberof SIGNAL_IO_INTERFACE
/// @fn size_t Read( long int deviceID, unsigned int channel, double* ref_value )
/// @brief Reads samples list from specified channel of given device
/// @param[in] deviceID input device identifier
/// @param[in] channel input device channel index
/// @param[out] ref_value allocated buffer long enough to hold the samples number returned by GetMaxInputSamplesNumber()
/// @return number of samples read (0 on errors)
///   
/// @memberof SIGNAL_IO_INTERFACE
/// @fn bool AcquireOutputChannel( long int deviceID, unsigned int channel )
/// @brief Check availability and get exclusive access for specified output channel of given device
/// @param[in] deviceID output device identifier
/// @param[in] channel output device channel index
/// @return true on successful channel acquisition (availability for writing), false otherwise
///   
/// @memberof SIGNAL_IO_INTERFACE
/// @fn void ReleaseOutputChannel( long int deviceID, unsigned int channel )
/// @brief Give up exclusive access for specified output channel of given device
/// @param[in] deviceID output device identifier
/// @param[in] channel output device channel index
///   
/// @memberof SIGNAL_IO_INTERFACE
/// @fn bool Write( long int deviceID, unsigned int channel, double value )
/// @brief Writes value to specified channel of given device
/// @param[in] deviceID output device identifier
/// @param[in] channel output device channel index
/// @param[in] value value to be written
/// @return true on successful writing, false otherwise
///
/// @memberof SIGNAL_IO_INTERFACE
