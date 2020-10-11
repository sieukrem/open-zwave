//-----------------------------------------------------------------------------
//
//	AutoLock.h
//
//	Basic types and preprocessor directives
//
//	Copyright (c) 2020 Eugen Kremer <eugen.kremer+openzwave@gmail.com>
//
//	SOFTWARE NOTICE AND LICENSE
//
//	This file is part of OpenZWave.
//
//	OpenZWave is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as published
//	by the Free Software Foundation, either version 3 of the License,
//	or (at your option) any later version.
//
//	OpenZWave is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU Lesser General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with OpenZWave.  If not, see <http://www.gnu.org/licenses/>.
//
//-----------------------------------------------------------------------------

#ifndef _AutoLock_H
#define _AutoLock_H

#include "platform/Mutex.h"

namespace OpenZWave
{
    namespace Internal{
        class AutoLock{
            private:
                Internal::Platform::Mutex* m_Mutex;
            public:
                AutoLock(Internal::Platform::Mutex* mutex){
                    m_Mutex = mutex;
                    m_Mutex->Lock();
                }
                ~AutoLock(){
                    m_Mutex->Unlock();
                }
        };
    }
}

#endif
