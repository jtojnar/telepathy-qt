/**
 * This file is part of TelepathyQt
 *
 * Copyright (C) 2011-2012 Collabora Ltd. <http://www.collabora.co.uk/>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _TelepathyQt_Farstream_types_h_HEADER_GUARD_
#define _TelepathyQt_Farstream_types_h_HEADER_GUARD_

#ifndef IN_TP_QT_FARSTREAM_HEADER
#error IN_TP_QT_FARSTREAM_HEADER
#endif

#include <TelepathyQt/Types>

namespace Tp
{

class FarstreamChannelFactory;

typedef Tp::SharedPtr<FarstreamChannelFactory> FarstreamChannelFactoryPtr;

} // Tp

#endif
