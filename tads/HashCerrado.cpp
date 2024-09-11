#ifndef HASH_CERRADO
#define HASH_CERRADO

#include <iostream>
#include "Table.h"
using namespace std;

template <class K, class V>
class HashCerrado : public Table<K, V>
{
private:
    struct ClaveValor
    {
        K key;
        V value;
        int numRepeticiones;
        ClaveValor(K unKey, V unValue, int unNumRepeticiones) : key(unKey), value(unValue), numRepeticiones(unNumRepeticiones) {}
    };

    ClaveValor **arr;

    int (*hash)(K);

    int buckets;

    int getBucket(K key, int i)
    {
        int n = this->hash(key);
        return abs((n+i) % this->buckets);
    }

    void insertRec(int i, K key, V value)
    {
        int bucket = getBucket(key, i);
        if (arr[bucket] == NULL)
        {
            arr[bucket] = new ClaveValor(key, value, 1);            
        }
        else if (arr[bucket]->key == key)
        {
            arr[bucket]->value = value;
            arr[bucket]->numRepeticiones = arr[bucket]->numRepeticiones + 1;
        }
        else
        {
            insertRec(i+1, key, value);
        }
    }

    V getRec(int i, K key)
    {
        int bucket = getBucket(key, i);
        if (arr[bucket]->key == key)
        {
            return arr[bucket]->value;
        }
        else
        {
            return getRec(i+1, key);
        }
    }

    bool existsRec(int i, K key)
    {
        int bucket = getBucket(key, i);
        if (arr[bucket] == NULL)
        {
            return false;
        }
        else if (arr[bucket]->key == key)
        {
            return true;
        }
        else
        {
            return existsRec(i+1, key);
        }
    }

public:
    HashCerrado(int capInicial, int (*_hash)(K))
    {
        this->arr = new ClaveValor *[capInicial]();
        hash = _hash;
        for (int i=0; i<capInicial; i++)
        {
            arr[i] = NULL;
        }
        buckets = capInicial;
    }
    
    void insert(K key, V value)
    {
        return this->insertRec(0, key, value);
    }

    V get(K key)
    {
        assert(this->exists(key));
        return this->getRec(0, key);
    }

    int getBucketNumRepeticiones(int indice)
    {
        if (this->arr[indice] == 0)
        {
            return 0;
        }
        else
        {
            return this->arr[indice]->numRepeticiones;    
        }
    }

    bool exists(K key)
    {
        return this->existsRec(0, key);
    }

    void remove(K key)
    {
        return;
    }
};

#endif