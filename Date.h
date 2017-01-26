//
//  Date.h
//  Date
//
//  Created by Shelley Dogra on 1/23/17.
//  Copyright © 2017 Shelley Dogra. All rights reserved.
//

#ifndef Date_h
#define Date_h

class Date {
    
public:
    Date ();
    Date (int, int, int);
    
    void display();
    
    int GetMonth();
    void SetMonth(int);
    
    int GetDay();
    void SetDay( int);
    
    int GetYear();
    void SetYear(int);
    
    void setDate(int, int, int);
    
    ~Date();
    
    Date operator+ ( int );
    Date operator- ( int );
    
    bool leapYear( int );
    
    
    
private:
    int month, day, year;
    
    
};


#endif /* Date_h */
