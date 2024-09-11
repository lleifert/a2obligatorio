#ifndef TABLE_H
#define TABLE_H

template <class K, class V>
class Table
{
public:
    virtual void insert(K key, V value) = 0;
    virtual V get(K key) = 0;
    virtual int getBucketNumRepeticiones(int indice) = 0;
    virtual bool exists(K key) = 0;
    virtual void remove(K key) = 0;
};

#endif