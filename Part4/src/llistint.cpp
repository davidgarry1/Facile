#include "../lib/llistint.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

//Copy Constructor (Deep Copy)
LListInt::LListInt(const LListInt& other)
{
      head_ = NULL;
      tail_ = NULL;
      size_ = 0;
      //insert all of other's items
      //this will be deep since insert is deep
      for (int i=0; i<other.size_; i++)
      {
          this->insert(i, other.get(i));
      }
}

//Assigment Operator (Deep Copy)
LListInt& LListInt::operator=(const LListInt& other)
{
    //handle if user sets list to itself
    if(this == &other)
    {
      return *this;
    }
    //delete old contents
    this->clear();
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
    //set new contents
    for (int i=0; i<other.size_; i++)
    {
        //insert all of other's items
        //this will be deep since insert is deep
        this->insert(i, other.get(i));
    }
    //return self
    return *this;
}

//Concatenation Operator (other should be appended to the end of this)
LListInt LListInt::operator+(const LListInt& other) const
{
    //static allocation to avoid memory leaks
    LListInt nuevo;
    for (int i=0; i<this->size_; i++)
    {
        //insert all of this's items
        //this will be deep since insert is deep
        nuevo.insert(i, this->get(i));
    }
    for (int i=this->size_; i<(other.size_ + this->size_); i++)
    {
        //insert all of other's items
        //this will be deep since insert is deep
        nuevo.insert(i, other.get(i- this->size_));
    }
    //return the concatenation
    return nuevo;
}

//Access Operator
int const & LListInt::operator[](int position) const
{
    return this->get(position);
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  //if valid loc
  if(loc <= size_ && loc>=0)
  {
    Item *nuevo = new Item;
    nuevo->val = val;
    nuevo->prev = NULL;
    nuevo->next = NULL;
    if(size_>0)
    {
      if(loc == 0)
      {
        //insert in front
        nuevo->next = head_;
        head_->prev = nuevo;
        head_ = nuevo;
        head_->prev = NULL;
      }
      else
      {
        if(loc == size_)
        {
          //insert in end
          tail_->next = nuevo;
          nuevo->prev = tail_;
          tail_=nuevo;
          tail_->next = NULL;
        }
        else
        {
          //insert in middle
          Item *temp = getNodeAt(loc);
          nuevo->prev = temp->prev;
          temp->prev->next = nuevo;
          temp->prev = nuevo;
          nuevo->next = temp;
        }
      }
    }
    else
    {
      //insert lone node
      head_=nuevo;
      tail_=nuevo;
    }
    size_++;
  }
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
  //if valid loc
  if(!(loc >= size_ || loc <0))
  {
    if(size_ != 1)
    {
      if(loc == 0)
      {
        //remove from front
        head_=head_->next;
        delete head_->prev;
        head_->prev = NULL;
      }
      else
      {
        if(loc == size_-1)
        {
          //remove from end
          tail_=tail_->prev;
          delete tail_->next;
          tail_->next = NULL;
        }
        else
        {
          //remove from middle
          Item *temp = getNodeAt(loc);
          temp->prev->next = temp->next;
          temp->next->prev = temp->prev;
          delete temp;
        }
      }
    }
    else
    {
      //remove only node
      delete head_;
      head_ = NULL;
      tail_ = NULL;
    }
    size_--;
  }
}

/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
    if(loc != size_-1)
    {
        Item *temp = head_;
        //iterate through nodes for (loc)th node
        for(int q=0; q<loc; q++)
        {
          temp = temp->next;
        }
        return temp;
    }
    else
    {
      return tail_;
    }
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}