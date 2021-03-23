#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T>
class Container {
public:        
   virtual int size() const = 0;
   virtual bool isEmpty() const = 0;    
};

#endif
