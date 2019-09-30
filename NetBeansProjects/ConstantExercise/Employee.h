/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Admin
 *
 * Created on January 10, 2019, 6:37 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
protected: //can be inherited and accessed by direct classes
    string m_FirstName;
    string m_LastName;
    string m_DepartmentName;
    unsigned short m_HiringYear;

public:
    Employee(const string& firstName, const string& lastName, const string& departmentName, const unsigned short hireYear) {
        m_FirstName = firstName;
        m_LastName = lastName;
        m_DepartmentName = departmentName;
        m_HiringYear = hireYear;      
    }
    string getFirstName() {
        return m_FirstName;
    }
};    
#endif /* EMPLOYEE_H */

