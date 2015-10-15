#pragma once
#include <osg/Drawable>
#include "object.h"

class Drawable : public Object
{
    Q_OBJECT
public:
    void classBegin() override;
    osg::Drawable* toOsg() { return static_cast<osg::Drawable*>(osgObj.get()); }
};

