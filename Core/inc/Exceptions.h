#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class NotImplementedException : public std::logic_error
{
public:
    NotImplementedException(const std::string &message);
};

class NullPointerException : public std::logic_error
{
public:
    NullPointerException(const std::string& message);
};

class OutOfBoundsException : public std::logic_error
{
public:
    OutOfBoundsException(const std::string& message);
};

class ClassInitializationException : public std::runtime_error
{
public:
    ClassInitializationException(const std::string& message);
};

class SelfReferenceException : public std::logic_error
{
public:
    SelfReferenceException(const std::string &message);
};

#endif // EXCEPTIONS_H
