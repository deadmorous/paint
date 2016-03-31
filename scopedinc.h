#ifndef SCOPEDINC_H
#define SCOPEDINC_H

class ScopedInc
{
private:
    int& counter;
public:
    explicit ScopedInc(int& counter) : counter(counter)
    {
        ++counter;
    }
    ~ScopedInc()
    {
        --counter;
    }
};

#endif // SCOPEDINC_H

