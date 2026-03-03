/*!
 ***************************************************************************
 * \file GroceryStore.cpp
 *
 * \author Caleb LaRue
 *
 * \brief This is the main controller and simulation tool for the midterm exam
 *
 *
 ****************************************************************************
 */
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <iterator>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <type_traits>
#include <vector>
#include <iostream>
#include "Person.h"
#include <ctime>
#include <random>
using std::rand;
using std::string;

void Simulate(std::vector<std::deque<Person>>& store);
int CustomerWantsToChangeLanes(std::vector<int>& numPeopleInLine, std::vector<int>& numItems, int laneNum);
bool TestCustomerWantsToChangeLanes();
void print(std::vector<std::deque<Person>>& store);
Person randomPersonGenerator();

int main()
{
    std::deque<Person> Lane1; //portmanteau double-ended queue (NOT a single-ended queue)
    
    std::deque<Person> Lane2;
    std::deque<Person> Lane3;
    std::deque<Person> Lane4;
    std::deque<Person> Lane5;
    std::deque<Person> Lane6;
    std::deque<Person> Lane7;
    std::deque<Person> Lane8;
    std::deque<Person> Lane9;
    std::deque<Person> Lane10;
    std::deque<Person> Lane11;
    std::deque<Person> Lane12;
    std::deque<Person> Lane13;
    std::deque<Person> Lane14;
    std::deque<Person> Lane15;
    std::deque<Person> Lane16;
    std::deque<Person> Lane17;
    std::deque<Person> Lane18;

    std::vector<std::deque<Person>> Store;
    Lane1.push_back(Person("Bob", 14));
    Lane1.push_back(Person("Allice", 45));
    Lane1.push_back(Person("Mark", 15));
    Lane1.push_back(Person("Cameron", 35));
    Lane1.push_back(Person("Darth", 85));

    Lane2.push_back(Person("Bob", 14));
    Lane2.push_back(Person("Allice", 45));
    Lane2.push_back(Person("Mark", 15));
    Lane2.push_back(Person("Cameron", 35));
    Lane2.push_back(Person("Darth", 85));

    for (int i = 0; i < 15; i++)
    {
        Lane3.push_back(randomPersonGenerator());
        Lane4.push_back(randomPersonGenerator());
        Lane5.push_back(randomPersonGenerator());
        Lane6.push_back(randomPersonGenerator());
        Lane7.push_back(randomPersonGenerator());
        Lane8.push_back(randomPersonGenerator());
        Lane9.push_back(randomPersonGenerator());
        Lane10.push_back(randomPersonGenerator());
        Lane11.push_back(randomPersonGenerator());
    }
    for (int i = 0; i < 20; i++)
    {
        Lane12.push_back(randomPersonGenerator());
        Lane13.push_back(randomPersonGenerator());
        Lane14.push_back(randomPersonGenerator());
        Lane15.push_back(randomPersonGenerator());
        Lane16.push_back(randomPersonGenerator());
        Lane17.push_back(randomPersonGenerator());
        Lane18.push_back(randomPersonGenerator());
    }

    Store.push_back(Lane1);
    Store.push_back(Lane2);
    Store.push_back(Lane3);
    Store.push_back(Lane4);
    Store.push_back(Lane5);
    Store.push_back(Lane6);
    Store.push_back(Lane7);
    Store.push_back(Lane8);
    Store.push_back(Lane9);
    Store.push_back(Lane10);
    Store.push_back(Lane11);
    Store.push_back(Lane12);
    Store.push_back(Lane13);
    Store.push_back(Lane14);
    Store.push_back(Lane15);
    Store.push_back(Lane16);
    Store.push_back(Lane17);
    Store.push_back(Lane18);

    /*int i = 0;
    for(auto& person : Lane1)
    {
        printf("%s is the %d position\n" , person.getName().c_str(), i);
        i++;
    }
    */

    int numIterations = 0;
    for (auto& Lane : Store)
    {
        while (Lane.size() != 0)
        {
            Simulate(Store);
            printf("Grocery store iteration number %d\n", numIterations + 1);
            numIterations++;
        }

    }
    printf("GroceryStore sim is finished\n");




}
int CustomerWantsToChangeLanes(std::vector<int>& numPeopleInLine, std::vector<int>& numItems, int laneNum)
{
    std::vector<int>::iterator m_MinElement;
    //if(std::min_element(m_numOfPeopleInLine.begin(),m_numOfPeopleInLine.end()) < std::max_element(m_numOfPeopleInLine.begin(), m_numOfPeopleInLine.end()) - 2 
     //       && 
     /*for(int i = 0; i < numPeopleInLine.size(); i++)
     {
         if(true)
     }*/
    m_MinElement = std::min_element(numPeopleInLine.begin(), numPeopleInLine.end());
    int indexOfMinElement = std::distance(numPeopleInLine.begin(), m_MinElement);
    if (numPeopleInLine[laneNum] > *m_MinElement - 2
        && numItems[laneNum] > numItems[indexOfMinElement] + 15)
    {
        return indexOfMinElement;
    }
    else
    {
        return -1;
    }
}

