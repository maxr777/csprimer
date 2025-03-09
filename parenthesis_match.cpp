#include <string>
#include <vector>

bool parenthesis_match(const std::string &s) {
  std::vector<char> chars(s.size());
  for (auto &a : s) {
    chars.push_back(a);
  }

  ZZ

      return false;
}

int main() {
  if (parenthesis_match("()") != 1)
    return 1;
  else if (parenthesis_match("(()") != 0)
    return 2;
  else if (parenthesis_match("(())") != 1)
    return 3;
  else if (parenthesis_match("()()") != 1)
    return 4;
  else if (parenthesis_match(")(()") != 1)
    return 5;
  else if (parenthesis_match("([{}])") != 1)
    return 6;
  else if (parenthesis_match("([)]") != 0)
    return 7;
}
