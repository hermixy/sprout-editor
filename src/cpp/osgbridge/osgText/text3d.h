#pragma once
#include <osgText/Text3D>
#include "textbase.h"

class Text3D : public TextBase
{
    Q_OBJECT
public:
    Text3D() {}
    void classBegin() override { osgObj = new osgText::Text3D; }
    osgText::Text3D* toOsg() { return static_cast<osgText::Text3D*>(osgObj); }
};
