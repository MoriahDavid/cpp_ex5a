#include <iostream>
#include <vector>

using namespace std;

namespace ariel{

    
    class Person{
        private:

        public:
            string name;

            vector<Person> person_subs;

            Person(string name){
                this->name = name;
            }
            Person(){
                this->name = "";
            }

            // Add son - p to this person
            void add_sub(Person sub){
                this->person_subs.push_back(sub);
            }
    };

    class OrgChart{

        private:
            Person root;
            Person* find_person(Person* root, string name);

        public:

            class iterator_level_order{
                private:
                public:
                    bool operator==(const iterator_level_order &it) const;
                    bool operator!=(const iterator_level_order &it) const;
                    iterator_level_order& operator++(); //++iterator
                    iterator_level_order& operator++(int); //iterator++
                    string operator*() const;
                    string* operator->() const;
            };

            class iterator_reverse_order{
                private:

                public:
                    bool operator==(const iterator_reverse_order &it) const;
                    bool operator!=(const iterator_reverse_order &it) const;
                    iterator_reverse_order& operator++(); //++iterator
                    iterator_reverse_order& operator++(int); //iterator++
                    string operator*() const;
                    string* operator->() const;

            };

            class iterator_preorder{
                 private:

                public:
                    bool operator==(const iterator_preorder &it) const;
                    bool operator!=(const iterator_preorder &it) const;
                    iterator_preorder& operator++(); //++iterator
                    iterator_preorder& operator++(int); //iterator++
                    string operator*() const;
                    string* operator->() const;

            };

            iterator_level_order begin(); //call begin level order
            iterator_level_order end(); //call begin level order

            iterator_level_order begin_level_order();
            iterator_level_order end_level_order();
            
            iterator_reverse_order begin_reverse_order();
            iterator_reverse_order reverse_order();

            iterator_preorder begin_preorder();
            iterator_preorder end_preorder();

            OrgChart& add_root(string s);
            OrgChart& add_sub(string p, string subp);

            friend ostream& operator<<(ostream& os, const OrgChart& oc); //friend in order to relate to the class
    };

}   