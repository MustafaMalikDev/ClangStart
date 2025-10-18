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

#ifndef LIB_MONSTA_KEYBOARD_H
#define LIB_MONSTA_KEYBOARD_H

namespace monsta::events
{

class keyboard final
{
public:
  keyboard () = delete;
  ~keyboard () = delete;

public:
  static bool is_key_pressed ( int ) noexcept;
  static bool is_key_down ( int ) noexcept;

  static int get_key_pressed () noexcept;
  static int get_key_down () noexcept;

  static bool is_key_up ( int ) noexcept;
};

}

#endif /* LIB_MONSTA_KEYBOARD_H */