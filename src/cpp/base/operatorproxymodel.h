#pragma once
#include <QtCore>

class OperatorProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit OperatorProxyModel();
    Q_INVOKABLE void setFilterPattern(const QString& pattern);
    Q_INVOKABLE int sourceIndex(int row);
};