// Copyright (c) 2021-2023 ChilliBits. All rights reserved.

#pragma once

#include <Token.h>

#include <string>
#include <utility>

namespace ts::compiler {

struct CodeLoc {
 public:
  // Constructors
  CodeLoc(size_t line, size_t col, std::string sourceFilePath = "");
  explicit CodeLoc(const antlr4::Token *token, std::string sourceFilePath = "");

  // Public members
  std::string sourceFilePath;
  size_t line;
  size_t col;

  // Public methods
  [[nodiscard]] std::string toString() const;
  [[nodiscard]] std::string toPrettyString() const;
  [[nodiscard]] std::string toPrettyLine() const;
  [[nodiscard]] std::string toPrettyLineAndColumn() const;

  // Operators
  friend bool operator==(const CodeLoc &a, const CodeLoc &b) {
    return a.line == b.line && a.col == b.col;
  }
  friend bool operator<(const CodeLoc &a, const CodeLoc &b) {
    return a.line == b.line ? a.col < b.col : a.line < b.line;
  }
  friend bool operator>(const CodeLoc &a, const CodeLoc &b) {
    return a.line == b.line ? a.col > b.col : a.line > b.line;
  }
};

}  // namespace ts::compiler