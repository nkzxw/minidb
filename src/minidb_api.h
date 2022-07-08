//  Copyright (c) 2014 Yan Chen.
//  All rights reserved.
//
//  Author: yan.chen.im@gmail.com (Yan Chen)

#ifndef MINIDB_MINIDB_API_H_
#define MINIDB_MINIDB_API_H_

#include <string>

#include "buffer_manager.h"
#include "catalog_manager.h"
#include "sql_statement.h"

class MiniDBAPI {
 private:
  std::string path_;
  CatalogManager *cm_;
  BufferManager *hdl_;
  std::string curr_db_;

 public:
  MiniDBAPI(std::string p);
  ~MiniDBAPI();
  void Quit();
  void Help();
  void CreateDatabase(SQLCreateDatabase &st);
  void ShowDatabases();
  void DropDatabase(SQLDropDatabase &st);
  void DropTable(SQLDropTable &st);
  void DropIndex(SQLDropIndex &st);
  void Use(SQLUse &st);
  void CreateTable(SQLCreateTable &st);
  void ShowTables();
  void Insert(SQLInsert &st);
  void Select(SQLSelect &st);
  void CreateIndex(SQLCreateIndex &st);
  void Delete(SQLDelete &st);
  void Update(SQLUpdate &st);
};

#endif /* MINIDB_MINIDB_API_H_ */
