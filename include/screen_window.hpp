#ifndef _SCREEN_WINDOWS_HPP
#define _SCREEN_WINDOWS_HPP

#include <iostream>
#include <string>
#include <vector>

class Screen;

class Windows {
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clean(ScreenIndex);
  ScreenIndex ret_a_scope_name(ScreenIndex);

private:
  std::vector<Screen> screens;
};

class Screen {
public:
  using pos = std::string::size_type;

private:
  using pri_pos = std::string::size_type;

  std::string contents;
  pos height = 0, width = 0;
  mutable pos cursor = 0;
  // mutable members can be changed even if the class object itself were const

public:
  Screen() = default;
  Screen(const std::string &con, pos hi, pos wi)
      : contents(con), height(hi), width(wi) {}
  Screen(const std::string &con)
      : contents(con), height(1), width(con.size()), cursor(0) {}
  Screen(pos hi = 0, pos wi = 0) : height(hi), width(wi) {}
  Screen(std::istream &is) // just initialize by content
  {
    read(is, *this);
    height = 1;
    width = contents.size();
    cursor = 0;
  }

  bool set_size(pos hi, pos wi) {
    // no fault condition
    height = hi;
    // no fault condition
    width = wi;
    return true;
  }

  bool set_cursor(pos cur) const {
    if (cur >= contents.size())
      return false;
    cursor = cur;
    return true;
  }

  char get_cursor_content() const {
    return contents.size() ? contents[cursor] : '\0';
  }

  friend std::istream &read(std::istream &is, Screen &scr);
  friend std::ostream &print(std::ostream &os, const Screen &scr);

  // q: why we can use ScreenIndex to declare the parameter of clean, as it's a
  // type alias in Windows class' scope a: because once beyond the the windows::
  // make the scope be seen, the remain of the declaration can see the scope
  friend void Windows::clean(ScreenIndex);
  friend Windows::ScreenIndex Windows::ret_a_scope_name(ScreenIndex);
};

std::istream &read(std::istream &is, Screen &scr);
std::ostream &print(std::ostream &os, const Screen &scr);

// Screen::pri_pos a;   can not access because of the same access control as
// other members Screen::pos a;

#endif