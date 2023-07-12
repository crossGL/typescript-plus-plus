// Copyright (c) 2021-2023 ChilliBits. All rights reserved.

#include "utils/CommonUtil.h"

namespace ts::compiler {

/**
 * Search all occurrences of needle in haystack and replace them with the
 * replacement
 *
 * @param haystack Input string
 * @param needle String to search
 * @param replacement String to replace
 */
void CommonUtil::replaceAll(std::string &haystack, const std::string &needle,
                            const std::string &replacement) {
  size_t start_pos = 0;
  while ((start_pos = haystack.find(needle, start_pos)) != std::string::npos) {
    haystack.replace(start_pos, needle.length(), replacement);
    start_pos += replacement.length();
  }
}

/**
 * Split the given haystack by the needle and return the last fragment
 *
 * @param haystack Input string
 * @param needle String to search
 * @return Last fragment
 */
std::string CommonUtil::getLastFragment(const std::string &haystack,
                                        const std::string &needle) {
  const size_t index = haystack.rfind(needle);
  return index == std::string::npos ? haystack
                                    : haystack.substr(index + needle.length());
}

}  // namespace ts::compiler
