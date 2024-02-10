#include <iostream>
#include <string>

int main()
{
  wchar_t c = L'一';
  wchar_t en = 'a';
  std::wcout << c << " " << en << ' ' << L"一二三" << std::endl;
  return 0;
}