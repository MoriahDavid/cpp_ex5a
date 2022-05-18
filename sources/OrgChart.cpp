#include <iostream>
#include <vector>

#include "OrgChart.hpp"
// #include "iterator_level_order.hpp"

using namespace std;

namespace ariel{

    //inner class- iterator_level_order

    bool OrgChart::iterator_level_order::operator==(const iterator_level_order &it) const{
        return false;
    }

    bool OrgChart::iterator_level_order::operator!=(const iterator_level_order &it) const{
        return false;
    }

    OrgChart::iterator_level_order& OrgChart::iterator_level_order::operator++(){ //++iterator
        return *this;
    }

    OrgChart::iterator_level_order& OrgChart::iterator_level_order::operator++(int){ //iterator++
        return *this;
    }

    string OrgChart::iterator_level_order::operator*() const{
        return "";
    }

    string* OrgChart::iterator_level_order::operator->() const{
        return NULL;
    }



    bool OrgChart::iterator_reverse_order::operator==(const iterator_reverse_order &it) const{
        return false;
    }

    bool OrgChart::iterator_reverse_order::operator!=(const iterator_reverse_order &it) const{
        return false;
    }

    OrgChart::iterator_reverse_order& OrgChart::iterator_reverse_order::operator++(){ //++iterator
        return *this;
    }

    OrgChart::iterator_reverse_order& OrgChart::iterator_reverse_order::operator++(int){ //iterator++
        return *this;
    }

    string OrgChart::iterator_reverse_order::operator*() const{
        return "";
    }

    string* OrgChart::iterator_reverse_order::operator->() const{
        return NULL;
    }



    bool OrgChart::iterator_preorder::operator==(const iterator_preorder &it) const{
        return false;
    }

    bool OrgChart::iterator_preorder::operator!=(const iterator_preorder &it) const{
        return false;
    }

    OrgChart::iterator_preorder& OrgChart::iterator_preorder::operator++(){ //++iterator
        return *this;
    }

    OrgChart::iterator_preorder& OrgChart::iterator_preorder::operator++(int){ //iterator++
        return *this;
    }

    string OrgChart::iterator_preorder::operator*() const{
        return "";
    }

    string* OrgChart::iterator_preorder::operator->() const{
        return NULL;
    }



    OrgChart::iterator_level_order OrgChart::begin(){
        return iterator_level_order{};
    }

    OrgChart::iterator_level_order OrgChart::end(){
        return iterator_level_order{};
    }

    OrgChart::iterator_level_order OrgChart::begin_level_order(){
        return iterator_level_order{};
    }

    OrgChart::iterator_level_order OrgChart::end_level_order(){
        return iterator_level_order{};
    }
    
    OrgChart::iterator_reverse_order OrgChart::begin_reverse_order(){
        return iterator_reverse_order{};
    }

    OrgChart::iterator_reverse_order OrgChart::reverse_order(){
        return iterator_reverse_order{};
    }

    OrgChart::iterator_preorder OrgChart::begin_preorder(){
        return iterator_preorder{};
    }

    OrgChart::iterator_preorder OrgChart::end_preorder(){
        return iterator_preorder{};
    }

    OrgChart& OrgChart::add_root(string s){
        // if(&this->root == nullptr){
        //     this->root = Person(s);
        // }
        // else{
            this->root.name = s;
        // }
        return *this;
    }

    OrgChart& OrgChart::add_sub(string p, string subp){
        Person* father = find_person(&this->root, p);
        if(father == nullptr){
            throw("Person(father) dont found");
        }
        else{
            father->add_sub(Person(subp));
            return *this;
        }
    }

    Person* OrgChart::find_person(Person* root, string name){

        if(root->name == name){
            return root;
        }
        for(size_t i = 0; i < root->person_subs.size(); i++){
            Person* result = find_person(&root->person_subs[i], name);
            if(result != nullptr){
                return result;
            }
        }
        return nullptr;
    }
   
    ostream& operator<<(ostream& os, const OrgChart& oc){
        
        return os;
    }


}