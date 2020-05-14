#include <string>

bool is_vowel( char character )
{
  char ch = tolower(character);
  return ch == 'a' || ch == 'e' || ch == 'i' ||
         ch == 'o' || ch == 'u' || ch == 'y';
}