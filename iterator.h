#ifndef ITERATOR_H
#define ITERATOR_H

template<class Array>
class Iterator{
    public:
        using self = Iterator<Array>;
        using value_type = typename Array::value_type;
        using reference = value_type&;
        using const_reference = value_type const&;
        using pointer = value_type*;

        Iterator()
            : address_(nullptr)
            {}
        
        Iterator(pointer address)
            : address_(address)
            {}

        self& operator ++(){
            ++address_;
            return *this;
        }

        self operator ++(int) const{
            self copy = *this;
            ++(*this);
            return copy;
        }

        pointer operator ->(){
            return address_;
        }

        reference operator *(){
            return *address_;
        }

        bool operator ==(const self& other){
            return address_ == other.address_;
        }

        bool operator !=(const self& other){
            return !(*this == other);
        }

    private:
        pointer address_;
};



#endif