//Antoine Innocent BA2 Informatique
//Matricule: 000394700

#ifndef _LIST_HPP
#define _LIST_HPP

#include <cstddef>   // NULL, ptrdiff_t, size_t
#include <stdexcept> // exception types
#include <algorithm>
#include <iostream> 

template <typename T>
class List {
public:
  class Place;
  class const_Place;
private:
  struct _Item {
    T      info;
    _Item* next;
    _Item () {}
    _Item (const T& x, _Item* s): info(x), next(s) {}
  };
  _Item*  _first;   // Pointer to first item
  _Item** _last;    // Pointer to next field of last item
  std::size_t _size;
  template <typename X> static void swap (X& a, X& b)
    {const X tmp = a; a = b; b = tmp;}
public:
  // Getters
  Place begin () {return Place(this, &_first);}
  Place end ()   {return Place(this, _last);}
  
  std::size_t size ()  const {return _size;}
  bool empty () const  {return _size == 0;}
  // Constructors
  List (): _first(nullptr), _last(&_first), _size(0) {}
  List (const T& t): _first(nullptr), _last(&_first), _size(0)
    {insert(end(), t);}
  List (const List& L): _first(nullptr), _last(&_first), _size(0)
    {insert(end(), L.begin(), L.end());}
  List (List&& L): _first(L._first), _last(L._size ? L._last : &_first),
                   _size(L._size)
    {L._first = nullptr; L._last= &L._first; L._size = 0;}
  List& operator= (const List& L) {
    if (this != &L) {clear(); insert(end(), L.begin(), L.end());}
    return *this;
  }
  List& operator= (List&& L) {
    if (this != &L) {
      clear();
      _first = L._first; L._first = nullptr;
      _last  = L._size ? L._last : &_first; L._last = &L._first;
      _size  = L._size; L._size = 0;
    }
    return *this;
  }
  ~List () {clear();}
  // Updates
  virtual Place insert (const T& );
  virtual Place erase (const T&) ;
  virtual void search(const T&);

  void clear ();

};

// Methods

template <typename T>
typename List<T>::Place List<T>::insert (const T& t) {
  // Insert "at p", i.e. before p (connect to *_current)

  typename List<T>::Place p1;
  p1= this->begin();
 

  if (this->_size!=0){
      while (*p1<=t ){
          
          ++p1;
          
         if (*p1._current==nullptr){
             break;
         }};}
  
  
  *p1._current = new _Item(t, *p1._current);
  ++_size;
  if (p1._current == _last) _last = &(*p1._current)->next;
  

  return p1;
  }






template <typename T>
typename List<T>::Place List<T>::erase (const T& t) {
  // Erase "at p", i.e. **_current
  typename List<T>::Place p1;
  p1= this->begin();
  
  if (_size!=0){
      while (*p1!=t){   //searching element for deleting
          ++p1;
          if (*p1._current==nullptr){
             throw std::invalid_argument("List::erase: invalid iterator"); }}
    _Item* q = *p1._current;
    *p1._current = (*p1._current)->next;
    delete q;
    if (!*p1._current) _last = p1._current;
    --_size;
  
  return p1;
  }}


template <typename T>
void List<T>::search(const T& t){
    //Search t in linked list
    //Prints success message if found
    typename List<T>::Place p1;
    p1= this->begin();

    if (_size!=0){
        while (*p1!=t){
            ++p1;
            if (*p1._current==nullptr){
               throw std::invalid_argument("List::find: word not in list"); }}
        std::cout<<"Word is in list"<<std::endl;
      
      
    
    }
    else{
        throw std::invalid_argument("List::find: Empty list");
        
    }
}






template <typename T>
void print (List<T>& L) {
    for(typename List<T>::Place p = L.begin(); p != L.end(); ++p){
        std::cout << *p << std::endl;
    }
}




template <typename T>
void List<T>::clear () {
  while (_first) {
    _Item* q = _first;
    _first = _first->next;
    delete q;
  }
  _last = &_first;
  _size = 0;
}

// Iterators
template <typename T>
class List<T>::Place {
  friend class List;
  friend class const_Place;
  List*   _list;
  _Item** _current;
  Place (List* L, _Item** p): _list(L), _current(p) {}
public:
  Place (): _list(nullptr), _current(nullptr) {}          // Singular value
  inline T& operator* () const;
  inline T* operator-> () const;
  inline Place& operator++ ();
  inline Place operator++ (int);              // Postfix
  inline friend bool operator== (const Place& p1, const Place& p2)
    {return p1._current == p2._current;}
  inline friend bool operator!= (const Place& p1, const Place& p2)
    {return p1._current != p2._current;}
};

