/*
 * @Author: your name
 * @Date: 2021-07-24 00:41:43
 * @LastEditTime: 2021-07-24 00:57:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/desgin_mode/include/Proxy.h
 */
#include "public.h"
#include <iostream>
using namespace std;
class Iimage
{
public:
    virtual ~Iimage() = default;
    virtual void display() = 0;
};

class CRealImage : public Iimage
{

private:
    string name;

public:
    CRealImage() = default;
    CRealImage(string name)
    {
        this->name = name;
        LoadFromDisk(name);
    };

    virtual void display() override
    {
        cout << "Displaying: " << name << endl;
    }

    void LoadFromDisk(string filename)
    {
        cout << "Loading: " << filename << endl;
    }
    virtual ~CRealImage() = default;
};

class Proxy : public Iimage
{
private:
    shared_ptr<CRealImage> cRealImage;
    string filename;

public:
    ~Proxy() = default;
    Proxy(string name) : filename(name){};
    virtual void display() override
    {
        if (cRealImage.get() == NULL)
        {
            cRealImage = make_shared<CRealImage>(filename);
        }
        cRealImage->display();
    }
};