#include<bits/stdc++.h>
using namespace std;

class AbstractEmployee{  // Abstraction 
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee{
private:        // Encapsulation
    string Company;
    int Age;
protected:
    string Name;  // makes available to my derived class of Employee.
public:  
    void setName(string name){ // setter
        Name = name;
    } 
    string getName(){  // getter
        return Name;
    }
    void setCompany(string company){
        Company = company;
    } 
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        if(age >= 18)
        Age = age;
    } 
    int getAge(){
        return Age;
    }
    void introduceYourself(){
        cout << "Name " << Name << "\n";
        cout << "Company " << Company << "\n";
        cout << "Age " << Age << "\n";
    }   
    // Constructor
    Employee(string name,string company,int age){
        Name = name;
        Company = company;
        Age = age;
    } 
    void AskForPromotion(){
        if(Age > 30){
            cout << Name << " got promoted " << "\n";
        }
        else{
            cout << Name << " , sorry no promotion for you " << "\n";
        }
    } 
    virtual void Work(){
        cout << Name << " is writing tasks " << endl;
    }   
};

class Developer: public Employee{
public:
    string FavProgrammingLanguage;
    Developer(string name,string company,int age,string favProgrammingLanguage)
    :Employee(name,company,age) // giving parent parameters
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void fixBug(){
       // cout << getName() << " fixed bug using " << FavProgrammingLanguage << "\n";
       cout << Name << " fixed a bug using " << FavProgrammingLanguage << "\n";
    }
    void Work(){
        cout << Name << " is writing " << FavProgrammingLanguage << " code" << endl;
    }  

};
class Teacher: public Employee {
public:    
    string Subject;
    void PrepareLesson(){
        cout << Name << " is preparing " << Subject <<" lesson " << endl;
    }
    Teacher(string name,string company,int age,string subject)
    :Employee(name,company,age)
    {
        Subject = subject;

    }
    void Work(){
        cout << Name << " is preparing " << Subject  << endl;
    }  
    


};
int main(){
   // Employee employee1 = Employee("Rajat","Google",19);
   // Employee employee2 = Employee("Akshat","Amazon",11);
    //employee1.name = "Rajat";
    //employee1.company = "Google";
    //employee1.age = 19;
    //employee1.AskForPromotion();
    //employee2.AskForPromotion();
    Developer d = Developer("Rajat","Google",19,"Javascript");
    //d.fixBug();
    // if we use public in my developer i am able to access AskForPromotion method
    Teacher t = Teacher("Jack","Cool",34,"History");
    //t.PrepareLesson();
    // The most common use of polymorphism is when a parent class reference is used to refer to a child class object
    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();
    
    
}