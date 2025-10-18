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

#ifndef LIB_MONSTA_CONFIG_H
#define LIB_MONSTA_CONFIG_H

// clang-format off
#if defined(__APPLE__)
#   ifdef __i386__
#       error Unsupported Platform archietecture. Please use Apple Silicon (arm64).
#   endif
#   include <TargetConditionals.h>
#   if defined(TARGET_OS_MAC) || defined(TARGET_OSX)
#       define MONSTA_PLAT_MAC
#   endif
#   if defined(TARGET_OS_IOS)
#       define MONSTA_PLAT_IOS
#   endif
#elif defined(__unix__) || defined(__unix) || defined(unix)
#   define MONSTA_PLAT_UNIX
#elif defined(_WIN32) || defined(_WIN64)
#   define MONSTA_PLAT_WINDOWS
#elif defined(__ANDROID__)
#   define MONSTA_PLAT_ANDROID
#else
#   error Unknown platform detected. Cannot use Engine.
#endif
// clang-format on

#define MONSTA_GL_MAJOR_VERSION 4

#ifdef __APPLE__
#define MONSTA_GL_MINOR_VERSION 1
#else
#define MONSTA_GL_MINOR_VERSION 6
#endif

#define MONSTA_ENGINE_VERSION "0.0.1"

#endif /* LIB_MONSTA_CONFIG_H */