void Simulate(std::vector<std::deque<Person>>& store)
{
    std::vector<int> m_numOfPeopleInLine;
    std::vector<int> m_totalItems;
    std::srand(std::time(nullptr));
    printf("The front of the Lines\n");
    for (auto& lane : store)
    {
        if (!lane.empty())
        {
            int randInt = rand() % 60 + 1;
            int totalItems;

            lane.front().setItems(lane.front().getItems() - randInt);
            if (lane.front().getItems() <= 0)
            {
                lane.pop_front();
            }
            printf("%s 's number of items is: %d \n", lane.front().getName().c_str(),
                lane.front().getItems());
            for (Person p : lane)
            {
                totalItems += p.getItems();
            }
            m_numOfPeopleInLine.push_back(lane.size());
            m_totalItems.push_back(totalItems);
        }
    }

    //Changing lanes of one customer at a time
    for (int i = 0; i < store.size(); i++)
    {
        if (!store[i].empty())
        {
            int laneToChangeTo = CustomerWantsToChangeLanes(m_numOfPeopleInLine, m_totalItems, i);
            if (laneToChangeTo > -1)
            {
                Person p = store[i].back();
                m_numOfPeopleInLine[i]--;
                m_totalItems[i] -= p.getItems();
                printf("%s is swithing lanes to %d\n", p.getName().c_str(), laneToChangeTo);
                store[i].pop_back();
                store[laneToChangeTo].push_back(p);
                m_numOfPeopleInLine[laneToChangeTo]++;
                m_totalItems[laneToChangeTo] += p.getItems();

            }
        }
    }
    print(store);


}
void print(std::vector<std::deque<Person>>& store)
{
    printf("\n\n-------------------------------------------------\n");
    printf("|\tLane \t| Numbers of Customers in Line  |\n");
    for (int i = 0; i < store.size(); i++)
    {
        printf("|\t%d \t| %17zu \t\t|\n", i, store[i].size());
    }
    printf("-------------------------------------------------\n\n");
}
bool TestCustomerWantsToChangeLanes()
{
    std::vector<int> numPeopleInLine;
    std::vector<int> numItems;
    numPeopleInLine.push_back(5);
    numPeopleInLine.push_back(8);
    numPeopleInLine.push_back(10);
    numPeopleInLine.push_back(3);
    numPeopleInLine.push_back(2);


    numItems.push_back(50);
    numItems.push_back(150);
    numItems.push_back(200);
    numItems.push_back(45);
    numItems.push_back(60);

    if (CustomerWantsToChangeLanes(numPeopleInLine, numItems, 2) == 4)
        return true;
    else
        return false;

}

Person randomPersonGenerator()
{
    string firstName[] = { "John", "Ludwig", "Hildegard" , "George", "Antonio", "Claude" };
    string lastName[] = { "Bach" , "Mozart", "Beethoven", "Monteverdi", "Handel", "Vivaldi" };


    // make the song 
    string fullName = firstName[std::rand() / ((RAND_MAX + 1u) / 6)] + " " + lastName[std::rand() / ((RAND_MAX + 1u) / 6)];
    int numItems = rand() / ((RAND_MAX + 1u) / 150);
    Person p(fullName, numItems);


    return p;

}

