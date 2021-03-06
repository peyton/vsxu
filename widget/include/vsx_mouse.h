/**
* Project: VSXu: Realtime modular visual programming language, music/audio visualizer.
*
* This file is part of Vovoid VSXu.
*
* @author Jonatan Wallmander, Robert Wenzel, Vovoid Media Technologies AB Copyright (C) 2003-2013
* @see The GNU Public License (GPL)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef __vsx_mouse__
#define __vsx_mouse__
#ifdef _WIN32
#include <windows.h>
#endif

#include <vector/vsx_vector3.h>

#include "vsx_widget_dllimport.h"
#define MOUSE_CURSOR_ARROW 0
#define MOUSE_CURSOR_HAND 1
#define MOUSE_CURSOR_IBEAM 2
#define MOUSE_CURSOR_SIZE 3
#define MOUSE_CURSOR_NS 4
#define MOUSE_CURSOR_WE 5
#define MOUSE_CURSOR_NESW 6
#define MOUSE_CURSOR_NWSE 7
class WIDGET_DLLIMPORT vsx_mouse
{
  int cursor;
  bool visible;
  vsx_vector3<> position;
  void set_cursor_implement();

public:

  void set_cursor(int id);
  vsx_vector3<> get_cursor_pos() __attribute__((always_inline))
  {
    return position;
  }

  void set_cursor_pos(float x, float y);
  void show_cursor();
  void hide_cursor();
  vsx_mouse();
};

#endif

