#ifndef REGISTRY_H
#define REGISTRY_H

#include <QVector>

template<class G>
class Registry
{
public:
    static QVector<G> generators()
    {
        return generatorVector();
    }

    static void addGenerator(G g)
    {
        generatorVector() << g;
    }

private:
    Registry();
    Registry(const Registry&);
    Registry& operator=(const Registry&);

    static QVector<G>& generatorVector() {
        static QVector<G> generators;
        return generators;
    }
};

template<class G>
class Registrator
{
public:
    Registrator(G g)
    {
        Registry<G>::addGenerator(g);
    }
};

#endif // REGISTRY_H

