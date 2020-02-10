#pragma once
#include <vector>

template <int M, int N, typename T>
class Matrice {
 private:
    std::vector<std::vector<T>> mat;

 public:
    Matrice() {
        this->mat = std::vector<std::vector<T>>(M);
        for (auto m = mat.begin(); m != mat.end(); m++)
            *m = std::vector<T>(N);
    }

    std::vector<T> &operator [] (int index){
        return mat[index];
    }

    class iterator {
     public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = std::remove_cv_t <T>;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

     private:
        pointer ptr;

     public:
        bool operator == (const iterator &it) {
            return this->ptr == it.ptr;
        }
        bool operator != (const iterator &it) {
            return !(this->ptr == it.ptr);
        }

        iterator operator ++(int) {
            iterator i = *this;
            ptr++;
            return i;
        }
        iterator &operator ++() {
            ptr++;
            return *this;
        }
        reference operator * () const {
            return *(this->ptr);
        }
    };

    iterator begin() noexcept {
        return iterator(mat);
    }
    iterator end() noexcept {
        return iterator(mat+N*M);
    }
};
