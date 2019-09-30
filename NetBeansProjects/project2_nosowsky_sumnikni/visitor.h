#ifndef VISITOR_H
#define VISITOR_H
#include <QString>
#include<QTableWidget>


class Visitor{
public:
    Visitor(){}
    virtual ~Visitor(){}
    virtual double VisitTable(QTableWidget*)=0;
};
#endif // VISITOR_H
