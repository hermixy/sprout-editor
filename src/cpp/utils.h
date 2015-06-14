#ifndef UTILS_H
#define UTILS_H

#include <QtCore>

class Utils : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString buildDate READ getBuildDate CONSTANT)

public:
    explicit Utils(QObject *parent = 0) { Q_UNUSED(parent) }
    QString getBuildDate() { return QString(__DATE__); }
    Q_INVOKABLE QString urlToPath(QUrl url);
    Q_INVOKABLE QString urlToFileName(QUrl url);
    Q_INVOKABLE QVariant loadSproutFile(const QString &filePath);
    Q_INVOKABLE void saveSproutFile(const QString filePath, const QVariant &fileData);
};

#endif // UTILS_H
