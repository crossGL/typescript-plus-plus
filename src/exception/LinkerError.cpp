// Copyright (c) 2021-2023 ChilliBits. All rights reserved.

#include "LinkerError.h"

namespace ts::compiler {

/**
 * @param type Type of the error
 * @param message Error message suffix
 */
LinkerError::LinkerError(const LinkerErrorType &type,
                         const std::string &message) {
  errorMessage = "[Error|Linker] " + getMessagePrefix(type) + ": " + message;
}

/**
 * Get the message for this particular error instance
 *
 * @return Error message in form of a char array
 */
const char *LinkerError::what() const noexcept { return errorMessage.c_str(); }

/**
 * Get the prefix of the error message for a particular error
 *
 * @param type Type of the error
 * @return Prefix string for the error type
 */
std::string LinkerError::getMessagePrefix(LinkerErrorType type) {
  switch (type) {
    case LINKER_NOT_FOUND:
      return "Linker not found";
    case LINKER_ERROR:
      return "Linker error occurred";
  }
  return "Unknown error";  // GCOV_EXCL_LINE
}

}  // namespace ts::compiler