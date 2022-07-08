//  Copyright (c) 2014 Yan Chen.
//  All rights reserved.
//
//  Author: yan.chen.im@gmail.com (Yan Chen)

#include <readline/history.h>
#include <readline/readline.h>

#include <algorithm>
#include <iostream>
#include <string>

#include "interpreter.h"

using namespace std;
std::string &trim(std::string &s) {
  if (s.empty()) {
    return s;
  }
  s.erase(0, s.find_first_not_of(" "));
  s.erase(s.find_last_not_of(" ") + 1);
  return s;
}
int main(int argc, const char *argv[]) {
  string sql;
  Interpreter itp;

  char *line;
  size_t found;

  using_history();

  while (true) {
    line = readline("MiniDB> ");
    sql = string(line);
    free(line);
    trim(sql);

    if (sql.compare(0, 4, "exit") == 0 || sql.compare(0, 4, "quit") == 0) {
      itp.ExecSQL("quit");
      break;
    }

    while ((found = sql.find(";")) == string::npos) {
      line = readline("");
      sql += "\n" + string(line);
      free(line);
    }

    if (sql.length() != 0) {
      add_history(sql.c_str());
    }

    itp.ExecSQL(sql);
    std::cout << std::endl;
  }
  return 0;
}
