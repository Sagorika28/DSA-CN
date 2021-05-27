#include <string>
#include <iostream>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    // to delete all the nodes of the linked list recursively
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **buckets;
    int count;
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];

        // to remove the garbage values
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    // first we delete the linked list at each bucket index and then we delete the whole bucket array
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    // searching
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0; // if we didn't find our value
    }

private:
    // to get hash function
    int getBucketIndex(string key)
    {
        int hashCode = 0; // using base p method: a*p^2 + b*p^1 + c*p^0

        int currentCoeff = 1; // p^0
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets; // to make sure it doesn't go out of integer range
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets; // to make sure it doesn't go out of integer range
        }

        return hashCode % numBuckets; // return the compression function result
    }

    // to rehash
    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets]; // increase bucket size
        for (int i = 0; i < (2 * numBuckets); i++)
        {
            buckets[i] = NULL; // empty the whole bucket
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        // tarverse each bucket
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            // check all the elements in the LL of each bucket and insert it in the new bucket
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        // delete the old temp bucket
        for (int i = 0; i < oldBucketCount; i++)
        {
            // delete the LL at each head
            MapNode<V> *head = temp[i];
            delete head; // gets deleted recursively
        }

        // delete the temp array
        delete[] temp;
    }

public:
    // print load factor
    double getLoadFactor()
    {
        return (1.0 * count) / numBuckets;
    }

    // inserting
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        // in case we find the key in the LL, we won't create a new entry, simply update the key value
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++; // incremented only when a new node is created

        // Rehashing-everytime we insert a new node, we need to check the load factor and rehash if load factor > 0.7
        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    // deleting
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next; // since we can not access the next of NULL
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL; // since we have made recursive deletion of node, we need to exclude it and break the chain
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0; // if we didn't find our value
    }
};

int main(int argc, char const *argv[])
{
    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
    }
    cout << map.size() << endl;

    map.remove("abc2");
    map.remove("abc7");

    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << ": " << map.getValue(key) << endl;
    }
    cout << map.size() << endl;
    return 0;
}