#ifndef TABLEVISITOR_H
#define TABLEVISITOR_H
#include "visitor.h"
#include <QDebug>
class TableVisitor: public Visitor{
public:
    TableVisitor(){}
    virtual ~TableVisitor(){}
    virtual double VisitTable(QTableWidget* qw){
        double total = 0;
        for(int i = 0;i < qw->rowCount();i++)
            total += qw->item(i, 1)->text().toDouble();
        qDebug() << total;
        return total;
    }
};
#endif // TABLEVISITOR_H
