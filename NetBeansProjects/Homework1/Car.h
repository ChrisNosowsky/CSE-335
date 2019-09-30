/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.h
 * Author: Admin
 *
 * Created on January 10, 2019, 7:58 PM
 */

#ifndef CAR_H
#define CAR_H

class Car{
protected:
    string m_Make;
    string m_Model;
    unsigned int m_Year;
    unsigned int m_GasMileage;
public:
    Car(const string& make, const string& model, const unsigned int& year, const unsigned int& gasMileage) {
        m_Make = make;
        m_Model = model;
        m_Year = year;
        m_GasMileage = gasMileage;
    }

    string getCarMake() const { //constant member functions
        return m_Make;
    }
    string getCarModel() const {
        return m_Model;
    }
    unsigned int getYear() const {
        return m_Year;
    }
    unsigned int getGasMileage() const {
        return m_GasMileage;
    }
    
    

};
#endif /* CAR_H */

