#include <string>
class Person
{
    int items;
    std::string name;
public:
    Person(std::string name, int items)
        : name(name), items(items)
    {
    }
    ~Person()
    {
        name.clear();
    }
    void setItems(int numItems)
    {
        items = numItems;

    }
    std::string getName()
    {
        return name;
    }
    int getItems()
    {
        return items;
    }
};

