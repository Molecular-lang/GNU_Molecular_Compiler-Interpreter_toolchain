// { dg-do compile { target c++11 } }

// Copyright (C) 2016-2023 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <memory>
#include <type_traits>

static_assert(!std::is_default_constructible<std::unique_ptr<int,
	      std::default_delete<int>&>>::value, "");
static_assert(!std::is_default_constructible<std::unique_ptr<int,
	      void(*)(int*)>>::value, "");
static_assert(!std::is_constructible<std::unique_ptr<int,
	      std::default_delete<int>&>, int*>::value, "");
static_assert(!std::is_constructible<std::unique_ptr<int,
	      void(*)(int*)>, int*>::value, "");

static_assert(!std::is_default_constructible<std::unique_ptr<int[],
	      std::default_delete<int>&>>::value, "");
static_assert(!std::is_default_constructible<std::unique_ptr<int[],
	      void(*)(int*)>>::value, "");
static_assert(!std::is_constructible<std::unique_ptr<int[],
	      std::default_delete<int>&>, int*>::value, "");
static_assert(!std::is_constructible<std::unique_ptr<int[],
	      void(*)(int*)>, int*>::value, "");
