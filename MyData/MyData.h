#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#ifdef MYDATA_EXPORTS
#define MYDATA_API __declspec(dllexport)
#else
#define MYDATA_API __declspec(dllimport)
#endif

#include "resource.h" // main symbols

class CMyDataApp : public CWinApp
{
public:
    CMyDataApp();

    // Overrides
public:
    virtual BOOL InitInstance();

    DECLARE_MESSAGE_MAP()
};

#pragma pack(push, 1)
class CExcept1App;

class MYDATA_API MY_POINT
{
public:
    double x;
    double y;
    char* name = nullptr;
    int numb;
    COLORREF color;

    MY_POINT() : x(0), y(0), name(nullptr), numb(0), color(RGB(200, 200, 200)) {}

    MY_POINT(double xx, double yy, const char* _name = nullptr, int _numb = 0, COLORREF _color = RGB(200, 200, 200))
        : x(xx), y(yy), numb(_numb), color(_color)
    {
        if (_name) {
            name = new char[strlen(_name) + 1];
            strcpy_s(name, strlen(_name) + 1, _name);
        }
        else {
            name = nullptr;
        }
    }

    MY_POINT(const MY_POINT& other) // Konstruktor kopiuj¹cy
    {
        x = other.x;
        y = other.y;
        numb = other.numb;
        color = other.color;
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy_s(name, strlen(other.name) + 1, other.name);
        }
        else {
            name = nullptr;
        }
    }

    MY_POINT& operator=(const MY_POINT& other) // Operator przypisania
    {
        if (this == &other) return *this;

        delete[] name;

        x = other.x;
        y = other.y;
        numb = other.numb;
        color = other.color;
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy_s(name, strlen(other.name) + 1, other.name);
        }
        else {
            name = nullptr;
        }

        return *this;
    }

    ~MY_POINT()
    {
        if (name) {
            delete[] name;
            name = nullptr;
        }
    }

    void set(double xx, double yy, const char* _name = nullptr, int _numb = 0, COLORREF _color = RGB(200, 200, 200))
    {
        x = xx;
        y = yy;
        numb = _numb;
        color = _color;

        delete[] name;
        if (_name) {
            name = new char[strlen(_name) + 1];
            strcpy_s(name, strlen(_name) + 1, _name);
        }
        else {
            name = nullptr;
        }
    }

    MY_POINT get() { return *this; }

    bool operator==(const CString& key) const {
        return CString(name) == key;
    }
};

class MYDATA_API MY_DATA : public MY_POINT
{
protected:
    MY_POINT* pTab;
    int capacity;
    int last;
public:
    CExcept1App* pExcept;
public:
    MY_DATA(int no_it);
    MY_DATA(const MY_DATA& ob);
    ~MY_DATA() { Free(); }
    void Free() { if (pTab) delete[] pTab; pTab = NULL; }
    void Init(int no_it);
    void Push(const MY_POINT& tmp);
    int size() { return last; }
    void clear() { last = 0; }

    MY_POINT& operator [] (const int i)
    {
        return pTab[i];
    }

    void GetMaxMinCoords(double& max_x, double& min_x, double& max_y, double& min_y);

private:
    MY_POINT* allocTab(MY_POINT* pTab, int i);
};

#pragma pack(pop)
