#include <string>
#include <vector>

bool parenthesis_match(const std::string &s) {
  std::vector<char> chars{};
  for (char a : s) {
    if (a == '(' || a == '[' || a == '{')
      chars.push_back(a);
    else {
      if (chars.empty())
        return false;

      char c = chars.back();
      chars.pop_back();

      switch (a) {
      case ')':
        if (c != '(')
          return false;
        break;
      case ']':
        if (c != '[')
          return false;
        break;
      case '}':
        if (c != '{')
          return false;
        break;
      }
    }
  }

  if (!chars.empty())
    return false;

  return true;
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
  else if (parenthesis_match(")(()") != 0)
    return 5;
  else if (parenthesis_match("([{}])") != 1)
    return 6;
  else if (parenthesis_match("([)]") != 0)
    return 7;
}
