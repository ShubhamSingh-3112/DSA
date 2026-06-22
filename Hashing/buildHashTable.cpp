#include <iostream>
using namespace std;
#include <string>

class Node
{
public:
    string key;
    int value;
    Node *next;
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class HashTable
{
public:
    Node **head;
    int totalSize;
    int curSize;
    HashTable(int size)
    {
        this->totalSize = size;
        this->curSize = 0;
        head = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            head[i] = NULL;
        }
    }

    int hash(string key)
    {
        int idx = 0;
        for (int i = 0; i < key.size(); i++)
        {
            idx = (idx * 31 + key[i]) % totalSize;
        }
        return idx % totalSize;
    }

    void rehash()
    { // O(n)
        int oldSize = totalSize;
        Node **oldHeads = head;

        totalSize = 2 * totalSize;
        head = new Node *[totalSize];
        curSize = 0;

        for (int i = 0; i < totalSize; i++)
        {
            head[i] = NULL;
        }

        for (int i = 0; i < oldSize; i++)
        {
            Node *temp = oldHeads[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if (oldHeads[i] != NULL)
            {
                delete oldHeads[i];
            }
        }
        delete[] oldHeads;
    }

    void insert(string key, int value)
    {
        int idx = hash(key);
        Node *newNode = new Node(key, value);
        newNode->next = head[idx];
        head[idx] = newNode;
        curSize += 1;

        double lambda = curSize / (double)totalSize;
        if (lambda > 1)
        {
            rehash(); // O(n)
        }
    }

    int search(string key)
    {
        int idx = hash(key);
        Node *temp = head[idx];
        while (temp != NULL && temp->key != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Key does not exists" << endl;
            return -1;
        }
        cout << temp->value << endl;
        return temp->value;
    }

    void remove(string key)
    {
        int idx = hash(key);
        Node *temp = head[idx];
        Node *prev = NULL;
        while (temp != NULL && temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Key does not exists" << endl;
            return;
        }

        if (temp == head[idx])
        {
            head[idx] = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }

        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }

    void display()
    {
        for (int i = 0; i < totalSize; i++)
        {
            if (head[i] != NULL)
            {
                cout << i << ":";
                Node *temp = head[i];
                while (temp != NULL)
                {
                    cout << temp->key << ":" << temp->value << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};
int main()
{
    HashTable ht(1);
    ht.insert("india", 150);
    ht.insert("nepal", 10);
    ht.insert("bhutan", 20);
    ht.insert("pak", 30);
    ht.insert("china", 110);
    ht.insert("indone", 110);

    ht.display();

    cout << ht.totalSize << endl;

    cout << "Nepal Population:";
    ht.search("nepal");

    ht.remove("india");
    ht.display();
}
