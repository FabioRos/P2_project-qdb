#ifndef UTILITA_H
#define UTILITA_H

//PER ORA MAI UTILIZZATO

#include <string>
using namespace std;

template <typename T>
string NumberToString ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}

template <typename T>
T StringToNumber ( const string &Text )//Text not by const reference so that the function can be used with a
{                               //character array as argument
    stringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}

#endif // UTILITA_H
