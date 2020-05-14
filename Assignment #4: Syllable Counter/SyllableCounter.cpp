#include <iostream>
#include <iomanip>
#include <fstream>
#include "assn.h"

bool sentenceEnd(char ch)
{
    if (ch == '.' || ch == ':' ||
        ch == ';' || ch == '?' ||
        ch == '!')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string line, input;
    // reads line from .txt file
    std::ifstream myfile("input.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            input = line;
        }
        myfile.close();
    }

    int i = 0, wordCount = 1, syllableCount = 1, sentenceCount = 0;
    while (i != input.size() - 1)
    {
        // assuming there will always be 1 word, adds 1 to wordCount when 'space' is detected
        if (input[i] == ' ')
        {
            wordCount++;
        }
        // assuming there will always be 1 syllable, if vowel is detected, add 1 to syllableCount
        if (is_vowel(input[i]))
        {
            syllableCount++;
        }
        // if two vowels are adjacent, count as one syllable
        if ((is_vowel(input[i])) && (is_vowel(input[i + 1])))
        {
            syllableCount--;
        }
        if ((input[i] == input[i + 1]) && (is_vowel(input[i])))
        {
            syllableCount++;
        }
        if ((is_vowel(input[i]) == false) && (input[i - 1] == ' ') && (sentenceEnd(input[i + 1])))
        {
            syllableCount++;
        }
        // assuming there will always be 1 sentence
        // checks if next. pos. is a '.', ':', ';', '?', or '!'
        if (sentenceEnd(input[i + 1]))
        {
            sentenceCount++;
        }
        // for multiple instances of '.', ':', ';', '?', or '!', deduct count
        if ((sentenceEnd(input[i])) && (sentenceEnd(input[i + 1])))
        {
            sentenceCount--;
        }
        i++;
    }
    if (sentenceEnd(input.back()) == false || (wordCount == syllableCount))
    {
        sentenceCount++;
    }
    if (sentenceCount > 1)
    {
        sentenceCount--;
    }
    if (syllableCount > 1)
    {
        syllableCount--;
    }
    if (wordCount > syllableCount >= sentenceCount)
    {
        syllableCount = wordCount;
    }

    double index = 206.835 - 84.6 * syllableCount / wordCount - 1.105 * wordCount / sentenceCount;

    std::cout << "Words: " << wordCount << std::endl;
    std::cout << "Syllables: " << syllableCount << std::endl;
    std::cout << "Sentences: " << sentenceCount << std::endl;
    std::cout << "Legibility Index: " << std::fixed << std::setprecision(0) << index << std::endl;

    return 0;
}
