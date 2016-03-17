#ifndef REGISTRY_H
#define REGISTRY_H

#include <QVector>

template< class G >
class Registry
{
public:
    static void addGenerator( G g ) {
        theInstance().m_generators << g;
    }
    static QVector<G> generators() {
        return theInstance().m_generators;
    }

private:
    Registry() {}
    Registry(const Registry&);
    Registry& operator=(const Registry&);

    QVector<G> m_generators;

    static Registry& theInstance() {
        static Registry registry;
        return registry;
    }
};

template< class G >
class Registrator
{
public:
    explicit Registrator(G g) {
        Registry<G>::addGenerator(g);
    }
};

#endif // REGISTRY_H