template <typename T>
class List<T>::const_Place {
  friend class List;
  const List*        _list;
  const _Item*const* _current;
  const_Place (const List* L, const _Item*const* p): _list(L), _current(p) {}
public:
  const_Place (): _list(nullptr), _current(nullptr) {}    // Singular value
  const_Place (const Place& p): _list(p._list), _current(p._current) {} // conv
  inline const T& operator* () const;
  inline const T* operator-> () const;
  inline const_Place& operator++ ();
  inline const_Place operator++ (int);       // Postfix
  inline friend bool operator== (const const_Place& p1, const const_Place& p2)
    {return p1._current == p2._current;}
  inline friend bool operator!= (const const_Place& p1, const const_Place& p2)
    {return p1._current != p2._current;}
};

// Iterators methods
template <typename T>
inline T& List<T>::Place::operator* () const {
  if (! _current)
    throw std::invalid_argument("List::Place::operator*: singular value");
  if (! *_current)
    throw std::invalid_argument("List::Place::operator*: end() value");
  return (*_current)->info;
}

template <typename T>
inline T* List<T>::Place::operator-> () const {
  if (! _current)
    throw std::invalid_argument("List::Place::operator->: singular value");
  if (! *_current)
    throw std::invalid_argument("List::Place::operator->: end() value");
  return &(*_current)->info;
}

template <typename T>
inline typename List<T>::Place& List<T>::Place::operator++ () {
  if (! _current)
    throw std::invalid_argument("List::Place::operator++: singular value");
  if (! *_current)
    throw std::invalid_argument("List::Place::operator++: end() value");
  _current = &(*_current)->next;
  return *this;
}

template <typename T>
inline typename List<T>::Place List<T>::Place::operator++ (int) {
  if (! _current)
    throw std::invalid_argument("List::Place::operator++: singular value");
  if (! *_current)
    throw std::invalid_argument("List::Place::operator++: end() value");
  Place p(*this);
  _current = &(*_current)->next;
  return p;
}

template <typename T>
inline const T& List<T>::const_Place::operator* () const {
  if (! _current)
    throw std::invalid_argument("List::const_Place::operator*: singular value");
  if (! *_current)
    throw std::invalid_argument("List::const_Place::operator*: end() value");
  return (*_current)->info;
}

template <typename T>
inline const T* List<T>::const_Place::operator-> () const {
  if (! _current)
    throw std::invalid_argument("List::const_Place::operator->: singular value");
  if (! *_current)
    throw std::invalid_argument("List::const_Place::operator->: end() value");
  return &(*_current)->info;
}

template <typename T>
inline typename List<T>::const_Place& List<T>::const_Place::operator++ () {
  if (! _current)
    throw std::invalid_argument("List::const_Place::operator++: singular value");
  if (! *_current)
    throw std::invalid_argument("List::const_Place::operator++: end() value");
  _current = &(*_current)->next;
  return *this;
}

template <typename T>
inline typename List<T>::const_Place List<T>::const_Place::operator++ (int) {
  if (! _current)
    throw std::invalid_argument("List::const_Place::operator++: singular value");
  if (! *_current)
    throw std::invalid_argument("List::const_Place::operator++: end() value");
  const_Place p(*this);
  _current = &(*_current)->next;
  return p;
}



template <typename T>
bool operator== (const List<T>& L1, const List<T>& L2) {
  bool OK = L1.size() == L2.size();
  for (typename List<T>::const_Place p1 = L1.begin(), p2 = L2.begin();
      OK && p1 != L1.end(); ++p1, ++p2)
    OK = *p1 == *p2;
  return OK;
}

template <typename T>
bool operator< (const List<T>& L1, const List<T>& L2) {
  // ordre lexicographique strict, valide si T admet l'op�rateur <
  typename List<T>::const_Place p1, p2;
  for (p1 = L1.begin(), p2 = L2.begin();
      p1 != L1.end() && p2 != L2.end(); ++p1, ++p2) { // tant que *p1 == *p2
    if (*p1 < *p2) return true;
    if (*p2 < *p1) return false;
  }
  return p1 == L1.end() && p2 != L2.end(); // cas o? L1 est pr�fixe de L2
}

template <typename T>
inline bool operator!= (const List<T>& L1, const List<T>& L2)
  {return !(L1 == L2);}

template <typename T>
inline bool operator> (const List<T>& L1, const List<T>& L2)
  {return L2 < L1;}

template <typename T>
inline bool operator<= (const List<T>& L1, const List<T>& L2)
  {return !(L2 < L1);}

template <typename T>
inline bool operator>= (const List<T>& L1, const List<T>& L2)
  {return !(L1 < L2);}

#endif  /* _LIST_HPP */
