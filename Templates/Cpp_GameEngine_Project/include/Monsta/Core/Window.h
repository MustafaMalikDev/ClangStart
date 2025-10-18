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

#ifndef LIB_MONSTA_WINDOW_H
#define LIB_MONSTA_WINDOW_H

struct GLFWwindow;

namespace monsta::core
{

class window final
{
private:
  static unsigned int s_width;
  static unsigned int s_height;
  static const char* s_title;
  static GLFWwindow* s_window;

public:
  window () = delete;
  ~window () = delete;

public:
  static bool init ( unsigned int, unsigned int ) noexcept ( false );
  static void start () noexcept ( false );
  static void close ();

  static void set_title ( const char* ) noexcept;

public:
  static GLFWwindow* get_core_window () noexcept;
  static unsigned int get_width () noexcept;
  static unsigned int get_height () noexcept;
};

}

#endif /* LIB_MONSTA_WINDOW_H */