#ifndef SCOPEDINC_H
#define SCOPEDINC_H

class ScopedInc
{
public:
    explicit ScopedInc(int& x) : x(x) {
        ++x;
    }
    ~ScopedInc() {
        --x;
    }

private:
    int& x;
};

#endif // SCOPEDINC_H

