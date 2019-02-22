// an auto pointer to use with arrays
// lets use arrays in create temp and swap idiom
template 
class auto_array
{
public :
auto_array(T *t) : ptr_( t )
{ }

~auto_array()
{ delete[] ptr_; }

T *operator->()
{ return ptr_; }

T *release()
{ 
T *tmp( ptr_ );
ptr_ = 0;
return tmp;
}

T &operator[](int i)
{ return ptr_[i]; }

private :
T *ptr_;
};
