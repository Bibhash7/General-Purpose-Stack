using namespace std;
template <class T>
class Stack{
	T* data;
	int sz;
private:
	T operator[](T i){
		if(i>sz){
			cout << "Index out of bounds: returning ";
			return NULL;
		}
		if(i < 0){
			cout << "Enter Index >= 0: returning ";
			return NULL;
		}
		return data[i];

	}
public:
	//Constructors
	Stack(){
		data = NULL;
		sz = 0;
	}
	Stack(T a[], int n){
		data = new T[n];
		for(int i = 0; i < n; ++i){
			data[i] = a[i];
		}
		sz = n;
	}
	//Destructor
	~Stack(){
    	delete[] data;
	}
	
	//Overloaded Left Shift for visualization
	friend ostream &operator<<( ostream &output, Stack<T> &s) { 
         for(int i = s.size()-1; i >=0; --i){
         	cout << "[ ";
         	cout << s[i];
         	cout << " ]";
         	cout << '\n'; 
         }
         return output;            
      }
	void push(T item); //Push Item
	void pop();	   //Pop Item
	T top();	   //Top element
	T bottom();	   //Bottom element
	void reverse();    //Reverse the Stack
	int size();        //Size of the Stack
	bool empty();	   //Checks if the Stack is Empty or not

};

template<class T>
void Stack<T>::push(T item){
	T *tmp = new T[sz+1];
	for(int i = 0; i < sz; ++i){
		tmp[i] = data[i];
	}
	tmp[sz] = item;
	if(data != NULL){
		delete[] data;
	}

	data = tmp;
	sz++;

}

template <class T>
void Stack<T>::pop(){
	if(sz > 0){
	T *tmp = new T[sz-1];
	for(int i = 0; i < sz-1; ++i){
		tmp[i] = data[i];
	}
	if(data != NULL){
		delete[] data;
	}

	data = tmp;
	sz--;
	}

}

template <class T>
void Stack<T>::reverse(){
	T *tmp = new T[sz];
	for(int i = 0; i < sz; ++i){
		tmp[i] = data[sz -i-1];
	}
	if(data != NULL){
		delete[] data;
	}

	data = tmp;

}

template <class T>
T Stack<T>::top(){
	//cout << sz;
	if(sz <= 0){
		cout << "Stack is Empty: returning ";
		return NULL;
	}
	return data[sz-1];
	

}

template <class T>
T Stack<T>::bottom(){
	if(sz <= 0){
		cout << "Stack is Empty: returning ";
		return NULL;
	}
	return data[0];
	

}

template <class T>
bool Stack<T>::empty(){
	return (sz<=0);
}

template<class T> 
int Stack<T>:: size(){
	return sz;
}
