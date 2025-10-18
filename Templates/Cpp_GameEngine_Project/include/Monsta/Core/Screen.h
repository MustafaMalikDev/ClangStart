/**
 *  Monsta 3D Game Engine Framework.
 *  Copyright (C) 2024 Mustafa Malik (avia.shabbyman@gmail.com)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LIB_MONSTA_SCREEN_H
#define LIB_MONSTA_SCREEN_H

#include "Monsta/Config.h"

#if defined( MONSTA_PLAT_MAC )
#include <CoreGraphics/CGDisplayConfiguration.h>
#elif defined( MONSTA_PLAT_WINDOWS )
#include <Windows.h>
#else
#error Core/Screen.h is missing an include file, please implement it
#endif

namespace monsta::core
{

static inline unsigned int
get_screen_width ()
{
#if defined( MONSTA_PLAT_MAC )
  CGDirectDisplayID displayId = CGMainDisplayID ();
  return CGDisplayPixelsWide ( displayId );
#endif
}

static inline unsigned int
get_screen_height ()
{
#if defined( MONSTA_PLAT_MAC )
  CGDirectDisplayID displayId = CGMainDisplayID ();
  return CGDisplayPixelsHigh ( displayId );
#endif
}

}

#endif /* LIB_MONSTA_SCREEN_H */