#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  ifstream file;
  ofstream out("/root/code/CPP_learn/test_file/file2", fstream::out); // implicitly trunc mode
  string str;
  // get one character per loop, but skip blanks
  file.open("/root/code/CPP_learn/test_file/file1", fstream::in);
  if (file.is_open())
  {
    char c;
    while (file >> c)
    {
      cout << c;
    }
  }
  cout << endl;
  cout << file.eof() << ' ' << file.fail() << ' ' << file.bad() << endl;
  file.close();
  cout << file.eof() << ' ' << file.fail() << ' ' << file.bad() << endl;
  // close do not clear the state bits

  file.clear();
  cout << file.eof() << ' ' << file.fail() << ' ' << file.bad() << endl;

  file.open("/root/code/CPP_learn/test_file/file1.none");
  cout << file.eof() << ' ' << file.fail() << ' ' << file.bad() << endl;
  file.close();

  file.open("/root/code/CPP_learn/test_file/file1");
  cout << file.eof() << ' ' << file.fail() << ' ' << file.bad() << endl;
  // open a file successfully sets good bit
  file.close();

  file.open("/root/code/CPP_learn/test_file/file2");
  file.tie(&out);

  out << "1234567" << ends;
  file >> str;
  cout << str << endl;
  file.seekg(fstream::beg);

  out.close();
  out.open("/root/code/CPP_learn/test_file/file2", fstream::app);
  out << "123" << ends;
  out << "123" << ends;
  file >> str;
  cout << str << endl;
  file.seekg(fstream::beg);

  out.close();
  out.open("/root/code/CPP_learn/test_file/file2", fstream::trunc);
  out << "123";
  out << "2131231" << ends;
  file >> str;
  cout << str << endl;
  file.seekg(fstream::beg);

  cout << endl;
  return 0;
}