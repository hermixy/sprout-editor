#include "textbase.h"
#include <QDebug>
#include <osgText/Font>

void TextBase::classBegin()
{
    Drawable::classBegin();
    toOsg()->setAxisAlignment(osgText::TextBase::AxisAlignment::XZ_PLANE);
    toOsg()->setCharacterSize(0.15);
    toOsg()->setFont("fonts/times.ttf");
}

void TextBase::setText(QString text)
{
    if (toOsg()->getText().createUTF8EncodedString() == text.toStdString()) return;
    toOsg()->setText(text.toStdString());
    emit textChanged(text);
}