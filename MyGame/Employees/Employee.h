#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
public:
    virtual ~Employee(){};
    //
    virtual void to_work(Resources &) = 0;
    virtual void gather_energy(Resources &) = 0;

protected:
    void add_energy(short n) { m_energy += n; };
    short get_energy() { return m_energy; };

private:
    short m_energy{70};
};

#endif